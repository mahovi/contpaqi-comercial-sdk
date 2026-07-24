# Referencia P/Invoke -- MGWServicios.dll

`MGW_SDK.h` en este mismo directorio es el **header C original del
proveedor** (extraído de la documentación oficial) -- fuente autoritativa
para cualquier función/struct que no esté ya traducida aquí. Este archivo
(`reference.md`) trae la traducción a C#/P/Invoke ya usada y funcionando,
más las partes más importantes reorganizadas para uso directo.

Nota: `MGW_SDK.h` es una revisión de header más antigua que la instalación
donde se validó todo esto (Comercial v11.5.1) -- por ejemplo no incluye
`fInicioSesionSDK` (ver Gotcha #1 en `SKILL.md`), que sí existe y funciona
en esa versión. Trátalo como catálogo base casi completo, no como límite
exacto de lo que existe en una instalación dada.

## Declaraciones P/Invoke (inicialización + Bajo Nivel más usadas)

```csharp
using System;
using System.Runtime.InteropServices;
using System.Text;

public static class Sdk
{
    // --- Inicialización / Terminación ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetNombrePAQ(string aNombrePAQ);

    // Llamar ANTES de fSetNombrePAQ -- ver SKILL.md Gotcha #1. No está en
    // MGW_SDK.h (header de una revisión anterior) pero existe y funciona.
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fInicioSesionSDK(string aNombreUsuario, string aContrasena);

    [DllImport("MGWSERVICIOS.DLL")]
    public static extern void fTerminaSDK();

    [DllImport("MGWSERVICIOS.DLL")]
    public static extern void fError(int aNumError, StringBuilder aMensaje, int aLen);

    // --- Empresas ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fPosPrimerEmpresa(ref int aIdEmpresa, StringBuilder aNombreEmpresa, StringBuilder aDirectorioEmpresa);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fPosSiguienteEmpresa(ref int aIdEmpresa, StringBuilder aNombreEmpresa, StringBuilder aDirectorioEmpresa);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fAbreEmpresa(string aDirectorioEmpresa);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern void fCierraEmpresa();

    // --- Existencias / Costos / Precios ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaExistencia(string aCodigoProducto, string aCodigoAlmacen,
        string aAnio, string aMes, string aDia, ref double aExistencia);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaPrecioVenta(string aCodigoConcepto, string aCodigoCliente,
        string aCodigoProducto, StringBuilder aPrecioVenta);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaCostoPromedio(string aCodigoProducto, string aCodigoAlmacen,
        string aAnio, string aMes, string aDia, StringBuilder aCostoPromedio);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaUltimoCosto(string aCodigoProducto, string aCodigoAlmacen,
        string aAnio, string aMes, string aDia, StringBuilder aUltimoCosto);

    // --- Clientes/Proveedores (Bajo Nivel) ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaCteProv(string aCodCteProv);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaIdCteProv(int aIdCteProv);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fLeeDatoCteProv(string aCampo, StringBuilder aValor, int aLen);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fInsertaCteProv();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fEditaCteProv();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetDatoCteProv(string aCampo, string aValor);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fGuardaCteProv();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fEliminarCteProv(string aCodigoCteProv);

    // --- Productos (Bajo Nivel) ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaProducto(string aCodProducto);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaIdProducto(int aIdProducto);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fLeeDatoProducto(string aCampo, StringBuilder aValor, int aLen);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fInsertaProducto();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fEditaProducto();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetDatoProducto(string aCampo, string aValor);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fGuardaProducto();

    // --- Documentos (Bajo Nivel) -- fEditarDocumento() sin fBuscaDocumento
    // previo = inserta un registro nuevo (mismo patrón para movimientos) ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscarDocumento(string aCodConcepto, string aSerie, double aFolio);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fLeeDatoDocumento(string aCampo, StringBuilder aValor, int aLen);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fEditarDocumento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetDatoDocumento(string aCampo, string aValor);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fGuardaDocumento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSiguienteFolio(string aCodigoConcepto, StringBuilder aSerie, ref double aFolio);
    // Obligatorio después de guardar documento + movimientos -- ver
    // "Gotcha #2" en SKILL.md. Sin esto, los acumulados del sistema no se
    // actualizan aunque la existencia/costos sí.
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fAfectaDocto_Param(string aCodConcepto, string aSerie, double aFolio, bool aAfecta);

    // --- Movimientos (Bajo Nivel) ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetFiltroMovimiento(int aIdDocumento);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fCancelaFiltroMovimiento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fPosPrimerMovimiento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fPosSiguienteMovimiento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fLeeDatoMovimiento(string aCampo, StringBuilder aValor, int aLen);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fEditarMovimiento();
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetDatoMovimiento(string aCampo, string aValor);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fGuardaMovimiento();

    // El SDK no está en el PATH del sistema -- ubicarlo por el registro y
    // pararse ahí con SetCurrentDirectory ANTES de llamar cualquier función
    // de arriba, si no, DllImport truena con "no se pudo encontrar la DLL".
    [DllImport("KERNEL32", CharSet = CharSet.Auto, SetLastError = true)]
    public static extern bool SetCurrentDirectory(string lpPathName);

    public static string GetErrorMessage(int numError)
    {
        var sb = new StringBuilder(512);
        fError(numError, sb, 512);
        return sb.ToString();
    }
}
```

## Catálogo completo de funciones por categoría (ver `MGW_SDK.h` para firmas exactas en C)

El header oficial cubre muchas más entidades de las que se han usado hasta
ahora. Todas siguen el mismo patrón Bajo Nivel (`fBusca<X>`/`fBuscaId<X>` →
`fLeeDato<X>`, o `fInserta<X>`/`fEdita<X>` → `fSetDato<X>` → `fGuarda<X>`),
más navegación (`fPosPrimer<X>`/`fPosUltimo<X>`/`fPosSiguiente<X>`/
`fPosAnterior<X>`/`fPosBOF<X>`/`fPosEOF<X>`):

- **Documentos** -- `fInsertarDocumento`/`fEditarDocumento`/`fGuardaDocumento`/
  `fBorraDocumento`/`fCancelaDocumento`, `fSetDatoDocumento`/`fLeeDatoDocumento`,
  `fSiguienteFolio`, `fSetFiltroDocumento`, `fBuscarIdDocumento`/
  `fBuscaDocumento`/`fBuscarDocumento`, navegación completa. Alto nivel:
  `fAltaDocumento`, `fAltaDocumentoCargoAbono`.
- **Movimientos** -- `fInsertarMovimiento`/`fEditarMovimiento`/`fGuardaMovimiento`,
  `fSetDatoMovimiento`/`fLeeDatoMovimiento`, `fSetFiltroMovimiento`,
  `fBuscarIdMovimiento`, navegación completa,
  `fAfectaSerie`, `fRecuperaTipoProducto`. Alto nivel: `fAltaMovimiento`,
  `fAltaMovimientoCDesct` (con descuentos), `fAltaMovimientoCaracteristicas`,
  `fAltaMovtoCaracteristicasUnidades`, `fAltaMovimientoSeriesCapas` (y sus
  variantes `_Param` que reciben todo como cadenas en vez de structs).
- **Clientes/Proveedores** -- `fBuscaIdCteProv`/`fBuscaCteProv`,
  `fInsertaCteProv`/`fEditaCteProv`/`fGuardaCteProv`/`fBorraCteProv`/
  `fEliminarCteProv`, `fSetDatoCteProv`/`fLeeDatoCteProv`, navegación
  completa, `fInformacionCliente` (crédito/saldo). Alto nivel:
  `fAltaCteProv`, `fActualizaCteProv`, `fLlenaRegistroCteProv`.
- **Productos** -- `fBuscaIdProducto`/`fBuscaProducto`,
  `fInsertaProducto`/`fEditaProducto`/`fGuardaProducto`/`fBorraProducto`/
  `fEliminarProducto`, `fSetDatoProducto`/`fLeeDatoProducto`/
  `fSetDescripcionProducto`, navegación completa. Alto nivel: `fAltaProducto`,
  `fActualizaProducto`, `fLlenaRegistroProducto`.
- **Direcciones** -- `fBuscaDireccionEmpresa`/`fBuscaDireccionCteProv`/
  `fBuscaDireccionDocumento`, `fInsertaDireccion`/`fEditaDireccion`/
  `fGuardaDireccion`, `fSetDatoDireccion`/`fLeeDatoDireccion`, navegación
  completa. Alto nivel: `fAltaDireccion`, `fActualizaDireccion`,
  `fLlenaRegistroDireccion`.
- **Existencias/Costos** -- `fRegresaExistencia`,
  `fRegresaExistenciaCaracteristicas`, `fRegresaCostoPromedio`,
  `fRegresaUltimoCosto`, `fRegresaCostoEstandar`, `fRegresaCostoCapa`,
  `fRecosteoProducto`, `fRegresaPrecioVenta`.
- **Concepto de Documento** -- `fBuscaIdConceptoDocto`/`fBuscaConceptoDocto`,
  `fLeeDatoConceptoDocto`/`fSetDatoConceptoDocto`, `fRegresPorcentajeImpuesto`,
  navegación completa.
- **Catálogos auxiliares** (mismo patrón Bajo Nivel cada uno): Agentes,
  Almacenes, Unidades de Peso y Medida, Clasificaciones, Valores de
  Clasificación, Movimientos Contables, Parámetros.
- **Direcciones/CFDI** -- `fEmitirDocumento`, `fEntregEnDiscoXML`,
  `fDocumentoUUID`, `fGetTamSelloDigitalYCadena`/`fGetSelloDigitalYCadena`,
  `fTimbraXML`/`fTimbraNominaXML`/`fTimbraComplementoXML`/
  `fTimbraComplementoPagoXML`, `fCancelaUUID`/`fCancelaUUID33`,
  `fEliminarRelacionesCFDIs`/`fAgregarRelacionCFDI`/`fAgregarRelacionCFDI2`/
  `fRecuperarRelacionesCFDIs`.
- **CheqPAQ (ajustes de IVA/IESPS, saldar documentos)** --
  `fAltaDoctoAjusteIVAClienteProveedor`, `fAltaDoctoAjusteIESPSCteProv`,
  `fSaldarDocumento`/`fSaldarDocumento_Param`, `fBorrarAsociacion`/
  `fBorrarAsociacion_Param`.

## Licenciamiento -- investigado y verificado con GetProcAddress

El header expone funciones para licenciamiento (documentadas en el manual
de **AdminPAQ**, no en el de Comercial, pero declaradas en el mismo header
compartido), más un mecanismo separado vía una DLL `Runtime.dll`:

```c
extern "C" STDEXPIMP int  PASCAL fInicializaLicenseInfo(int aSistema);
extern "C" STDEXPIMP int PASCAL fObtieneLicencia(char *aCodAcvtiva, char *aCodSitio, char *aSerie, char *aTagVersion);
extern "C" STDEXPIMP int PASCAL fObtienePassProxy(char *aPassProxy);

// Apuntadores a funciones de Runtime.dll (info de licencia)
typedef int (__stdcall *ptr_RTInit)(char* aProductName, __int64 aVersionTag);
typedef int (__stdcall *ptr_RTDone)();
typedef int (__stdcall *ptr_RTQuery)(char* aBuf);
typedef int (__stdcall *ptr_RTQueryLicenseInfo)(bool* aIsEvaluation, bool* aIsTemporary, UINT* aMaxUsers,
                                      UINT* aMaxDays, UINT* aMaxRuns, UINT* aMaxUsageHours,
                                      UINT* aMaxToken1, UINT* aMaxToken2,
                                      int* aExtra1, int* aExtra2);
```

**Verificado en producción con `GetProcAddress` directo sobre el archivo
(no solo probando y viendo el error -- prueba definitiva de qué exporta
cada DLL):**

- `fInicializaLicenseInfo` **sí existe** en `MGWSERVICIOS.DLL` de Comercial.
  Probada con `aSistema=0` (código documentado solo para AdminPAQ, sin
  código conocido para Comercial) -- regresó `0` (éxito): la conexión al
  servidor de licencias funciona a nivel básico.
- `fObtieneLicencia` **NO existe** en `MGWSERVICIOS.DLL` de Comercial, ni
  en `RuntimeAPI.dll` (el candidato más cercano al `Runtime.dll` del
  header -- los nombres de DLL de CONTPAQi cambian entre versiones).
  Exclusiva de AdminPAQ en esta instalación.

Patrón para verificar exports de una DLL sin herramientas de Visual Studio
(útil para cualquier función dudosa en el futuro -- ejecutar con
PowerShell de **32 bits**, `%windir%\SysWOW64\WindowsPowerShell\v1.0\powershell.exe`,
ya que el DLL es de 32 bits):

```powershell
Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public class T {
    [DllImport("kernel32.dll", SetLastError=true)] public static extern bool SetCurrentDirectory(string p);
    [DllImport("kernel32.dll", SetLastError=true)] public static extern IntPtr LoadLibrary(string dllPath);
    [DllImport("kernel32.dll", SetLastError=true)] public static extern IntPtr GetProcAddress(IntPtr hModule, string procName);
}
"@
$dir = "C:\Program Files (x86)\Compac\COMERCIAL"
[T]::SetCurrentDirectory($dir) | Out-Null   # necesario para resolver dependencias del DLL
$h = [T]::LoadLibrary("$dir\MGWServicios.dll")
$addr = [T]::GetProcAddress($h, "NombreDeFuncion")
# $addr -eq [IntPtr]::Zero  ->  NO existe ese export en esta DLL
```

Si te encuentras con errores de "sistema no registrado" o mensajes
genéricos de acceso a `RepositorioAdminPAQ` (ver SKILL.md), **esto es un
punto de partida concreto para investigar** -- `fObtieneLicencia` en
particular (parámetros: código de activación, código de sitio, serie,
versión) suena directamente relacionado con activar/consultar el registro
de una instalación. No se ha probado en producción todavía; queda como
pista para la próxima sesión de debugging, no como solución confirmada.

## Structs para funciones "Alto Nivel" (ya traducidos a C#)

Antes se recomendaba evitar las funciones "Alto Nivel" por no conocer el
layout exacto de sus structs -- **ya no aplica**, `MGW_SDK.h` los define
completos. Todos usan `#pragma pack(4)` (`Pack = 4` en C#) y campos de texto
de tamaño fijo (`char buf[N+1]` en C ↔ `[MarshalAs(UnmanagedType.ByValTStr,
SizeConst = N+1)] public string` en C#, usando `CharSet.Ansi`).

Longitudes base (de `MGW_SDK.h`): `kLongCodigo=30`, `kLongNombre=60`,
`kLongFecha=23`, `kLongRFC=20`, `kLongCURP=20`, `kLongDenComercial=50`,
`kLongRepLegal=50`, `kLongReferencia=20`, `kLongDescripcion=60`,
`kLongTextoExtra=50`, `kLongCodValorClasif=3`, `kLongNombreProducto=255`.
En los structs cada campo reserva `+1` para el terminador.

```csharp
[StructLayout(LayoutKind.Sequential, Pack = 4, CharSet = CharSet.Ansi)]
public struct RegDocumento
{
    public double aFolio;
    public int aNumMoneda;
    public double aTipoCambio;
    public double aImporte;
    public double aDescuentoDoc1;
    public double aDescuentoDoc2;
    public int aSistemaOrigen;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodConcepto;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 12)] public string aSerie;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 24)] public string aFecha;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodigoCteProv;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodigoAgente;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)] public string aReferencia;
    public int aAfecta;
    public double aGasto1;
    public double aGasto2;
    public double aGasto3;
}

[StructLayout(LayoutKind.Sequential, Pack = 4, CharSet = CharSet.Ansi)]
public struct RegMovimiento
{
    public int aConsecutivo;
    public double aUnidades;
    public double aPrecio;
    public double aCosto;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodProdSer;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodAlmacen;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)] public string aReferencia;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)] public string aCodClasificacion;
}

// Declaraciones correspondientes (aIdDocumento/aIdMovimiento son "por
// referencia" -- el SDK regresa el ID del registro recién creado):
[DllImport("MGWSERVICIOS.DLL")]
public static extern int fAltaDocumento(ref int aIdDocumento, ref RegDocumento astDocumento);
[DllImport("MGWSERVICIOS.DLL")]
public static extern int fAltaMovimiento(int aIdDocumento, ref int aIdMovimiento, ref RegMovimiento astMovimiento);
```

Para `ClienteProveedor` y `Producto` (structs mucho más grandes, decenas de
campos) -- ver la definición completa en `MGW_SDK.h` (`typedef struct
ClienteProveedor`/`typedef struct Producto`) y traducir cada `char campo[N+1]`
al mismo patrón `[MarshalAs(UnmanagedType.ByValTStr, SizeConst = N+1)]`. Las
funciones correspondientes:

```csharp
[DllImport("MGWSERVICIOS.DLL")]
public static extern int fAltaCteProv(ref int aIdCteProv, ref ClienteProveedor astCteProv);
[DllImport("MGWSERVICIOS.DLL")]
public static extern int fAltaProducto(ref int aIdProducto, ref Producto astProducto);
```

## Constantes de nombres de campo (para `fLeeDato<X>`/`fSetDato<X>`)

Estas constantes son los nombres de campo REALES a usar como `aCampo` --
**no son necesariamente iguales a las columnas de la tabla SQL Server
subyacente** (ej. el campo del SDK para el concepto de un documento es
`cCodigoConcepto`, mientras que la columna SQL equivalente es
`CIDCONCEPTODOCUMENTO`). Ver tabla completa en `MGW_SDK.h`
(sección "Constantes de nombres de campos"). Las más usadas:

| Entidad | Constante | Campo real (string) |
|---|---|---|
| Cliente/Proveedor | `kCteProv_Codigo` | `cCodigoCliente` |
| Cliente/Proveedor | `kCteProv_RazonSocial` | `cRazonSocial` |
| Cliente/Proveedor | `kCteProv_RFC` | `cRFC` |
| Documento | `kDocumento_IdDocumento` | `cIdDocumento` |
| Documento | `kDocumento_CodigoConcepto` | `cCodigoConcepto` |
| Documento | `kDocumento_Serie` | `cSerieDocumento` |
| Documento | `kDocumento_Folio` | `cFolio` |
| Documento | `kDocumento_CodigoCteProv` | `cCodigoCteProv` |
| Documento | `kDocumento_Fecha` | `cFecha` |
| Movimiento | `kMovto_IdMovto` | `cIdMovimiento` |
| Movimiento | `kMovto_CodProducto` | `cCodigoProducto` |
| Movimiento | `kMovto_CodAlmacen` | `cCodigoAlmacen` |
| Movimiento | `kMovto_Unidades` | `cUnidades` |
| Movimiento | `kMovto_Precio` | `cPrecio` |
| Producto | `kProducto_Codigo` | `cCodigoProducto` |
| Producto | `kProducto_Nombre` | `cNombreProducto` |
| Producto | `kProducto_Descripcion` | `cDescripcionProducto` |

**Antes de escribir código nuevo que llame `fSetDato<X>`/`fLeeDato<X>`,
verificar el nombre exacto de campo contra `MGW_SDK.h`** en vez de asumir
que coincide con la columna SQL -- fue un error real cometido antes de
tener este header (se usaron nombres de columna SQL Server directamente,
ej. `CIDCONCEPTODOCUMENTO`/`CIDCLIENTEPROVEEDOR`, que casi seguro no son
los nombres de campo correctos del SDK -- pendiente de corregir y volver a
probar cuando el bloqueo de licenciamiento se resuelva).

## Ubicar el SDK vía registro (antes de cualquier llamada de arriba)

```csharp
const string regKey = @"SOFTWARE\Computación en Acción, SA CV\CONTPAQ I COMERCIAL";
using (var key = Registry.LocalMachine.OpenSubKey(regKey))
{
    if (key == null) throw new Exception("No se encontró la llave de registro del SDK: " + regKey);
    var dir = key.GetValue("DirectorioBase") as string;
    Sdk.SetCurrentDirectory(dir);
}
```

Recordar: en Windows de 64 bits, `Registry.LocalMachine.OpenSubKey` con esta
ruta solo encuentra la llave si el proceso compiló `/platform:x86` (deja que
Windows redirija automáticamente a `WOW6432Node`) -- en `AnyCPU`/x64 la
llave aparece vacía/no existe, aunque sí exista en el registro real.

## Secuencia completa de arranque (pseudocódigo)

```csharp
PrepararSdkPath();                                    // registro + SetCurrentDirectory
Sdk.fInicioSesionSDK(usuario, contraseña);            // ANTES de fSetNombrePAQ -- ver Gotcha #1
Sdk.fSetNombrePAQ("CONTPAQ I COMERCIAL");
int idEmpresa = 0;
var nombre = new StringBuilder(256);
var directorio = new StringBuilder(512);
Sdk.fPosPrimerEmpresa(ref idEmpresa, nombre, directorio);
Sdk.fAbreEmpresa(directorio.ToString());
// ... operaciones ...
// Si se creó/editó un documento: fAfectaDocto_Param(concepto, serie, folio, true)
// ANTES de cerrar -- ver Gotcha #2 en SKILL.md. Sin esto los acumulados
// del sistema no se actualizan.
Sdk.fCierraEmpresa();
Sdk.fTerminaSDK();
```

## Transferencia de archivos por fragmentos (para despliegue vía WinRM)

WinRM no tiene copia de archivos nativa, y `pywinrm` manda cada comando como
argumento de línea de comandos (`-encodedcommand`) con límite de tamaño --
subir binarios/fuentes grandes en un solo comando truena. Patrón que
funciona (Python, usando `winrm.Session`):

```python
import base64

CHUNK_SIZE = 2000  # caracteres base64 por fragmento

def upload_file(session, content_bytes, remote_path):
    b64 = base64.b64encode(content_bytes).decode("ascii")
    chunks = [b64[i:i + CHUNK_SIZE] for i in range(0, len(b64), CHUNK_SIZE)] or [""]
    for i, chunk in enumerate(chunks):
        if i == 0:
            script = (
                f'$bytes = [System.Convert]::FromBase64String("{chunk}"); '
                f'[System.IO.File]::WriteAllBytes("{remote_path}", $bytes)'
            )
        else:
            script = (
                f'$bytes = [System.Convert]::FromBase64String("{chunk}"); '
                f'$fs = [System.IO.File]::Open("{remote_path}", [System.IO.FileMode]::Append); '
                f'$fs.Write($bytes, 0, $bytes.Length); $fs.Close()'
            )
        session.run_ps(script)
```

Compilar en el propio servidor con `csc.exe` de .NET Framework (no requiere
Visual Studio):

```powershell
$csc = "$env:windir\Microsoft.NET\Framework64\v4.0.30319\csc.exe"
& $csc /nologo /platform:x86 /out:"salida.exe" "Sdk.cs" "Program.cs"
```
