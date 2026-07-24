/*--------------------------------------------------------------------------------------------------
  Historia de Revisiones
  Fecha       ID-Lotus      Descripcion
----------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------- */
#ifndef MGW_SDKH
#define MGW_SDKH

#include <windows.h>
#define kDECIMALES_PORCENTAJES    2

////////////////////////////////////////////////////////////////////////////////////////////////////
// Constantes de nombres de campos
////////////////////////////////////////////////////////////////////////////////////////////////////

// Campos de la tabla de Agentes
#define kAgente_Codigo                      "cCodigoAgente"
#define kAgente_Nombre                      "cNombreAgente"
#define kAgente_Tipo                        "cTipoAgente"
#define kAgente_CodigoCliente               "cCodigoCliente"
#define kAgente_CodigoProveedor             "cCodigoProveedor"
#define kAgente_CodigoValorClasif1          "cCodigoValorClasif1"
#define kAgente_CodigoValorClasif2          "cCodigoValorClasif2"
#define kAgente_CodigoValorClasif3          "cCodigoValorClasif3"
#define kAgente_CodigoValorClasif4          "cCodigoValorClasif4"
#define kAgente_CodigoValorClasif5          "cCodigoValorClasif5"
#define kAgente_CodigoValorClasif6          "cCodigoValorClasif6"
#define kCteProv_DescProntoPago             "cDescuentoProntoPago"
#define kAgente_ComisionVenta               "cComisionVentaAgente"
#define kAgente_ComisionCobro               "cComisionCobroAgente"

// Campos de la tablas de Clientes/Proveedores
#define kCteProv_Codigo                     "cCodigoCliente"
#define kCteProv_RazonSocial                "cRazonSocial"
#define kCteProv_RFC                        "cRFC"
#define kCteProv_Tipo                       "cTipoCliente"
#define kCteProv_Mensajeria                 "cMensajeria"
#define kCteProv_CodigoAgenteVenta          "cCodigoAgenteVenta"
#define kCteProv_CodigoAgenteCobro          "cCodigoAgenteCobro"
#define kCteProv_CodigoValorClasCte1        "cCodigoValorClasifCte1"
#define kCteProv_CodigoValorClasCte2        "cCodigoValorClasifCte2"
#define kCteProv_CodigoValorClasCte3        "cCodigoValorClasifCte3"
#define kCteProv_CodigoValorClasCte4        "cCodigoValorClasifCte4"
#define kCteProv_CodigoValorClasCte5        "cCodigoValorClasifCte5"
#define kCteProv_CodigoValorClasCte6        "cCodigoValorClasifCte6"
#define kCteProv_CodigoValorClasProv1       "cCodigoValorClasifPro1"
#define kCteProv_CodigoValorClasProv2       "cCodigoValorClasifPro2"
#define kCteProv_CodigoValorClasProv3       "cCodigoValorClasifPro3"
#define kCteProv_CodigoValorClasProv4       "cCodigoValorClasifPro4"
#define kCteProv_CodigoValorClasProv5       "cCodigoValorClasifPro5"
#define kCteProv_CodigoValorClasProv6       "cCodigoValorClasifPro6"
#define kCteProv_DescProntoPago             "cDescuentoProntoPago"
#define kCteProv_InteresMoratorio           "cInteresMoratorio"
#define kCteProv_NombreMoneda               "cNombreMoneda"
#define kCteProv_ComisionVenta              "cComVenta"
#define kCteProv_ComisionCobro              "cComCobro"
#define kCteProv_CodigoAlmacenConsignacion  "cCodigoAlmacen"

// Campos de la tablas de Direcciones
#define kDireccion_CodigoCatalogo           "cCodigoCatalogo"
#define kDireccion_TipoCatalogo             "cTipoCatalogo"

// Campos de la tablas de Almacenes
#define kAlmacen_Codigo                     "cCodigoAlmacen"
#define kAlmacen_CodigoValorClasif1         "cCodigoValorClasif1"
#define kAlmacen_CodigoValorClasif2         "cCodigoValorClasif2"
#define kAlmacen_CodigoValorClasif3         "cCodigoValorClasif3"
#define kAlmacen_CodigoValorClasif4         "cCodigoValorClasif4"
#define kAlmacen_CodigoValorClasif5         "cCodigoValorClasif5"
#define kAlmacen_CodigoValorClasif6         "cCodigoValorClasif6"

// Campos de la tablas de Documentos
#define kDocumento_IdDocumento              "cIdDocumento"
#define kDocumento_CodigoConcepto           "cCodigoConcepto"
#define kDocumento_Serie                    "cSerieDocumento"
#define kDocumento_Folio                    "cFolio"
#define kDocumento_Fecha                    "cFecha"
#define kDocumento_CodigoCteProv            "cCodigoCteProv"
#define kDocumento_RazonSocial              "cRazonSocial"
#define kDocumento_RFC                      "cRFC"
#define kDocumento_SerieOmision             "cSeriePorOmision"
#define kDocumento_CodigoAgente             "cCodigoAgente"
#define kDocumento_FechaVencimiento         "cFechaVencimiento"
#define kDocumento_FechaEntRecep            "cFechaEntregaRecepcion"
#define kDocumento_FechaProntoPago          "cFechaProntoPago"
#define kDocumento_FechaUltimoInteres       "cFechaUltimoInteres"
#define kDocumento_IdMoneda                 "cidMoneda"
#define kDocumento_TipoCambio               "cTipoCambio"
#define kDocumento_Referencia               "cReferencia"
#define kDocumento_Importe                  "cImporte"
#define kDocumento_Descuento1               "cDescuentoDoc1"
#define kDocumento_Descuento2               "cDescuentoDoc2"
#define kDocumento_DescProntoPago           "cDescuentoProntoPago"
#define kDocumento_InteresMoratorio         "cPorcentajeInteres"
#define kDocumento_SisOrigen                "cSistOrig"
#define kDocumento_Observaciones            "cObservaciones"
#define kDocumento_ConDireccionFiscal       "cConDireccionFiscal"
#define kDocumento_ConDireccionEnvio        "cConDireccionEnvio"
#define kDocumento_Gasto1                   "cGasto1"
#define kDocumento_Gasto2                   "cGasto2"
#define kDocumento_Gasto3                   "cGasto3"

// Campos de la tablas de Movimientos
#define kMovto_IdMovto                      "cIdMovimiento"
#define kMovto_NumMovto                     "cNumeroMovimiento"
#define kMovto_CodProducto                  "cCodigoProducto"
#define kMovto_CodAlmacen                   "cCodigoAlmacen"
#define kMovto_CodAlmacenEntrada            "cCodigoAlmacenEntrada"
#define kMovto_CodAlmacenSalida             "cCodigoAlmacenSalida"
#define kMovto_CodAlmacenConsignacion       "cCodigoAlmacenConsignacion"
#define kMovto_Unidades                     "cUnidades"
#define kMovto_UnidadesNC                   "cUnidadesNC"
#define kMovto_Precio                       "cPrecio"
#define kMovto_CostoCapturado               "cCostoCapturado"
#define kMovto_CodValorClasificacion        "cCodigoValorClasificacion"
#define kMovto_Referencia                   "cReferencia"
#define kMovto_FechaExtra                   "cFechaExtra"
#define kMovto_NombreUnidad                 "cNombreUnidad"
#define kMovto_NombreUnidadNC               "cNombreUnidadNC"
#define kMovto_CodClasificacion             "cCodigoClasificacion"
#define kMovto_Neto                         "cNeto"
#define kMovto_Total                        "cTotal"
#define kMovto_ObservaMov                   "cObservaMov"
#define kMovto_ComisionVenta	              "cComVenta"

#define kMovto_PorcDescto1                  "cPorcentajeDescuento1"
#define kMovto_ImportDescto1                "cDescuento1"
#define kMovto_PorcDescto2                  "cPorcentajeDescuento2"
#define kMovto_ImportDescto2                "cDescuento2"
#define kMovto_PorcDescto3                  "cPorcentajeDescuento3"
#define kMovto_ImportDescto3                "cDescuento3"
#define kMovto_PorcDescto4                  "cPorcentajeDescuento4"
#define kMovto_ImportDescto4                "cDescuento4"
#define kMovto_PorcDescto5                  "cPorcentajeDescuento5"
#define kMovto_ImportDescto5                "cDescuento5"

// Campos de la tabla de Productos
#define kProducto_Codigo                    "cCodigoProducto"
#define kProducto_Nombre                    "cNombreProducto"
#define kProducto_Tipo                      "cTipoProducto"
#define kProducto_Precio1                   "cPrecio1"
#define kProducto_NombrePadreCarac1         "cNombrePadreCarac1"
#define kProducto_NombrePadreCarac2         "cNombrePadreCarac2"
#define kProducto_NombrePadreCarac3         "cNombrePadreCarac3"
#define kProducto_CodigoValorClasif1        "cCodigoValorClasif1"
#define kProducto_CodigoValorClasif2        "cCodigoValorClasif2"
#define kProducto_CodigoValorClasif3        "cCodigoValorClasif3"
#define kProducto_CodigoValorClasif4        "cCodigoValorClasif4"
#define kProducto_CodigoValorClasif5        "cCodigoValorClasif5"
#define kProducto_CodigoValorClasif6        "cCodigoValorClasif6"
#define kProducto_NombreUnidadBase          "cNombreUnidadBase"
#define kProducto_NombreUnidadCompra        "cNombreUnidadCompra"
#define kProducto_NombreUnidadVenta         "cNombreUnidadVenta"
#define kProducto_NombreUnidadXML           "cNombreUnidadXML"
#define kProducto_NombreUnidadNoConvertible "cNombreUnidadNoConvertible"
#define kProducto_Descripcion               "cDescripcionProducto"
#define kProducto_MetodoCosteo              "cMetodoCosteo"
#define kProducto_ComisionVenta	            "cComVentaExcepProducto"
#define kProducto_MonedaCostoExtra1         "cMonedaCostoExtra1"
#define kProducto_MonedaCostoExtra2         "cMonedaCostoExtra2"
#define kProducto_MonedaCostoExtra3         "cMonedaCostoExtra3"
#define kProducto_MonedaCostoExtra4         "cMonedaCostoExtra4"
#define kProducto_MonedaCostoExtra5         "cMonedaCostoExtra5"
#define kProducto_MargenUtilidad            "cMargenUtilidad"
#define kProducto_ComisionCobro	            "cComCobroExcepProducto"


