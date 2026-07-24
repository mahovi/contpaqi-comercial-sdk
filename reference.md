# Referencia P/Invoke -- MGWServicios.dll

Declaraciones C# ya usadas y funcionando contra un servidor CONTPAQi
Comercial real. Punto de partida directo -- no hace falta re-extraer estas
firmas del manual.

```csharp
using System;
using System.Runtime.InteropServices;
using System.Text;

public static class Sdk
{
    // --- Inicialización / Terminación ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fSetNombrePAQ(string aNombrePAQ);

    // Llamar ANTES de fSetNombrePAQ -- ver SKILL.md Gotcha #1.
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
    public static extern int fAbreEmpresa(string aDirectorioEmpresa);

    [DllImport("MGWSERVICIOS.DLL")]
    public static extern void fCierraEmpresa();

    // --- Existencias / Precios ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaExistencia(string aCodigoProducto, string aCodigoAlmacen,
        string aAnio, string aMes, string aDia, ref double aExistencia);

    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fRegresaPrecioVenta(string aCodigoConcepto, string aCodigoCliente,
        string aCodigoProducto, StringBuilder aPrecioVenta);

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

    // --- Productos (Bajo Nivel) ---
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaProducto(string aCodProducto);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fBuscaIdProducto(int aIdProducto);
    [DllImport("MGWSERVICIOS.DLL")]
    public static extern int fLeeDatoProducto(string aCampo, StringBuilder aValor, int aLen);

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
