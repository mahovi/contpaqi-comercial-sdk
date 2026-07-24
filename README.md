# contpaqi-comercial-sdk (Claude Code skill)

Skill de Claude Code con conocimiento validado en producción sobre el SDK
de CONTPAQi Comercial (`MGWServicios.dll`) -- secuencia de inicialización
correcta (incluyendo un paso que el manual oficial del proveedor no
documenta), el patrón "Bajo Nivel" para leer/escribir cualquier entidad, y
cómo interpretar los mensajes de error reales del SDK en vez de tomarlos
literal.

## Por qué existe

El manual oficial del SDK está incompleto y trae inconsistencias. Sin este
conocimiento, es fácil confundir "no conozco el SDK todavía" con "esto está
roto" -- ya pasó, costó horas de diagnóstico real contra un servidor en
producción.

## Uso

Copiar este directorio a donde Claude Code busque skills del proyecto (o
instalarlo como plugin/skill según corresponda) para que quede disponible
al escribir o debuggear integraciones contra este SDK.

- `SKILL.md` -- la guía principal.
- `reference.md` -- declaraciones P/Invoke (C#) ya funcionando, patrón de
  transferencia de archivos por WinRM, y comando de compilación.

No asume ningún proyecto específico -- es reutilizable para cualquier
integración contra CONTPAQi Comercial vía su SDK.
