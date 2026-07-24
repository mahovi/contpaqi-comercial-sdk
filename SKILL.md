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

Fuentes usadas para armar esto (de un lote de 11 archivos del proveedor --
el resto resultaron ser de otros productos CONTPAQi, ver abajo):
- El manual oficial "Manual SDK Sistemas Comerciales.pdf" (incompleto, ver
  gotchas abajo -- no confiar ciegamente en sus ejemplos).
- **`MGW_SDK.h`** (en este mismo directorio) -- el header C original del
  DLL, mucho más completo que el manual: todas las constantes de nombre de
  campo, el catálogo completo de funciones, y las estructuras de datos para
  las funciones "Alto Nivel" (antes evitadas por no tener esto). Es de una
  revisión anterior a la instalación validada (no incluye
  `fInicioSesionSDK`, que sí existe y funciona en la versión real usada) --
  tratarlo como catálogo casi completo, no como límite exacto.
- La librería open-source
  [ARSoftware.Contpaqi.Comercial](https://github.com/AndresRamos/ARSoftware.Contpaqi.Comercial)
  (ahí se encontró `fInicioSesionSDK`, ausente de `MGW_SDK.h`).
- Verificación directa contra SQL Server (la base de datos real detrás de
  Comercial) para confirmar nombres de tabla/columna.
- `reference.md` en este mismo directorio tiene las declaraciones P/Invoke
  ya usadas y funcionando, el catálogo completo por categoría, y las
  estructuras traducidas a C# para las funciones "Alto Nivel".

**Otros 9 archivos del mismo lote del proveedor son de productos distintos**
(DLLs y APIs diferentes -- la mayoría no aplica a Comercial): 3 de
**CONTPAQi Bancos**, 2 de **CONTPAQi Contabilidad**, 1 overview genérico
multi-producto, y 1 guía de "Examinador de Objetos" específica para los
SDKs de Bancos/Contabilidad (basados en COM, no aplica al acceso directo
por P/Invoke que usa esta skill) -- esos 6 sí son ruido para Comercial. El
de **AdminPAQ** (`Funciones SDK-ADMW.PDF`) es la excepción: aunque es de
otro producto, documenta funciones de licenciamiento (`fInicializaLicenseInfo`,
`fObtieneLicencia`) declaradas en el mismo header compartido -- **sí vale
la pena revisarlo** para cualquier función que aparezca en `MGW_SDK.h` sin
documentación en el manual de Comercial, ya que puede estar documentada
ahí en su lugar (aprendido después de descartarlo una vez sin razón
suficiente).

Si en el futuro se integra con Bancos, Contabilidad o AdminPAQ, esos
manuales existen y valdría la pena revisarlos a fondo -- para Comercial,
salvo la excepción de licenciamiento ya señalada, son ruido.

**Los 11 archivos se leyeron completos, no solo por título/muestreo**
(2026-07-24, a petición explícita después de que quedara claro que
descartar documentos por su título había hecho perder información real
más de una vez). Confirmado con lectura real, no solo grep:
- Los 5 de Bancos/Contabilidad y el overview general usan una arquitectura
  **distinta** por completo: SDK COM (`TSdkSesion`, `SDKCONTPAQNGLib.dll`,
  métodos como `.firmaUsuario()`/`.abreEmpresa()`), no las funciones
  planas de `MGWServicios.dll` que usa Comercial -- confirma que
  genuinamente no aplican, no es solo una suposición por el título.
- El manual de AdminPAQ sí comparte arquitectura con Comercial (mismo
  header `MGW_SDK.h`) y de ahí salió el hallazgo de `fAfectaDocto_Param`
  (ver más abajo) -- justo el tipo de cosa que se habría perdido si no se
  hubiera insistido en revisarlo a fondo.
- Dato menor: uno de los ejemplos de Bancos usa
  `firmaUsuarioParams("SUPERVISOR", "")` como usuario de ejemplo -- refuerza
  que `SUPERVISOR` sin contraseña es una convención/cuenta de ejemplo
  estándar de CONTPAQi en toda su documentación, no algo específico de una
  instalación en particular.

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

## Dos niveles por entidad: "Alto Nivel" y "Bajo Nivel"

El SDK expone dos niveles por cada entidad (Cliente/Proveedor, Producto,
Documento, Movimiento, Dirección):

- **Alto Nivel** (`fAltaCteProv`, `fAltaDocumento`, `fAltaProducto`, etc.):
  una sola llamada con una estructura de datos (`ClienteProveedor`,
  `RegDocumento`, `Producto`, etc.) que ya viene completa. **Ahora sí
  usable** -- `MGW_SDK.h` define el layout exacto de cada struct
  (`reference.md` trae la traducción a C#/`StructLayout` para las más
  usadas). Antes se recomendaba evitarlas por no tener esta información.
- **Bajo Nivel**: mismo patrón repetido para cada entidad, campo por campo
  -- más verboso pero más fácil de debuggear paso a paso (se ve
  exactamente qué campo falla). Preferir esto para diagnóstico o cuando
  falte la definición exacta de algún struct nuevo:

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

  Los nombres de `campo` son las constantes que trae `MGW_SDK.h`
  ("Constantes de nombres de campos", ej. `cCodigoConcepto`,
  `cCodigoCteProv`, `cCodigoProducto`, `cUnidades` -- tabla completa en
  `reference.md`). **Ojo**: estos nombres NO siempre coinciden con las
  columnas de las tablas SQL Server subyacentes (`admClientes`,
  `admProductos`, `admDocumentos`, `admMovimientos`) -- antes de este
  header se asumió (incorrectamente) que sí coincidían, usando nombres
  como `CIDCONCEPTODOCUMENTO`/`CIDCLIENTEPROVEEDOR` en vez de los reales
  `cCodigoConcepto`/`cCodigoCteProv`. Verificar siempre contra `MGW_SDK.h`,
  no contra el esquema SQL.

  Para leer los movimientos (líneas) de un documento ya encontrado:
  ```
  fSetFiltroMovimiento(idDocumento)
  fPosPrimerMovimiento() / fPosSiguienteMovimiento()   -- iterar hasta que regrese error != 0
  fLeeDatoMovimiento(campo, valor, len)                -- por cada uno
  fCancelaFiltroMovimiento()                            -- al terminar
  ```

## Gotcha #2: "afectar" el documento después de crearlo (`fAfectaDocto_Param`)

Crear un documento (`fEditarDocumento`+`fSetDatoDocumento`+`fGuardaDocumento`)
y sus movimientos (`fEditarMovimiento`+`fSetDatoMovimiento`+`fGuardaMovimiento`)
**no es suficiente** -- la existencia y los costos se actualizan, pero los
**acumulados del sistema no**, hasta que el documento se "afecta"
explícitamente:

```csharp
[DllImport("MGWSERVICIOS.DLL")]
public static extern int fAfectaDocto_Param(string aCodConcepto, string aSerie, double aFolio, bool aAfecta);

// después de guardar documento + movimientos:
Sdk.fAfectaDocto_Param(codigoConcepto, serie, folio, true);
```

Esto **no está documentado bajo su propio encabezado en el manual de
Comercial** -- el manual solo menciona de pasada, en la introducción de
"Trabajando con Documentos", que "existen dos tipos de afectación, una
para los documentos de cargo y abono y otra para los demás tipos de
documento", sin nunca explicar cómo hacerlo. Se encontró:
- La función `fAfectaDocto`/`fAfectaDocto_Param` **sí está declarada** en
  el header de Comercial (`MGW_SDK.h`), bajo la categoría "CheqPAQ" del
  catálogo -- fácil de pasar por alto pensando que es específica de esa
  integración.
- El manual de **AdminPAQ** (misma familia de SDK, mismo patrón de
  funciones) sí documenta el flujo completo: `fInicializaSDK → fAbreEmpresa
  → Alta de documento → Alta de movimientos → Afectar documento →
  fCierraEmpresa → fTerminaSDK` -- el paso de "afectar" es obligatorio en
  el diagrama de flujo oficial, no opcional.
- El folio real del documento hay que leerlo con `fLeeDatoDocumento("cFolio",
  ...)` después de `fGuardaDocumento` -- no asumir que se conoce de
  antemano, el SDK lo autoasigna.

Todavía no se ha podido probar esto en vivo (bloqueado por el problema de
licenciamiento del SDK, ver más abajo) -- queda como el paso a verificar en
cuanto ese bloqueo se resuelva.

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
  puntos de arriba): esto ya no se resuelve solo con cambios de código de
  integración. Se investigó la pista de `fObtieneLicencia`/
  `fInicializaLicenseInfo` (documentadas solo en el manual de **AdminPAQ**,
  "Funciones SDK-ADMW.PDF" -- no en el de Comercial, pero declaradas en el
  mismo `MGW_SDK.h` compartido) -- **verificado con `GetProcAddress`
  directo sobre la DLL real** (no solo probando y viendo el error, para no
  repetir el error de descartar algo sin comprobarlo a fondo):
  - `fInicializaLicenseInfo` **sí existe** en `MGWSERVICIOS.DLL` de
    Comercial y, probada con `aSistema=0` (código documentado solo para
    AdminPAQ, sin código conocido para Comercial), **regresó éxito (0)** --
    es decir, la conexión al servidor de licencias en sí funciona a nivel
    básico.
  - `fObtieneLicencia` **NO existe** como export en `MGWSERVICIOS.DLL` de
    Comercial (confirmado, no solo con `DllImport` -- también con
    `GetProcAddress` manual sobre el archivo, que es la prueba definitiva).
    Tampoco existe en `RuntimeAPI.dll` (el candidato más cercano al
    "Runtime.dll" del header). Es una función exclusiva de AdminPAQ en esta
    instalación -- descartada para Comercial.
  - Conclusión de esta pista: el mecanismo de licencia SÍ es alcanzable y
    responde, pero no hay forma (encontrada hasta ahora) de consultar el
    detalle de la licencia específicamente para el módulo SDK de Comercial
    desde código. **Escalar a soporte técnico de CONTPAQi directamente**
    (no solo al proveedor de TI/infraestructura local -- puede que ni
    ellos sepan activarlo), pasándoles el mensaje de error exacto, en qué
    llamada ocurrió, y que `fInicializaLicenseInfo` confirma que el
    servidor de licencias responde.

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

- `reference.md` en este directorio -- declaraciones P/Invoke (C#) ya
  usadas y funcionando, catálogo completo de funciones por categoría,
  structs traducidos para "Alto Nivel", y la tabla de constantes de
  nombres de campo. Punto de partida directo para escribir nuevas
  integraciones sin volver a extraer firmas del manual.
- `MGW_SDK.h` en este directorio -- header C original del proveedor,
  fuente autoritativa para cualquier función/struct/constante que no esté
  ya traducida en `reference.md`.