// Campos de la tabla de Promociones
#define kPromocion_cCodigoValorClasifCliente1   "cCodigoValorClasifCliente1"
#define kPromocion_cCodigoValorClasifCliente2   "cCodigoValorClasifCliente2"
#define kPromocion_cCodigoValorClasifCliente3   "cCodigoValorClasifCliente3"
#define kPromocion_cCodigoValorClasifCliente4   "cCodigoValorClasifCliente4"
#define kPromocion_cCodigoValorClasifCliente5   "cCodigoValorClasifCliente5"
#define kPromocion_cCodigoValorClasifCliente6   "cCodigoValorClasifCliente6"
#define kPromocion_cCodigoValorClasifProducto1  "cCodigoValorClasifProducto1"
#define kPromocion_cCodigoValorClasifProducto2  "cCodigoValorClasifProducto2"
#define kPromocion_cCodigoValorClasifProducto3  "cCodigoValorClasifProducto3"
#define kPromocion_cCodigoValorClasifProducto4  "cCodigoValorClasifProducto4"
#define kPromocion_cCodigoValorClasifProducto5  "cCodigoValorClasifProducto5"
#define kPromocion_cCodigoValorClasifProducto6  "cCodigoValorClasifProducto6"

// Campos de la tabla de Series
#define kSerie_NumeroSerie                  "cNumeroSerie"

// Campos de la tabla de Capas
#define kCapas_Pedimento                    "cPedimento"
#define kCapas_NumeroLote                   "cNumeroLote"
#define kCapas_Aduana                       "cAduana"
#define kCapas_FechaPedimento               "cFechaPedimento"
#define kCapas_FechaFabricacion             "cFechaFabricacion"
#define kCapas_FechaCaducidad               "cFechaCaducidad"
#define kCapas_Existencia                   "cExistencia"
#define kCapas_TipoCapa                     "cTipoCapa"
#define kCapas_Fecha                        "cFecha"
#define kCapas_Costo                        "cCosto"
#define kCapas_TipoCambio                   "cTipoCambio"
#define kCapas_NumeroAduana                 "cNumAduana"  //N.D. 8821

// Campos de la tabla de Unidades
#define kUnidades_IdUnidad                  "cIdUnidad"
#define kUnidades_NombreUnidad              "cNombreUnidad"
#define kUnidades_Abreviatura               "cAbreviatura"

// Campos de la tabla de Cajas
#define kCaja_Codigo                        "cCodigoC01"
#define kClave_Usuario                      "Clave"

// Definicion de constantes de longitudes de campos
#define kLongFecha                23
#define kLongSerie                11
#define kLongCodigo               30
#define kLongNombre               60
#define kLongReferencia           20
#define kLongDescripcion          60
#define kLongCuenta              100
#define kLongMensaje            3000
#define kLongNombreProducto      255
#define kLongAbreviatura           3
#define kLongCodValorClasif        3
#define kLongDenComercial         50
#define kLongRepLegal             50
#define kLongTextoExtra           50
#define kLongRFC                  20
#define kLongCURP                 20
#define kLongDesCorta             20
#define kLongNumeroExtInt          6
#define kLongNumeroExpandido      30
#define kLongCodigoPostal          6
#define kLongTelefono             15
#define kLongEmailWeb             50

#define kLongSelloSat             690
#define kSDKLonSerieCertSAT          189
#define kLongFechaHora            35
#define kLongSelloCFDI            690
#define kSDKLongitudUUID             205
#define kLongitudRegimen          100
#define kLongitudMoneda           60
#define kLongitudFolio            16
#define kLongitudMonto            30
#define kLogitudLugarExpedicion   400
#define kLongitudNomBanExtranjero 254 

// Constantes para el método fLlenaRegistro...
#define kAlta_Registro              1
#define kActualizacion_Registro     2

/***************************************************************************************************
Estructura de para grabar Documentos con un movimiento  (Cargos y Abonos)
***************************************************************************************************/
#pragma pack(push)
#pragma pack(4)
// Definición de estructura de datos de documentos -------------------------------------------------
typedef struct RegDocumento {
   double aFolio;
   int    aNumMoneda;
   double aTipoCambio;
   double aImporte;
   double aDescuentoDoc1;
   double aDescuentoDoc2;
   int    aSistemaOrigen;
   char   aCodConcepto[ kLongCodigo + 1 ];
   char   aSerie[ kLongSerie + 1 ];
   char   aFecha[ kLongFecha + 1 ];
   char   aCodigoCteProv[ kLongCodigo + 1 ];
   char   aCodigoAgente[ kLongCodigo + 1 ];
   char   aReferencia[ kLongReferencia + 1 ];
   int    aAfecta;
   double aGasto1;
   double aGasto2;
   double aGasto3;
} REGDOCUMENTO;

typedef REGDOCUMENTO FAR * LPFREGDOCUMENTO;

// Definición de estructura de datos de movimientos ------------------------------------------------
typedef struct RegMovimiento {
  int     aConsecutivo;
  double  aUnidades;
  double  aPrecio;
  double  aCosto;
  char    aCodProdSer[ kLongCodigo + 1 ];
  char    aCodAlmacen[ kLongCodigo + 1 ];
  char    aReferencia[ kLongReferencia + 1 ];
  char    aCodClasificacion[ kLongCodigo + 1 ];
} REGMOVIMIENTO;

typedef REGMOVIMIENTO FAR * LPFREGMOVIMIENTO;

// Definición de estructura de datos de movimientos con Descuentos ---------------------------------
typedef struct RegMovimientoCDesctos {
  int     aConsecutivo;
  double  aUnidades;
  double  aPrecio;
  double  aCosto;
  double  aPorcDescto1;
  double aImporteDescto1;
  double  aPorcDescto2;
  double aImporteDescto2;
  double  aPorcDescto3;
  double aImporteDescto3;
  double  aPorcDescto4;
  double aImporteDescto4;
  double  aPorcDescto5;
  double aImporteDescto5;
  char    aCodProdSer[ kLongCodigo + 1 ];
  char    aCodAlmacen[ kLongCodigo + 1 ];
  char    aReferencia[ kLongReferencia + 1 ];
  char    aCodClasificacion[ kLongCodigo + 1 ];
} REGMOVIMIENTOCDESCTOS;

typedef REGMOVIMIENTOCDESCTOS FAR * LPFREGMOVIMIENTOCDESCTOS;

// Definición de estructura de datos del la llave de documentos ------------------------------------
typedef struct RegLlaveDoc {
  char   aCodConcepto[ kLongCodigo + 1 ];
  char   aSerie[ kLongSerie + 1 ];
  double aFolio;
} REGLLAVEDOC;

typedef REGLLAVEDOC FAR * LPFREGLLAVEDOC;

// Definición de estructura de datos movimientos de Serie/Capas ------------------------------------
typedef struct SeriesCapas {
  double aUnidades;
  double aTipoCambio;
  char   aSeries[ kLongCodigo + 1 ];
  char   aPedimento[ kLongDescripcion + 1 ];
  char   aAgencia[ kLongDescripcion + 1 ];
  char   aFechaPedimento[ kLongFecha + 1 ];
  char   aNumeroLote[ kLongDescripcion + 1 ];
  char   aFechaFabricacion[ kLongFecha + 1 ];
  char   aFechaCaducidad[ kLongFecha + 1 ];
} SERIESCAPAS;

typedef SERIESCAPAS FAR * LPSERIESCAPAS;

// Definición de estructura de datos de caracteristicas --------------------------------------------
typedef struct Caracteristicas {
  double aUnidades;
  char   aValorCaracteristica1[ kLongDescripcion + 1 ];
  char   aValorCaracteristica2[ kLongDescripcion + 1 ];
  char   aValorCaracteristica3[ kLongDescripcion + 1 ];
} CARACTERISTICAS;

typedef CARACTERISTICAS FAR * LPCARACTERISTICAS;

// Definicion de estructura de datos de caracteristicas con unidades de peso y medida --------------
typedef struct CaracteristicasUnidades
{
  char   aUnidad[ kLongAbreviatura + 1 ];
  double aUnidades;
  double aUnidadesNC;
  char   aValorCaracteristica1[ kLongDescripcion + 1 ];
  char   aValorCaracteristica2[ kLongDescripcion + 1 ];
  char   aValorCaracteristica3[ kLongDescripcion + 1 ];
} CARACTERISTICASUNIDADES;

