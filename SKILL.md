---
name: contpaqi-comercial-sdk
description: Guía autoritativa para integrar código (C#/.NET vía P/Invoke) contra el SDK de CONTPAQi Comercial (MGWServicios.dll) -- secuencia de inicialización correcta, el patrón "Bajo Nivel" para leer/escribir cualquier entidad, y cómo interpretar los mensajes de error reales del SDK. Usar cuando se escriba código nuevo contra este SDK, se debuggee un error de CONTPAQi Comercial, o se necesite decidir qué función usar para una operación (buscar/crear/editar cliente, producto, documento o movimiento).
---

# SDK de CONTPAQi Comercial (MGWServicios.dll)

Esta skill existe porque el manual oficial del proveedor ("Manual SDK
Sistemas Comerciales.pdf", Computación en Acción SA de CV / CONTPAQi) está
**incompleto y tiene inconsistencias** -- varias horas de trabajo real se
fueron en descubrir por prueba y error cosas que el manual no menciona. No
vuelvas a repetir ese trabajo: esto ya está validado contra un servidor
real en producción.

Fuentes usadas para armar esto:
- El manual oficial (incompleto, ver gotchas abajo -- no confiar ciegamente
  en sus ejemplos).
- La librería open-source
  [ARSoftware.Contpaqi.Comercial](https://github.com/AndresRamos/ARSoftware.Contpaqi.Comercial)
  (más completa en varios puntos -- ahí se encontró `fInicioSesionSDK`).
- Verificación directa contra SQL Server (la base de datos real detrás de
  Comercial) para confirmar nombres de tabla/columna.
- `reference.md` en este mismo directorio tiene las declaraciones P/Invoke
  ya usadas y funcionando.

## Secuencia de inicialización (obligatoria, en este orden)

1. **Ubicar el SDK vía registro de Windows**:
   `HKLM\SOFTWARE\Computación en Acción, SA CV\CONTPAQ I COMERCIAL`, valor
   `DirectorioBase`.
   - Esta llave normalmente **no** trae espacio final en el nombre, aunque
     el manual oficial sí lo trae en sus ejemplos de código (ver Gotcha
     más abajo) -- verificar siempre contra el registro real de la máquina
     donde se va a correr, no asumir.
   - **CONTPAQi Comercial es de 32 bits.** En Windows de 64 bits esta
     llave vive en la vista `WOW6432Node`
     (`HKLM\SOFTWARE\WOW6432Node\...`). El ejecutable **debe compilarse
     `/platform:x86`** (nunca `AnyCPU`) -- así Windows redirige la ruta del
     registro automáticamente, y de paso el proceso puede cargar
     `MGWSERVICIOS.DLL` (también de 32 bits). Compilar en `AnyCPU`
     falla en ambos frentes.
2. **`SetCurrentDirectory`** (kernel32) apuntando a `DirectorioBase`, ANTES
   de cualquier llamada al SDK -- si no, el `DllImport` no encuentra la DLL.
3. **`fInicioSesionSDK(usuario, contraseña)`** -- ver Gotcha #1, es el paso
   que el manual oficial NO documenta y que evita el cuelgue.
4. **`fSetNombrePAQ("CONTPAQ I COMERCIAL")`** -- inicializa la conexión al
   sistema.
5. **`fPosPrimerEmpresa(ref idEmpresa, nombre, directorio)`** -- ubica la
   primera empresa configurada.
6. **`fAbreEmpresa(directorio)`** -- abre esa empresa. Ya se puede operar.
7. Al terminar: **`fCierraEmpresa()`** luego **`fTerminaSDK()`**.

## Gotcha #1 (el más importante): `fInicioSesionSDK` antes de `fSetNombrePAQ`

`fSetNombrePAQ()` sin haber llamado antes a `fInicioSesionSDK()` intenta
mostrar una **ventana de login** (usuario/contraseña de la aplicación
Comercial, no de Windows ni de SQL). Si el proceso corre en una sesión sin
escritorio interactivo (por ejemplo, lanzado por WinRM/PowerShell remoto --
Session 0 de Windows), esa ventana nunca puede mostrarse ni cerrarse, y el
proceso **se queda colgado indefinidamente**: vivo, con CPU casi nula, sin
excepción, sin log posterior a ese punto. Se confirmó con `EnumWindows`
(user32.dll) que el proceso no tiene ninguna ventana propia -- no es un
diálogo visible bloqueado, es el mecanismo interno de Windows Error
Reporting/creación de ventana esperando un window station interactivo que
no existe en Session 0.

Si el mismo código corre desde una sesión RDP real (interactiva), el
problema se manifiesta distinto: un `System.Runtime.InteropServices.SEHException`
(excepción nativa no manejada) en vez de un cuelgue. Mismo problema de raíz,
manifestación distinta según el tipo de sesión.

**Solución**: llamar `fInicioSesionSDK(usuario, contraseña)` ANTES de
`fSetNombrePAQ`, con las credenciales de la aplicación Comercial (el login
real que usa la persona que la usa día a día -- pedírselo al cliente/
usuario, no asumir ni usar credenciales de Windows/SQL).

Si un proceso se queda atorado y no responde por este motivo, `Stop-Process
-Force`/`taskkill /F` normalmente lo cierra -- pero en al menos un caso real
dejó el proceso genuinamente sin poder cerrarse ni con `/F` (probablemente
un lock interno del SDK que no se libera limpiamente sin pasar por
`fCierraEmpresa`/`fTerminaSDK`). No pareció afectar el uso interactivo
normal de Comercial en ese caso, pero evita forzar cierres si puedes dejar
que el proceso termine solo o usar un timeout más generoso primero.

## El patrón "Bajo Nivel" (usar esto, no las funciones "Alto Nivel")

El SDK expone dos niveles por cada entidad (Cliente/Proveedor, Producto,
Documento, Movimiento):

- **Alto Nivel** (`fAltaCteProv`, `fAltaDocumento`, etc.): más simple en
  apariencia, pero requiere una estructura de datos abstracta (`tCteProv`,
  etc.) cuyo layout exacto **no** viene documentado en el manual oficial.
  **Evitar** a menos que consigas esa definición de struct de otra fuente.
- **Bajo Nivel**: mismo patrón repetido para cada entidad, totalmente
  documentado con tipos primitivos (cadenas, enteros) -- usar siempre esto:

  **Lectura:**
  ```
  fBusca<Entidad>(codigo)         -- posiciona el cursor
  fLeeDato<Entidad>(campo, valor, len)   -- leer campo por campo
  ```

  **Alta (creación) o edición:**
  ```
  fInserta<Entidad>()  o  fEditar<Entidad>()   -- entra a modo edición/inserción
  fSetDato<Entidad>(campo, valor)              -- una llamada por campo
  fGuarda<Entidad>()                            -- confirma los cambios
  ```

  Para **Documentos** específicamente no existe un `fInserta` separado:
  `fEditarDocumento()` **sin** una búsqueda previa exitosa entra en modo
  inserción de un documento nuevo (mismo patrón para `fEditarMovimiento()`
  con movimientos). Con búsqueda previa exitosa, edita el registro
  encontrado.

  Los nombres de `campo` corresponden a las columnas reales de las tablas
  SQL Server subyacentes (`admClientes`, `admProductos`, `admDocumentos`,
  `admMovimientos`, `admConceptos`, etc.) -- si tienes acceso a la base de
  datos, consulta `INFORMATION_SCHEMA.COLUMNS`/`sys.tables` ahí para
  confirmar nombres exactos en vez de adivinar contra el manual.

  Para leer los movimientos (líneas) de un documento ya encontrado:
  ```
  fSetFiltroMovimiento(idDocumento)
  fPosPrimerMovimiento() / fPosSiguienteMovimiento()   -- iterar hasta que regrese error != 0
  fLeeDatoMovimiento(campo, valor, len)                -- por cada uno
  fCancelaFiltroMovimiento()                            -- al terminar
  ```

## Cómo interpretar mensajes de error reales (no tomarlos literal)

- **`999990: El sistema no está registrado`** (al llamar `fSetNombrePAQ`):
  generalmente indica un problema de licenciamiento/registro del módulo
  SDK para esa instalación específica -- no necesariamente un error de
  escritura en el nombre del sistema (aunque vale la pena verificar: el
  manual oficial trae el ejemplo con un espacio final,
  `"CONTPAQ I COMERCIAL "`, que en la práctica puede no coincidir con el
  nombre real registrado en esa máquina -- confirmar siempre contra el
  registro de Windows).
- **`SEHException`** (excepción nativa no manejada) en `fSetNombrePAQ`:
  consistente con el mismo problema de licenciamiento/registro, manifestado
  como crash en vez de error limpio -- típicamente porque faltó
  `fInicioSesionSDK` antes (ver Gotcha #1) y esto corrió en una sesión
  interactiva (en sesión no interactiva, este mismo problema se manifiesta
  como cuelgue, no como excepción).
- **`No es posible acceder a la base de datos RepositorioAdminPAQ, su
  estado actual es [SELECT INTO/BULKCOPY,TRUNC. LOG ON CHKPT,LOADING,PRE
  RECOVERY,RECOVERING,NOT RECOVERED,OFFLINE,READ ONLY]`**: este es un
  mensaje **genérico oficial de CONTPAQi** (documentado en su propia Carta
  Técnica "Mejoras en la representación del mensaje al ejecutar el
  sistema", Comercial Premium 501) que aparece ante "cualquier
  inconsistencia" -- el listado entre corchetes es una lista de posibles
  estados, no necesariamente el estado real. Antes de asumir que la base
  está mal: conéctate directo por SQL (`sys.databases`, columnas
  `state_desc`/`is_read_only`) y prueba abrir esa base con Integrated
  Security -- si conecta bien y aparece `ONLINE`/no read-only, la base está
  sana y el problema real es el chequeo interno de licencia/registro del
  SDK contra ella, no la base en sí. `RepositorioAdminPAQ` es la base
  donde CONTPAQi guarda su propio registro/licenciamiento interno (sus
  tablas suelen traer prefijo `CAC#####`).
- Cuando el problema aterriza en licenciamiento/registro del SDK (los tres
  puntos de arriba): esto ya no se resuelve desde el código. **Escalar a
  soporte técnico de CONTPAQi directamente** (no solo al proveedor de TI/
  infraestructura local -- puede que ni ellos sepan activarlo), pasándoles
  el mensaje de error exacto y en qué llamada ocurrió.

## Gotchas de despliegue (Windows Server sin Visual Studio)

- Compilar con `csc.exe` de **.NET Framework** (no `dotnet build`/.NET
  Core) -- suele estar en
  `%windir%\Microsoft.NET\Framework64\v4.0.30319\csc.exe` incluso para
  compilar output de 32 bits (usar `/platform:x86` como flag, no cambiar de
  compilador).
- Si se despliega por WinRM: no hay copia de archivos nativa y el tamaño de
  comando tiene límite -- transferir archivos fuente en fragmentos base64
  (ver patrón `upload_file` en `reference.md`), no embebidos completos en
  un solo comando remoto.

## Ver también

`reference.md` en este directorio -- declaraciones P/Invoke (C#) ya usadas
y funcionando para: inicialización, Clientes/Proveedores, Productos,
Documentos, Movimientos, Existencias y Precios. Punto de partida directo
para escribir nuevas integraciones sin volver a extraer firmas del manual.