typedef CARACTERISTICASUNIDADES FAR * LPCARACTERISTICASUNIDADES;

// Definición de estructura de datos del tipo de producto  -----------------------------------------
typedef union TipoProducto {
  SeriesCapas     aSeriesCapas;
  Caracteristicas aCaracteristicas;
} TIPOPRODUCTO;

typedef TIPOPRODUCTO FAR * LPFTIPOPRODUCTO;

// Definición de estructura de datos del la llave de aperturas -------------------------------------
typedef struct RegLlaveAper {
  char aCodCaja[ kLongCodigo + 1 ];
  char aFechaApe[ kLongFecha + 1 ];
} REGLLAVEAPER;

typedef REGLLAVEAPER FAR * LPFREGLLAVEAPER;

// Definición de estructura de datos de productos --------------------------------------------------
typedef struct Producto
{
  char   cCodigoProducto[ kLongCodigo + 1 ];
  char   cNombreProducto[ kLongNombre + 1 ];
  char   cDescripcionProducto[ kLongNombreProducto + 1 ];
  int    cTipoProducto; // 1 = Producto, 2 = Paquete, 3 = Servicio
  char   cFechaAltaProducto[ kLongFecha + 1 ];
  char   cFechaBaja[ kLongFecha + 1 ];
  int    cStatusProducto; // 0 - Baja Lógica, 1 - Alta
  int    cControlExistencia; //
  int    cMetodoCosteo; // 1 = Costo Promedio en Base a Entradas, 2 = Costo Promedio en Base a Entradas Almacen, 3 = Último costo, 4 = UEPS, 5 = PEPS, 6 = Costo específico, 7 = Costo Estandar
  char   cCodigoUnidadBase[ kLongCodigo + 1 ];
  char   cCodigoUnidadNoConvertible[ kLongCodigo + 1 ];
  double cPrecio1;
  double cPrecio2;
  double cPrecio3;
  double cPrecio4;
  double cPrecio5;
  double cPrecio6;
  double cPrecio7;
  double cPrecio8;
  double cPrecio9;
  double cPrecio10;
  double cImpuesto1;
  double cImpuesto2;
  double cImpuesto3;
  double cRetencion1;
  double cRetencion2;
  // N.D.8386 La estructura debe recibir el nombre de la característica padre. (ALRH)
  char   cNombreCaracteristica1[ kLongNombre + 1 ];
  char   cNombreCaracteristica2[ kLongNombre + 1 ];
  char   cNombreCaracteristica3[ kLongNombre + 1 ];
  char   cCodigoValorClasificacion1[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacion2[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacion3[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacion4[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacion5[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacion6[ kLongCodValorClasif + 1 ];
  char   cTextoExtra1[ kLongTextoExtra + 1 ];
  char   cTextoExtra2[ kLongTextoExtra + 1 ];
  char   cTextoExtra3[ kLongTextoExtra + 1 ];
  char   cFechaExtra[ kLongFecha + 1 ];
  double cImporteExtra1;
  double cImporteExtra2;
  double cImporteExtra3;
  double cImporteExtra4;
} PRODUCTO;

typedef PRODUCTO FAR * LPFREGPRODUCTO;

// Definición de estructura de datos de cliente/proveedor ------------------------------------------
typedef struct ClienteProveedor
{
  char   cCodigoCliente[ kLongCodigo + 1 ];
  char   cRazonSocial[ kLongNombre + 1 ];
  char   cFechaAlta[ kLongFecha + 1 ];
  char   cRFC[ kLongRFC + 1 ];
  char   cCURP[ kLongCURP + 1 ];
  char   cDenComercial[ kLongDenComercial + 1 ];
  char   cRepLegal[ kLongRepLegal + 1 ];
  char   cNombreMoneda[ kLongNombre + 1 ];
  int    cListaPreciosCliente;
  double cDescuentoMovto;
  int    cBanVentaCredito; // 0 = No se permite venta a crédito, 1 = Se permite venta a crédito
  char   cCodigoValorClasificacionCliente1[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionCliente2[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionCliente3[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionCliente4[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionCliente5[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionCliente6[ kLongCodValorClasif + 1 ];
  int    cTipoCliente; // 1 - Cliente, 2 - Cliente/Proveedor, 3 - Proveedor
  int    cEstatus; // 0. Inactivo, 1. Activo
  char   cFechaBaja[ kLongFecha + 1 ];
  char   cFechaUltimaRevision[ kLongFecha + 1 ];
  double cLimiteCreditoCliente;
  int    cDiasCreditoCliente;
  int    cBanExcederCredito; // 0 = No se permite exceder crédito, 1 = Se permite exceder el crédito
  double cDescuentoProntoPago;
  int    cDiasProntoPago;
  double cInteresMoratorio;
  int    cDiaPago;
  int    cDiasRevision;
  char   cMensajeria[ kLongDesCorta + 1 ];
  char   cCuentaMensajeria[ kLongDescripcion + 1 ];
  int    cDiasEmbarqueCliente;
  char   cCodigoAlmacen[ kLongCodigo + 1 ];
  char   cCodigoAgenteVenta[ kLongCodigo + 1 ];
  char   cCodigoAgenteCobro[ kLongCodigo + 1 ];
  int    cRestriccionAgente;
  double cImpuesto1;
  double cImpuesto2;
  double cImpuesto3;
  double cRetencionCliente1;
  double cRetencionCliente2;
  char   cCodigoValorClasificacionProveedor1[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionProveedor2[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionProveedor3[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionProveedor4[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionProveedor5[ kLongCodValorClasif + 1 ];
  char   cCodigoValorClasificacionProveedor6[ kLongCodValorClasif + 1 ];
  double cLimiteCreditoProveedor;
  int    cDiasCreditoProveedor;
  int    cTiempoEntrega;
  int    cDiasEmbarqueProveedor;
  double cImpuestoProveedor1;
  double cImpuestoProveedor2;
  double cImpuestoProveedor3;
  double cRetencionProveedor1;
  double cRetencionProveedor2;
  int    cBanInteresMoratorio; // 0 = No se le calculan intereses moratorios al cliente, 1 = Si se le calculan intereses moratorios al cliente.
  char   cTextoExtra1[ kLongTextoExtra + 1 ];
  char   cTextoExtra2[ kLongTextoExtra + 1 ];
  char   cTextoExtra3[ kLongTextoExtra + 1 ];
  char   cFechaExtra[ kLongFecha + 1 ];
  double cImporteExtra1;
  double cImporteExtra2;
  double cImporteExtra3;
  double cImporteExtra4;
} CLIENTEPROVEEDOR;

typedef CLIENTEPROVEEDOR FAR * LPFREGCTEPROV;

// Definición de estructura de datos de valor clasificacion ----------------------------------------
typedef struct ValorClasificacion
{
  int  cClasificacionDe;
  int  cNumClasificacion;
  char cCodigoValorClasificacion[ kLongCodValorClasif + 1 ];
  char cValorClasificacion[ kLongDescripcion + 1 ];
} VALORCLASIFICACION;

typedef VALORCLASIFICACION FAR * LPFREGVALORCLASIFICACION;

// Definición de estructura de datos de unidad de peso y medida ------------------------------------
typedef struct Unidad
{
  char cNombreUnidad[ kLongNombre + 1 ];
  char cAbreviatura[ kLongAbreviatura + 1 ];
  char cDespliegue[ kLongAbreviatura + 1 ];
} UNIDAD;

typedef UNIDAD FAR * LPFREGUNIDAD;

// Definición de estructura de datos de direcciones ------------------------------------------------
typedef struct Direccion {
  char   cCodCteProv[ kLongCodigo + 1 ];
  int    cTipoCatalogo; // 1=Clientes y 2=Proveedores
  int    cTipoDireccion; // 1=Domicilio Fiscal, 2=Domicilio Envio
  char   cNombreCalle[ kLongDescripcion + 1 ];
  char   cNumeroExterior[ kLongNumeroExpandido + 1 ];
  char   cNumeroInterior[ kLongNumeroExpandido + 1 ];
  char   cColonia[ kLongDescripcion + 1 ];
  char   cCodigoPostal[ kLongCodigoPostal + 1 ];
  char   cTelefono1[ kLongTelefono + 1 ];
  char   cTelefono2[ kLongTelefono + 1 ];
  char   cTelefono3[ kLongTelefono + 1 ];
  char   cTelefono4[ kLongTelefono + 1 ];
  char   cEmail[ kLongEmailWeb + 1 ];
  char   cDireccionWeb[ kLongEmailWeb + 1 ];
  char   cCiudad[ kLongDescripcion + 1 ];
  char   cEstado[ kLongDescripcion + 1 ];
  char   cPais[ kLongDescripcion + 1 ];
  char   cTextoExtra[ kLongDescripcion + 1 ];
} DIRECCION;

typedef DIRECCION FAR * LPFREGDIRECCION;

// Definición de estructura de datos de Control de IVA  --------------------------------------------
typedef struct ControlIVA {
  double  cNetoTasa15;
  double  cNetoTasa10;
  double  cNetoTasaCero;
  double  cNetoTasaExenta;
  double  cNetoOtrasTasas;
  double  cIVATasa15;
  double  cIVATasa10;
  double  cIVAOtrasTasas;
  double  cRetIVATasa15;
  double  cRetIVATasa10;
  double  cRetIVAOtrasTasas;
  double  cRetISRTasa15;
  double  cRetISRTasa10;
  double  cRetISRTasaCero;
  double  cRetISRTasaExenta;
  double  cRetISROtrasTasas;
  double  cOtrosImpTasa15;
  double  cOtrosImpTasa10;
  double  cOtrosImpTasaCero;
  double  cOtrosImpTasaExenta;
  double  cOtrosImpOtrasTasas;
} CONTROL_IVA;

typedef CONTROL_IVA FAR * LPCONTROL_IVA;

// Nuevos métodos reforma 2010
// Definición de estructura de datos de Control de IVA  --------------------------------------------
typedef struct ControlIVA_2010 {
  double  cNetoTasa15;
  double  cNetoTasa10;
  double  cNetoTasaCero;
  double  cNetoTasaExenta;
  double  cNetoOtrasTasas;
  double  cIVATasa15;
  double  cIVATasa10;
  double  cIVAOtrasTasas;
  double  cRetIVATasa15;
  double  cRetIVATasa10;
  double  cRetIVAOtrasTasas;
  double  cRetISRTasa15;
  double  cRetISRTasa10;
  double  cRetISRTasaCero;
  double  cRetISRTasaExenta;
  double  cRetISROtrasTasas;
  double  cOtrosImpTasa15;
  double  cOtrosImpTasa10;
  double  cOtrosImpTasaCero;
  double  cOtrosImpTasaExenta;
  double  cOtrosImpOtrasTasas;
  double  cNetoTasa16;
  double  cNetoTasa11;
  double  cIVATasa16;
  double  cIVATasa11;
  double  cRetIVATasa16;
  double  cRetIVATasa11;
  double  cRetISRTasa16;
  double  cRetISRTasa11;
  double  cOtrosImpTasa16;
  double  cOtrosImpTasa11;
} CONTROL_IVA_2010;

typedef CONTROL_IVA_2010 FAR * LPCONTROL_IVA_2010;

// Definición de estructura de datos de Control de IVA  --------------------------------------------
typedef struct ControlIVA_2019 {
  double  cNetoTasa16;
  double  cNetoTasa8;
  double  cNetoTasaCero;
  double  cNetoTasaExenta;
  double  cNetoOtrasTasas;

  double  cIVATasa16;
  double  cIVATasa8;
  double  cIVAOtrasTasas;

  double  cRetIVATasa16;
  double  cRetIVATasa8;
  double  cRetIVAOtrasTasas;

  double  cRetISRTasa16;
  double  cRetISRTasa8;
  double  cRetISRTasaCero;
  double  cRetISRTasaExenta;
  double  cRetISROtrasTasas;

  double  cOtrosImpTasa16;
  double  cOtrosImpTasa8;
  double  cOtrosImpTasaCero;
  double  cOtrosImpTasaExenta;
  double  cOtrosImpOtrasTasas;
} CONTROL_IVA_2019;
typedef CONTROL_IVA_2019 FAR * LPCONTROL_IVA_2019;
  
#pragma pack(pop)
////////////////////////////////////////////////////////////////////////////////////////////////////
// Definiciones
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef MGW_SDK
  #define STDEXPIMP       __declspec(dllexport)
#else
  #define STDEXPIMP       __declspec(dllimport)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones de Interfaz a AdminPAQ
////////////////////////////////////////////////////////////////////////////////////////////////////
extern "C" STDEXPIMP void PASCAL fNoApagarMotorBD( void );

////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones Planas
////////////////////////////////////////////////////////////////////////////////////////////////////

// Funciones Generales =============================================================================
extern "C" STDEXPIMP int  PASCAL fSetNombrePAQ ( char *aSistema );
extern "C" STDEXPIMP int  PASCAL fInicializaSDK( void );
extern "C" STDEXPIMP void PASCAL fTerminaSDK   ( void );
extern "C" STDEXPIMP void PASCAL fError        ( int aNumError, char *aMensaje, int aLen );
// N.D.8475
extern "C" STDEXPIMP int  PASCAL fInicializaLicenseInfo(int aSistema);

extern "C" STDEXPIMP void PASCAL fSetModoImportacion( bool aImportacion );

extern "C" STDEXPIMP int PASCAL fPosPrimerEmpresa   ( int &aIdEmpresa, char *aNombreEmpresa, char *aDirectorioEmpresa );
extern "C" STDEXPIMP int PASCAL fPosSiguienteEmpresa( int &aIdEmpresa, char *aNombreEmpresa, char *aDirectorioEmpresa );

extern "C" STDEXPIMP int  PASCAL fAbreEmpresa   ( char *aDirectorioEmpresa );
extern "C" STDEXPIMP void PASCAL fCierraEmpresa ( void );

// Funciones de Documentos =========================================================================
extern "C" STDEXPIMP int PASCAL fInsertarDocumento( void );
extern "C" STDEXPIMP int PASCAL fEditarDocumento  ( void );
extern "C" STDEXPIMP int PASCAL fGuardaDocumento  ( void );
// Funciones para borrar / cancelar el documento
extern "C" STDEXPIMP int PASCAL fCancelaDoctoInfo ( char *aPass );
extern "C" STDEXPIMP int PASCAL fBorraDocumento   ( void );
extern "C" STDEXPIMP int PASCAL fCancelaDocumento ( void );
// Funciones para borrar / cancelar el documento eliminando la Interfaz Contable
extern "C" STDEXPIMP int PASCAL fBorraDocumento_CW  ( void );
extern "C" STDEXPIMP int PASCAL fCancelaDocumento_CW( void );

extern "C" STDEXPIMP int PASCAL fCancelarModificacionDocumento( void );

extern "C" STDEXPIMP int PASCAL fSetDatoDocumento( const char *aCampo, char *aValor );
extern "C" STDEXPIMP int PASCAL fLeeDatoDocumento( const char *aCampo, char *aValor, int aLen );

extern "C" STDEXPIMP int PASCAL fSiguienteFolio( char *aCodigoConcepto, char *aSerie, double &aFolio );

extern "C" STDEXPIMP int PASCAL fSetFiltroDocumento( char *aFechaInicio, char *aFechaFin,
                                                     char *aCodigoConcepto, char *aCodigoCteProv );
extern "C" STDEXPIMP int PASCAL fCancelaFiltroDocumento( void );

extern "C" STDEXPIMP int PASCAL fBuscarIdDocumento( int aIdDocumento );
extern "C" STDEXPIMP int PASCAL fBuscaDocumento   ( LPFREGLLAVEDOC astDocto );
extern "C" STDEXPIMP int PASCAL fBuscarDocumento  ( char *aCodConcepto, char *aSerie, char *aFolio );

extern "C" STDEXPIMP int PASCAL fPosPrimerDocumento   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoDocumento   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteDocumento( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorDocumento ( void );
extern "C" STDEXPIMP int PASCAL fPosBOF( void );
extern "C" STDEXPIMP int PASCAL fPosEOF( void );

extern "C" STDEXPIMP int PASCAL fAgregarHoraREP  ( char *aConcepto, char *aSerie, char *aFolio, char *aHora  );

extern "C" STDEXPIMP int PASCAL fRegresaIVACargo( LPFREGLLAVEDOC astDocto,
                                                  double &aNetoTasa15,
                                                  double &aNetoTasa10,
                                                  double &aNetoTasaCero,
                                                  double &aNetoTasaExcenta,
                                                  double &aNetoOtrasTasas,
                                                  double &aIVATasa15,
                                                  double &aIVATasa10,
                                                  double &aIVAOtrasTasas );


extern "C" STDEXPIMP int PASCAL fRegresaIVAPago( LPFREGLLAVEDOC astDocto,
                                                 double &aNetoTasa15,
                                                 double &aNetoTasa10,
                                                 double &aNetoTasaCero,
                                                 double &aNetoTasaExcenta,
                                                 double &aNetoOtrasTasas,
                                                 double &aIVATasa15,
                                                 double &aIVATasa10,
                                                 double &aIVAOtrasTasas );

// Nuevos métodos reforma 2010
extern "C" STDEXPIMP int PASCAL fRegresaIVACargo_2010( LPFREGLLAVEDOC astDocto,
                                                  double &aNetoTasa15,
                                                  double &aNetoTasa10,
                                                  double &aNetoTasa16,
                                                  double &aNetoTasa11,
                                                  double &aNetoTasaCero,
                                                  double &aNetoTasaExcenta,
                                                  double &aNetoOtrasTasas,
                                                  double &aIVATasa15,
                                                  double &aIVATasa10,
                                                  double &aIVATasa16,
                                                  double &aIVATasa11,
                                                  double &aIVAOtrasTasas );


extern "C" STDEXPIMP int PASCAL fRegresaIVAPago_2010( LPFREGLLAVEDOC astDocto,
                                                 double &aNetoTasa15,
                                                 double &aNetoTasa10,
                                                 double &aNetoTasa16,
                                                 double &aNetoTasa11,
                                                 double &aNetoTasaCero,
                                                 double &aNetoTasaExcenta,
                                                 double &aNetoOtrasTasas,
                                                 double &aIVATasa15,
                                                 double &aIVATasa10,
                                                 double &aIVATasa16,
                                                 double &aIVATasa11,
                                                 double &aIVAOtrasTasas );

//Nuevos métodos que regresan retenciones

extern "C" STDEXPIMP int PASCAL fRegresaIVACargoRet_2010( LPFREGLLAVEDOC astDocto,
                                                  double &aNetoTasa15,
                                                  double &aNetoTasa10,
                                                  double &aNetoTasa16,
                                                  double &aNetoTasa11,
                                                  double &aNetoTasaCero,
                                                  double &aNetoTasaExcenta,
                                                  double &aNetoOtrasTasas,
                                                  double &aIVATasa15,
                                                  double &aIVATasa10,
                                                  double &aIVATasa16,
                                                  double &aIVATasa11,
                                                  double &aIVAOtrasTasas,
                                                  double &aRetIVA,
                                                  double &aRetISR);

extern "C" STDEXPIMP int PASCAL fRegresaIVAPagoRet_2010( LPFREGLLAVEDOC astDocto,
                                                 double &aNetoTasa15,
                                                 double &aNetoTasa10,
                                                 double &aNetoTasa16,
                                                 double &aNetoTasa11,
                                                 double &aNetoTasaCero,
                                                 double &aNetoTasaExcenta,
                                                 double &aNetoOtrasTasas,
                                                 double &aIVATasa15,
                                                 double &aIVATasa10,
                                                 double &aIVATasa16,
                                                 double &aIVATasa11,
                                                 double &aIVAOtrasTasas,
                                                 double &aRetIVA,
                                                 double &aRetISR);

extern "C" STDEXPIMP int PASCAL fRegresaIVAPagoRet_2019 ( LPFREGLLAVEDOC astDocto, LPCONTROL_IVA_2019 aImportesIVA );


// S.C.130 Métodos para el Control de IVA
// Estos métodos se deben de llamar la primera vez con aIniciar en 1 y las restantes con aIniciar en 0 hasta que regresen kEOF(2)
extern "C" STDEXPIMP int PASCAL fRegresaControlIVACargo( LPFREGLLAVEDOC astDocto,
/* La primera vez es con 1 y las restantes es con cero*/ int     aIniciar,
//#define kDETALLE_SIN_DETALLE      0   // Regresa el IVA (Importe y tasas) totales
//#define kDETALLE_DOCTOxDOCTO      1   // Regresa el IVA (Importe y tasas) documento por documento
//#define kDETALLE_MOVTOxMOVTO      2   // Regresa el IVA (Importe y tasas) movimiento por movimiento
                                                         int     aNivelDeDetalle,
                                                         char   *aPtrReferencia/*[31]*/,
                                                         LPCONTROL_IVA aImportesIVA );

// S.C.130 Métodos para el Control de IVA
// Estos métodos se deben de llamar la primera vez con aIniciar en 1 y las restantes con aIniciar en 0 hasta que regresen kEOF(2)
extern "C" STDEXPIMP int PASCAL fRegresaControlIVAPago( LPFREGLLAVEDOC astDocto,
/* La primera vez es con 1 y las restantes es con cero*/int     aIniciar,
//#define kDETALLE_SIN_DETALLE      0   // Regresa el IVA (Importe y tasas) totales
//#define kDETALLE_DOCTOxDOCTO      1   // Regresa el IVA (Importe y tasas) documento por documento
//#define kDETALLE_MOVTOxMOVTO      2   // Regresa el IVA (Importe y tasas) movimiento por movimiento
                                                        int     aNivelDeDetalle,
                                                        char   *aPtrSerie/*[16]*/, long &aFolio, char *aPtrReferencia/*[31]*/,
                                                        LPCONTROL_IVA aImportesIVA );
// Reforma 2010
extern "C" STDEXPIMP int PASCAL fRegresaControlIVACargo_2010( LPFREGLLAVEDOC astDocto,
                                                              int     aIniciar,
                                                              int     aNivelDeDetalle,
                                                              char   *aPtrReferencia,
                                                              LPCONTROL_IVA_2010 aImportesIVA );

extern "C" STDEXPIMP int PASCAL fRegresaControlIVAPago_2010( LPFREGLLAVEDOC astDocto,
                                                             int     aIniciar,
                                                             int     aNivelDeDetalle,
                                                             char   *aPtrSerie, long &aFolio, char *aPtrReferencia,
                                                             LPCONTROL_IVA_2010 aImportesIVA );

extern "C" STDEXPIMP int PASCAL fRegresaControlIVAPago_2019 ( LPFREGLLAVEDOC astDocto, int aIniciar,int aNivelDeDetalle, char *aPtrSerie,
                                                            long &aFolio, char *aPtrReferencia, LPCONTROL_IVA_2019 aImportesIVA );


extern "C" STDEXPIMP int PASCAL fDocumentoImpreso    ( bool aImpreso );
extern "C" STDEXPIMP int PASCAL fDocumentoBloqueado  ( int &aBloqueado );
extern "C" STDEXPIMP int PASCAL fDocumentoDevuelto   ( int  aDevuelto );
extern "C" STDEXPIMP void PASCAL fActivarPrecioCompra( int  aActivar );
extern "C" STDEXPIMP int PASCAL fDocumentoUUID       ( char *aCodigoConcepto, char *aSerie, double aFolio, char *atPtrCFDIUUID);
extern "C" STDEXPIMP int PASCAL fObtieneDatosCFDI     ( char *atPtrPassword );
extern "C" STDEXPIMP int PASCAL fLeeDatoCFDI         ( char *aValor, int aDato );

extern "C" STDEXPIMP int PASCAL fGetTamSelloDigitalYCadena (char *atPtrPassword, int &aEspSelloDig, int &aEspCadOrig);
extern "C" STDEXPIMP int PASCAL fGetSelloDigitalYCadena (char *atPtrPassword, char* atPtrSelloDigital, char* atPtrCadenaOriginal);
extern "C" STDEXPIMP int PASCAL fGetSerieCertificado (char *atPtrPassword, char* aSerieCertificado);
extern "C" STDEXPIMP int PASCAL fGetNumParcialidades (char *atPtrPassword, char *aNumParcialidades);
extern "C" STDEXPIMP int PASCAL fGetCantidadParcialidades (char *atPtrPassword, char *aCantidadParcialidades);

// Funciones de Movimientos ========================================================================
extern "C" STDEXPIMP int PASCAL fInsertarMovimiento ( void );
extern "C" STDEXPIMP int PASCAL fEditarMovimiento   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaMovimiento   ( void );
extern "C" STDEXPIMP int PASCAL fCancelaCambiosMovimiento( void );
extern "C" STDEXPIMP int PASCAL fGuardaMovto  ( int aAfectar );
extern "C" STDEXPIMP int PASCAL fAfectaMovtos ( int aAfectar );

extern "C" STDEXPIMP int PASCAL fSetDatoMovimiento( const char *aCampo, char *aValor );
extern "C" STDEXPIMP int PASCAL fLeeDatoMovimiento( const char *aCampo, char *aValor, int aLen );

extern "C" STDEXPIMP int PASCAL fAfectaSerie( int aIdMovto, char *aNumeroSerie );
extern "C" STDEXPIMP int PASCAL fRecuperaTipoProducto( bool &aUnidades,
                                                       bool &aSerie,
                                                       bool &aLote,
                                                       bool &aPedimento,
                                                       bool &aCaracteristicas );

extern "C" STDEXPIMP int PASCAL fSetFiltroMovimiento    ( long aIdDocumento );
extern "C" STDEXPIMP int PASCAL fCancelaFiltroMovimiento( void );

extern "C" STDEXPIMP int PASCAL fBuscarIdMovimiento     ( long aIdMovimiento );

extern "C" STDEXPIMP int PASCAL fPosPrimerMovimiento    ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoMovimiento    ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteMovimiento ( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorMovimiento  ( void );
extern "C" STDEXPIMP int PASCAL fPosMovimientoBOF       ( void );
extern "C" STDEXPIMP int PASCAL fPosMovimientoEOF       ( void );

// Funciones de CheqPAQ ============================================================================
extern "C" STDEXPIMP int PASCAL fAltaDoctoAjusteIVAClienteProveedor( char   *aCodigoClienteProveedor,
                                                                     int     aEsCliente,
                                                                     int     aAbsorberAjusteIVA,
                                                                     char   *aFechaDocto,
                                                                     int     aIdMoneda,
                                                                     double  aTipoCambio,
                                                                     double  aImporteIVA,
                                                                     double  aTasaIVA,
                                                                     int     aIdFacturaBase,
                                                                     char    *aMetodo,
                                                                     char    *aLugar,
                                                                     int    &aIdDoctoGenerado );

extern "C" STDEXPIMP int PASCAL fAltaDoctoAjusteIESPSCteProv       ( char   *aCodigoClienteProveedor,
                                                                     int     aEsCliente,
                                                                     char   *aFechaDocto,
                                                                     int     aIdMoneda,
                                                                     double  aTipoCambio,
                                                                     double  aImporteIVA,
                                                                     double  aTasaIVA,
                                                                     double  aImporteIESPS,
                                                                     double  aTasaIESPS,
                                                                     int     aIdFacturaBase,
                                                                     char    *aMetodo,
                                                                     char    *aLugar,
                                                                     int    &aIdDoctoGenerado );


extern "C" STDEXPIMP int PASCAL fAltaDocumentoCargoAbono      ( LPFREGDOCUMENTO astDocumento );
extern "C" STDEXPIMP int PASCAL fAltaDocumentoCargoAbonoExtras( LPFREGDOCUMENTO astDocumento,
                                                                char  *aTextoExtra1,//kLongTextoExtra
                                                                char  *aTextoExtra2,//kLongTextoExtra
                                                                char  *aTextoExtra3,//kLongTextoExtra
                                                                char  *aFechaExtra ,//kLongFecha
                                                                double aImporteExtra1,
                                                                double aImporteExtra2,
                                                                double aImporteExtra3,
                                                                double aImporteExtra4);
extern "C" STDEXPIMP int PASCAL fAfectaDocto( LPFREGLLAVEDOC astDocto, bool aAfecta );
extern "C" STDEXPIMP int PASCAL fAfectaDocto_Param( char   *aCodConcepto,
                                                    char   *aSerie,
                                                    double aFolio,
                                                    bool   aAfecta );

extern "C" STDEXPIMP int PASCAL fSaldarDocumento( LPFREGLLAVEDOC astDocAPagar,
                                                  LPFREGLLAVEDOC astDocPago,
                                                  double aImporte,
                                                  int aIdMoneda,
                                                  char *aFecha );

extern "C" STDEXPIMP int PASCAL fSaldarDocumento_Param( char   *aCodConcepto_Pagar,
                                                        char   *aSerie_Pagar,
                                                        double aFolio_Pagar,
                                                        char   *aCodConcepto_Pago,
                                                        char   *aSerie_Pago,
                                                        double aFolio_Pago,
                                                        double aImporte,
                                                        int    aIdMoneda,
                                                        char   *aFecha );

extern "C" STDEXPIMP int PASCAL fSaldarDocumentoCheqPAQ(
                                                  LPFREGLLAVEDOC astDocAPagar,
                                                  LPFREGLLAVEDOC astDocPago,
                                                  double aImporte,
                                                  int aIdMoneda,
                                                  char *aFecha,
                                                  double aTipoCambioCheqPAQ );

extern "C" STDEXPIMP int PASCAL fBorrarAsociacion( LPFREGLLAVEDOC astDocAPagar,
                                                   LPFREGLLAVEDOC astDocPago );

extern "C" STDEXPIMP int PASCAL fBorrarAsociacion_Param( char   *aCodConcepto_Pagar,
                                                         char   *aSerie_Pagar,
                                                         double aFolio_Pagar,
                                                         char   *aCodConcepto_Pago,
                                                         char   *aSerie_Pago,
                                                         double aFolio_Pago );

extern "C" STDEXPIMP int PASCAL fEditarDocumentoCheqpaq(void);


extern "C" STDEXPIMP int PASCAL fEmitirDocumento( char   *aCodConcepto,
                                                  char   *aSerie,
                                                  double aFolio,
                                                  char   *aPassword,
                                                  char   *aArchivoAdicional);
extern "C" STDEXPIMP int PASCAL fEntregEnDiscoXML( char    *aCodConcepto,
                                                   char    *aSerie,
                                                   double  aFolio,
                                                   int     aFormato,
                                                   char    *aFormatoAmig );

// Funciones de Alto nivel =========================================================================
extern "C" STDEXPIMP int PASCAL fAltaDocumento   ( long &aIdDocumento, LPFREGDOCUMENTO astDocumento );
extern "C" STDEXPIMP int PASCAL fAltaMovimiento  ( long aIdDocumento,  long &aIdMovimiento, LPFREGMOVIMIENTO astMovimiento );
extern "C" STDEXPIMP int PASCAL fAltaMovimientoEx( long aIdMovimiento, LPFTIPOPRODUCTO aTipoProducto );
//SC 137
extern "C" STDEXPIMP int PASCAL fAltaMovimientoCDesct(long aIdDocumento, long &aIdMovimiento, LPFREGMOVIMIENTOCDESCTOS astMovimiento);
extern "C" STDEXPIMP int PASCAL fAltaMovimientoCaracteristicas( long aIdMovimiento,
                                                                long &aIdMovtoCaracteristicas,
                                                                LPCARACTERISTICAS aCaracteristicas );

extern "C" STDEXPIMP int PASCAL fAltaMovtoCaracteristicasUnidades( long aIdMovimiento,
                                                                   long &aIdMovtoCaracteristicas,
                                                                   LPCARACTERISTICASUNIDADES aCaracteristicasUnidades );

extern "C" STDEXPIMP int PASCAL fAltaMovimientoCaracteristicas_Param(
                                                  char *aIdMovimiento,
                                                  char *aIdMovtoCaracteristicas,
                                                  char *aUnidades,
                                                  char *aValorCaracteristica1,
                                                  char *aValorCaracteristica2,
                                                  char *aValorCaracteristica3 );

extern "C" STDEXPIMP int PASCAL fAltaMovtoCaracteristicasUnidades_Param(
                                                  char *aIdMovimiento,
                                                  char *aIdMovtoCaracteristicas,
                                                  char *aUnidad,
                                                  char *aUnidades,
                                                  char *aUnidadesNC,
                                                  char *aValorCaracteristica1,
                                                  char *aValorCaracteristica2,
                                                  char *aValorCaracteristica3 );

extern "C" STDEXPIMP int PASCAL fAltaMovimientoSeriesCapas( long aIdMovimiento, LPSERIESCAPAS aSeriesCapas );

extern "C" STDEXPIMP int PASCAL fAltaMovimientoSeriesCapas_Param( char *aIdMovimiento,
                                                                  char *aUnidades,
                                                                  char *aTipoCambio,
                                                                  char *aSeries,
                                                                  char *aPedimento,
                                                                  char *aAgencia,
                                                                  char *aFechaPedimento,
                                                                  char *aNumeroLote,
                                                                  char *aFechaFabricacion,
                                                                  char *aFechaCaducidad );

extern "C" STDEXPIMP int PASCAL fCalculaMovtoSerieCapa( long aIdMovimiento );

extern "C" STDEXPIMP int PASCAL fObtieneUnidadesPendientes( char *aConceptoDocto,
                                                            char *aCodigoProducto,
                                                            char *aCodigoAlmacen,
                                                            char *aUnidades );

extern "C" STDEXPIMP int PASCAL fObtieneUnidadesPendientesCarac( char *aConceptoDocto,
                                                                 char *aCodigoProducto,
                                                                 char *aCodigoAlmacen,
                                                                 char *aValorCaracteristica1,
                                                                 char *aValorCaracteristica2,
                                                                 char *aValorCaracteristica3,
                                                                 char *aUnidades );

extern "C" STDEXPIMP int PASCAL fModificaCostoEntrada( char *aIdMovimiento,
                                                       char *aCostoEntrada );



// Funciones de Clientes / Proveedores =============================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdCteProv ( int aIdCteProv );
extern "C" STDEXPIMP int PASCAL fBuscaCteProv   ( char *aCodCteProv );

extern "C" STDEXPIMP int PASCAL fInsertaCteProv ( void );
extern "C" STDEXPIMP int PASCAL fEditaCteProv   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaCteProv  ( void );
extern "C" STDEXPIMP int PASCAL fBorraCteProv   ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionCteProv( void );

extern "C" STDEXPIMP int PASCAL fEliminarCteProv( char *aCodigoCteProv );
extern "C" STDEXPIMP int PASCAL fLeeDatoCteProv ( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoCteProv ( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fAltaCteProv( int &aIdCteProv, LPFREGCTEPROV astCteProv );
extern "C" STDEXPIMP int PASCAL fActualizaCteProv( char *aCodigoCteProv, LPFREGCTEPROV astCteProv );
extern "C" STDEXPIMP int PASCAL fLlenaRegistroCteProv( LPFREGCTEPROV astCteProv, int aEsAlta );

extern "C" STDEXPIMP int PASCAL fPosPrimerCteProv   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoCteProv   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteCteProv( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorCteProv ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFCteProv      ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFCteProv      ( void );
extern "C" STDEXPIMP int PASCAL fInformacionCliente ( char aCodigo[], int &aPermiteCredito,
                                                      double &aLimiteCredito, int &aLimiteDoctosVencidos,
                                                      int &aPermiteExcederCredito, char aFecha[],
                                                      double &aSaldo, double &aSaldoPendiente,
                                                      int &aDoctosVencidos );



// Funciones de Productos ==========================================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdProducto( int aIdProducto );
extern "C" STDEXPIMP int PASCAL fBuscaProducto  ( char *aCodProducto );

extern "C" STDEXPIMP int PASCAL fInsertaProducto( void );
extern "C" STDEXPIMP int PASCAL fEditaProducto  ( void );
extern "C" STDEXPIMP int PASCAL fGuardaProducto ( void );
extern "C" STDEXPIMP int PASCAL fBorraProducto  ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionProducto( void );

extern "C" STDEXPIMP int PASCAL fEliminarProducto( char *aCodigoProducto );
extern "C" STDEXPIMP int PASCAL fLeeDatoProducto( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoProducto( const char *aCampo, char *aValor );
extern "C" STDEXPIMP int PASCAL fSetDescripcionProducto( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fAltaProducto( int &aIdProducto, LPFREGPRODUCTO astProducto );
extern "C" STDEXPIMP int PASCAL fActualizaProducto( char *aCodigoProducto, LPFREGPRODUCTO astProducto );
extern "C" STDEXPIMP int PASCAL fLlenaRegistroProducto( LPFREGPRODUCTO astProducto, int aEsAlta );

extern "C" STDEXPIMP int PASCAL fPosPrimerProducto    ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoProducto    ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteProducto ( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorProducto  ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFProducto       ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFProducto       ( void );

// Funciones de Addendas ===========================================================================
// N.C.143
extern "C" STDEXPIMP int PASCAL fInsertaDatoCompEducativo ( int aIdServicio, int aNumCampo, char *aDato );
// N.C.647
extern "C" STDEXPIMP int PASCAL fInsertaDatoAddendaDocto ( int aIdAddenda, int aIdCatalogo, int aNumCampo, char *aDato );
//N.D. 8808
extern "C" STDEXPIMP int PASCAL fInsertaDatoAddendaMovto ( int aIdAddenda, int aIdCatalogo, int aNumCampo, char *aDato );

extern "C" STDEXPIMP int PASCAL fObtenCeryKey(int aIdFirmarl, char *aRutaKey, char *aRutaCer);
extern "C" STDEXPIMP int PASCAL fObtieneLicencia (char *aCodAcvtiva, char *aCodSitio, char *aSerie, char *aTagVersion);
extern "C" STDEXPIMP int PASCAL fObtienePassProxy( char *aPassProxy );

//N.C.648   (RCVG)
extern "C" STDEXPIMP int PASCAL fTimbraXML( char *aRutaXML,
                                            char *aCodCOncepto,
                                            char *aUUID,
                                            char *aRutaDDA,
                                            char *aRutaResultado,
                                            char *aPass,
                                            char *aRutaFormato );
//NC: 650  (RCVG)
extern "C" STDEXPIMP int PASCAL fTimbraNominaXML( char *aRutaXML,
                                            char *aCodCOncepto,
                                            char *aUUID,
                                            char *aRutaDDA,
                                            char *aRutaResultado,
                                            char *aPass,
                                            char *aRutaFormato );

//NC: 334
extern "C" STDEXPIMP int PASCAL fTimbraComplementoXML( char *aRutaXML,
                                            char *aCodCOncepto,
                                            char *aUUID,
                                            char *aRutaDDA,
                                            char *aRutaResultado,
                                            char *aPass,
                                            char *aRutaFormato,
                                            int aComplemento );


extern "C" STDEXPIMP int PASCAL fTimbraComplementoPagoXML( char *aRutaXML,
                                            char *aCodCOncepto,
                                            char *aUUID,
                                            char *aRutaDDA,
                                            char *aRutaResultado,
                                            char *aPass,
                                            char *aRutaFormato );

//NC: 658  MMEV
extern "C" STDEXPIMP int PASCAL  fCancelaUUID( char *aUUID,
                                               char *aIdDConcepto,
                                               char *aPass );

extern "C" STDEXPIMP int PASCAL  fCancelaNominaUUID( char *aUUID,
                                                     char *aIdDConcepto,
                                                     char *aPass );

extern "C" STDEXPIMP int PASCAL  fCancelaComplementoPagoUUID( char *aUUID,
                                                     char *aIdDConcepto,
                                                     char *aPass );

// Funciones para la cancelacion 33 ================================================================
extern "C" STDEXPIMP int PASCAL  fCancelaUUID33( char *aUUID,
                                                 char *aRFCReceptor,
                                                 double aTotal,
                                                 char *aIdDConcepto,
                                                 char *aPass,
                                                 int &aEstatusCancelacion);

// Funciones para Direcciones ======================================================================
extern "C" STDEXPIMP int PASCAL fBuscaDireccionEmpresa  ( void );
extern "C" STDEXPIMP int PASCAL fBuscaDireccionCteProv  ( char *aCodCteProv, unsigned char aTipoDireccion );
extern "C" STDEXPIMP int PASCAL fBuscaDireccionDocumento( long aIdDocumento, unsigned char aTipoDireccion );

extern "C" STDEXPIMP int PASCAL fInsertaDireccion ( void );
extern "C" STDEXPIMP int PASCAL fEditaDireccion   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaDireccion  ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionDireccion( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoDireccion( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoDireccion( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fAltaDireccion  ( int &aIdDireccion, LPFREGDIRECCION astDireccion );
extern "C" STDEXPIMP int PASCAL fActualizaDireccion( LPFREGDIRECCION astDireccion );
extern "C" STDEXPIMP int PASCAL fLlenaRegistroDireccion( LPFREGDIRECCION astDireccion, int aEsAlta );

extern "C" STDEXPIMP int PASCAL fPosPrimerDireccion   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimaDireccion   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteDireccion( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorDireccion ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFDireccion      ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFDireccion      ( void );


// Funciones de Existencias ========================================================================
extern "C" STDEXPIMP int PASCAL fRegresaExistencia( char *aCodigoProducto,
                                                    char *aCodigoAlmacen,
                                                    char *aAnio,
                                                    char *aMes,
                                                    char *aDia,
                                                    double &aExistencia );

extern "C" STDEXPIMP int PASCAL fRegresaExistenciaCaracteristicas(
                                                  char *aCodigoProducto,
                                                  char *aCodigoAlmacen,
                                                  char *aAnio,
                                                  char *aMes,
                                                  char *aDia,
                                                  char *aValorCaracteristica1,
                                                  char *aValorCaracteristica2,
                                                  char *aValorCaracteristica3,
                                                  double &aExistencia );


// Funciones de Costo Historico ====================================================================
extern "C" STDEXPIMP int PASCAL fRegresaCostoPromedio( char *aCodigoProducto,
                                                       char *aCodigoAlmacen,
                                                       char *aAnio,
                                                       char *aMes,
                                                       char *aDia,
                                                       char *aCostoPromedio );

extern "C" STDEXPIMP int PASCAL fRegresaUltimoCosto( char *aCodigoProducto,
                                                     char *aCodigoAlmacen,
                                                     char *aAnio,
                                                     char *aMes,
                                                     char *aDia,
                                                     char *aUltimoCosto );

extern "C" STDEXPIMP int PASCAL fRegresaCostoEstandar( char *aCodigoProducto,
                                                       char *aCostoEstandar );

extern "C" STDEXPIMP int PASCAL fRegresaCostoCapa( char   *aCodigoProducto,
                                                   char   *aCodigoAlmacen,
                                                   double aUnidades,
                                                   char   *aImporteCosto );


// Funciones de Recosteo de Productos ==============================================================
extern "C" STDEXPIMP int PASCAL fRecosteoProducto( char *aCodigoProducto,
                                                   int  aEjercicio,
                                                   int  aPeriodo,
                                                   char *aCodigoClasificacion1,
                                                   char *aCodigoClasificacion2,
                                                   char *aCodigoClasificacion3,
                                                   char *aCodigoClasificacion4,
                                                   char *aCodigoClasificacion5,
                                                   char *aCodigoClasificacion6,
                                                   char *aNombreBitacora,
                                                   int  aSobreEscribirBitacora ,
                                                   int  aEsCalculoArimetico );


// Funcion para obtener el precio de venta de un producto ==========================================
extern "C" STDEXPIMP int PASCAL fRegresaPrecioVenta( char *aCodigoConcepto,
                                                     char *aCodigoCliente,
                                                     char *aCodigoProducto,
                                                     char *aPrecioVenta );

// Funciones de Concepto Documento =================================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdConceptoDocto ( int aIdConcepto );
extern "C" STDEXPIMP int PASCAL fBuscaConceptoDocto   ( char *aCodConcepto );

extern "C" STDEXPIMP int PASCAL fLeeDatoConceptoDocto( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fEditaConceptoDocto( void );
extern "C" STDEXPIMP int PASCAL fGuardaConceptoDocto( void );
extern "C" STDEXPIMP int PASCAL fSetDatoConceptoDocto( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fRegresPorcentajeImpuesto( int    aIdConceptoDocumento,
                                                           int    aIdClienteProveedor,
                                                           int    aIdProducto,
                                                           double &aPorcentajeImpuesto );

extern "C" STDEXPIMP int PASCAL fPosPrimerConceptoDocto   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimaConceptoDocto   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteConceptoDocto( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorConceptoDocto ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFConceptoDocto      ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFConceptoDocto      ( void );


// Funciones de Parametros =========================================================================
extern "C" STDEXPIMP int PASCAL fLeeDatoParametros( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fEditaParametros( void );
extern "C" STDEXPIMP int PASCAL fGuardaParametros( void );
extern "C" STDEXPIMP int PASCAL fSetDatoParametros( const char *aCampo, char *aValor );

// Funciones del Catálogo de Clasificaciones =======================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdClasificacion ( int aIdClasificacion );
extern "C" STDEXPIMP int PASCAL fBuscaClasificacion   ( int aClasificacionDe, int aNumClasificacion );

// NOTA: Las clasificaciones no se pueden eliminar
extern "C" STDEXPIMP int PASCAL fEditaClasificacion   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaClasificacion  ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionClasificacion( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoClasificacion( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoClasificacion( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fActualizaClasificacion( int  aClasificacionDe, int  aNumClasificacion,
                                                         char *aNombreClasificacion );

extern "C" STDEXPIMP int PASCAL fPosPrimerClasificacion( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoClasificacion( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteClasificacion( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorClasificacion( void );
extern "C" STDEXPIMP int PASCAL fPosBOFClasificacion( void );
extern "C" STDEXPIMP int PASCAL fPosEOFClasificacion( void );


// Funciones del Catálogo de Valores de Clasificaciones ============================================
extern "C" STDEXPIMP int PASCAL fBuscaIdValorClasif( int aIdValorClasif );
extern "C" STDEXPIMP int PASCAL fBuscaValorClasif( int  aClasificacionDe, int  aNumClasificacion,
                                                   char *aCodValorClasif );

extern "C" STDEXPIMP int PASCAL fInsertaValorClasif ( void );
extern "C" STDEXPIMP int PASCAL fEditaValorClasif   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaValorClasif  ( void );
extern "C" STDEXPIMP int PASCAL fBorraValorClasif   ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionValorClasif( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoValorClasif( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoValorClasif( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fAltaValorClasif     ( int &aIdValorClasif, LPFREGVALORCLASIFICACION astValorClasif );
extern "C" STDEXPIMP int PASCAL fActualizaValorClasif( char *aCodigoValorClasif, LPFREGVALORCLASIFICACION astValorClasif );
extern "C" STDEXPIMP int PASCAL fEliminarValorClasif ( int  aClasificacionDe, int  aNumClasificacion,
                                                       char *aCodigoValorClasif );
extern "C" STDEXPIMP int PASCAL fLlenaRegistroValorClasif( LPFREGVALORCLASIFICACION astValorClasif );

extern "C" STDEXPIMP int PASCAL fPosPrimerValorClasif   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoValorClasif   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteValorClasif( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorValorClasif ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFValorClasif      ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFValorClasif      ( void );


// Funciones del Catálogo de Unidades de Peso y Medida =============================================
extern "C" STDEXPIMP int PASCAL fBuscaIdUnidad( int aIdUnidad );
extern "C" STDEXPIMP int PASCAL fBuscaUnidad  ( char *aNombreUnidad );

extern "C" STDEXPIMP int PASCAL fInsertaUnidad  ( void );
extern "C" STDEXPIMP int PASCAL fEditaUnidad    ( void );
extern "C" STDEXPIMP int PASCAL fGuardaUnidad   ( void );
extern "C" STDEXPIMP int PASCAL fBorraUnidad    ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionUnidad( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoUnidad( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoUnidad( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fAltaUnidad     ( int &aIdUnidad, LPFREGUNIDAD astUnidad );
extern "C" STDEXPIMP int PASCAL fActualizaUnidad( char *aNombreUnidad, LPFREGUNIDAD astUnidad );
extern "C" STDEXPIMP int PASCAL fEliminarUnidad ( char *aNombreUnidad );
extern "C" STDEXPIMP int PASCAL fLlenaRegistroUnidad( LPFREGUNIDAD astUnidad );

extern "C" STDEXPIMP int PASCAL fPosPrimerUnidad    ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoUnidad    ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteUnidad ( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorUnidad  ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFUnidad       ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFUnidad       ( void );


// Funciones del Catálogo de Agentes ===============================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdAgente  ( int aIdAgente );
extern "C" STDEXPIMP int PASCAL fBuscaAgente    ( char *aCodigoAgente );

extern "C" STDEXPIMP int PASCAL fInsertaAgente  ( void );
extern "C" STDEXPIMP int PASCAL fEditaAgente    ( void );
extern "C" STDEXPIMP int PASCAL fGuardaAgente   ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionAgente( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoAgente  ( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoAgente  ( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fPosPrimerAgente    ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoAgente    ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteAgente ( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorAgente  ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFAgente       ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFAgente       ( void );


// Funciones del Catálogo de Almacenes =============================================================
extern "C" STDEXPIMP int PASCAL fBuscaIdAlmacen ( int aIdAlmacen );
extern "C" STDEXPIMP int PASCAL fBuscaAlmacen   ( char *aCodigoAlmacen );

extern "C" STDEXPIMP int PASCAL fInsertaAlmacen ( void );
extern "C" STDEXPIMP int PASCAL fEditaAlmacen   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaAlmacen ( void );
extern "C" STDEXPIMP int PASCAL fCancelarModificacionAlmacen( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoAlmacen ( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoAlmacen ( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fPosPrimerAlmacen   ( void );
extern "C" STDEXPIMP int PASCAL fPosUltimoAlmacen   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteAlmacen( void );
extern "C" STDEXPIMP int PASCAL fPosAnteriorAlmacen ( void );
extern "C" STDEXPIMP int PASCAL fPosBOFAlmacen      ( void );
extern "C" STDEXPIMP int PASCAL fPosEOFAlmacen      ( void );

//__________________________________________________________________________________________________

// Funciones del Catálogo de Movimientos Contables =============================================================
extern "C" STDEXPIMP int PASCAL fEditaMovtoContable   ( void );
extern "C" STDEXPIMP int PASCAL fGuardaMovtoContable  ( void );

extern "C" STDEXPIMP int PASCAL fLeeDatoMovtoContable ( const char *aCampo, char *aValor, int aLen );
extern "C" STDEXPIMP int PASCAL fSetDatoMovtoContable ( const char *aCampo, char *aValor );

extern "C" STDEXPIMP int PASCAL fPosPrimerMovtoContable   ( void );
extern "C" STDEXPIMP int PASCAL fPosSiguienteMovtoContable( void );
extern "C" STDEXPIMP int PASCAL fPosEOFMovtoContable      ( void );

//__________________________________________________________________________________________________
extern "C" STDEXPIMP int PASCAL fEliminarRelacionesCFDIs  ( char *aConcepto, char *aSerie, char *aFolio );
extern "C" STDEXPIMP int PASCAL fAgregarRelacionCFDI      ( char *aConcepto, char *aSerie, char *aFolio, char aTipoRelacion[4], char *aConceptoRelacionar, char *aSerieRelacionar, char *aFolioRelacionar );
extern "C" STDEXPIMP int PASCAL fAgregarRelacionCFDI2     ( char *aConcepto, char *aSerie, char *aFolio, char aTipoRelacion[4], char aUUID[] );
extern "C" STDEXPIMP int PASCAL fRecuperarRelacionesCFDIs ( char *aConcepto, char *aSerie, char *aFolio, char aTipoRelacion[4], char aUUIDs[256], char aRutaNombreArchivoInfo[] );


//__________________________________________________________________________________________________

class TParametroAPI;

class TClienteProveedorAPI;
class TProductoAPI;
class TAgenteAPI;
class TAlmacenAPI;
class TMovimientoContableAPI;

class TUnidadAPI;
class TClasificacionAPI;
class TValorClasificacionAPI;
class TDireccionAPI;
class TProductoIdentificadorAPI;

class TDocumentoAPI;
class TMovimientoAPI;
class TSaldarAPI;
class TExistenciaAPI;
class TCostoHistoricoAPI;
class TConceptoDocumentoAPI;
class TRecosteoAPI;
class TCapaAPI;
class TPrepolizaAPI;
class TCausacionIvaSDK;
class TMonedaAPI;
// N.C.143
class TEmisionAddendaAPI;

extern "C" STDEXPIMP TParametroAPI             *gPtrTParametroAPI;

extern "C" STDEXPIMP TClienteProveedorAPI      *gPtrTClienteProveedorAPI;
extern "C" STDEXPIMP TProductoAPI              *gPtrTProductoAPI;
extern "C" STDEXPIMP TAgenteAPI                *gPtrTAgenteAPI;
extern "C" STDEXPIMP TAlmacenAPI               *gPtrTAlmacenAPI;
extern "C" STDEXPIMP TMovimientoContableAPI    *gPtrTMovimientoContableAPI;

extern "C" STDEXPIMP TUnidadAPI                *gPtrTUnidadAPI;
extern "C" STDEXPIMP TClasificacionAPI         *gPtrTClasificacionAPI;
extern "C" STDEXPIMP TValorClasificacionAPI    *gPtrTValorClasificacionAPI;
extern "C" STDEXPIMP TDireccionAPI             *gPtrTDireccionAPI;
extern "C" STDEXPIMP TProductoIdentificadorAPI *gPtrTProductoIdentificadorAPI;

extern "C" STDEXPIMP TMonedaAPI                *gPtrTMonedaAPI;
extern "C" STDEXPIMP TDocumentoAPI             *gPtrTDocumentoAPI;
extern "C" STDEXPIMP TMovimientoAPI            *gPtrTMovimientoAPI;
extern "C" STDEXPIMP TSaldarAPI                *gPtrTSaldarAPI;
extern "C" STDEXPIMP TExistenciaAPI            *gPtrTExistenciaAPI;
extern "C" STDEXPIMP TCostoHistoricoAPI        *gPtrTCostoHistoricoAPI;
extern "C" STDEXPIMP TConceptoDocumentoAPI     *gPtrTConceptoDocumentoAPI;
extern "C" STDEXPIMP TRecosteoAPI              *gPtrTRecosteoAPI;
extern "C" STDEXPIMP TCapaAPI                  *gPtrTCapaAPI;
extern "C" STDEXPIMP TPrepolizaAPI             *gPtrTPrepolizaAPI;
extern "C" STDEXPIMP TCausacionIvaSDK          *gPtrTCausacionIVA;
// N.C.143
extern "C" STDEXPIMP TEmisionAddendaAPI        *gPtrTEmisionAddendaAPI;

#endif //MGW_SDK


//Definiciones de apuntadores a funciones de la DLL Runtime.dll para obtener información de la licencia
typedef  int (__stdcall *ptr_RTInit)(char* aProductName, __int64 aVersionTag);
typedef  int (__stdcall *ptr_RTDone)();
typedef  int (__stdcall *ptr_RTQuery)(char* aBuf);
typedef  int (__stdcall *ptr_RTQueryLicenseInfo)(bool* aIsEvaluation, bool* aIsTemporary, UINT* aMaxUsers,
                                      UINT* aMaxDays, UINT* aMaxRuns, UINT* aMaxUsageHours,
                                      UINT* aMaxToken1, UINT* aMaxToken2,
                                      int* aExtra1, int* aExtra2);

