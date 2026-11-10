# Progreso: retrofit de plantilla en CDFC

Seguimiento de la tarea de agregar la plantilla con "Tópicos utilizados" a los
`.cpp` de `CDFC/` que todavía no la tienen, para alimentar el índice generado
por `tools/gen_index.py`. Se avanza **de mayor a menor dificultad** (2200 →
800), unas pocas carpetas por sesión, hasta que se indique parar.

## Convenciones acordadas

- Plantilla estándar (ver `CDFC/1600/*.cpp` como referencia ya completa).
- Tópicos siempre en inglés, estilo tags de Codeforces (ej. `binary search`,
  `segment tree`), no texto compuesto con `:` (evita fragmentar el índice).
- Tópicos de un mismo problema que requieren más especificidad van como
  líneas separadas (ej. `shortest path` + `dijkstra`, no `shortest path:
  dijkstra`).
- Se excluyen del índice/tabla de tópicos: `training` y la etiqueta de
  dificultad `*NNNN` (se siguen escribiendo en el `.cpp` por consistencia con
  la plantilla, pero el generador los filtra).
- Para el campo `Fecha` de archivos retrofitteados (que no la tenían), se usa
  la fecha real del primer commit: `git log --follow --diff-filter=A
  --format="%ad" --date=format:"%Y-%m-%d %H:%M" -- <archivo>`. Esto es porque
  al editar el archivo hoy, la columna "Last commit date" de GitHub mostrará
  la fecha de hoy — la fecha real queda preservada dentro del propio archivo.
- `input.txt`, `output.txt`, `a.out` se ignoran (ya están en `.gitignore`,
  y el generador solo escanea `*.cpp`).
- Alcance: este sistema (plantilla + índice + hook) aplica **solo a `CDFC/`**
  por ahora. Carpetas vecinas (`CSES`, `uva`, `vjudge`, etc.) usan otras
  convenciones y no se tocan.

## Infraestructura ya construida

- `tools/gen_index.py` — genera el `README.md` de una carpeta de dificultad.
  Formato: tabla "Detalle por problema" primero, tabla "Índice por tópico"
  después. Uso manual: `python3 tools/gen_index.py CDFC/<dificultad>`.
- `scripts/hooks/pre-commit` — hook versionado que detecta `.cpp` en staging
  dentro de `CDFC/<dificultad>/`, regenera el `README.md` correspondiente y
  lo agrega al mismo commit. Activado vía `git config core.hooksPath
  scripts/hooks` (ya configurado en esta máquina; en un clon nuevo hay que
  volver a correr ese comando).
- Falta: `CDFC/README.md` (guía central explicando todo esto para lectura
  humana).

## Estado por carpeta (plantilla completa = todos los .cpp con el bloque de tópicos)

| Carpeta | Estado | Notas |
|---|---|---|
| 2200 | ✅ completo | 1/1 archivo |
| 1900 | ✅ completo | 4/4 archivos |
| 1800 | ✅ completo | 4/4 archivos |
| 1700 | ✅ completo | 4/4 archivos |
| 1600 | ✅ completo | 5/5 archivos |
| 1500 | ✅ completo | 32/32 (se borró test.cpp, no trackeado) |
| 1400 | ✅ completo | 24/24 archivos |
| 1300 | ✅ completo | 38/38 archivos |
| 1200 | ✅ completo | 35/35 archivos |
| 1100 | ⏳ pendiente | 7/28 con plantilla |
| 1000 | ⏳ pendiente | 2/30 con plantilla |
| 900 | ⏳ pendiente | 0/21 con plantilla |
| 800 | ⏳ pendiente | ~6/100 con plantilla |

## Normalización de tópicos antiguos (decisión tomada: arreglar sobre la marcha)

Desde `1900` se viene encontrando que archivos antiguos ya con plantilla
tienen tópicos mal formados, que fragmentarían el índice si no se corrigen:
formato compuesto con `:`, mayúsculas inconsistentes, separadores raros
(`->`, `|`, comas), términos en español, mismo concepto con nombres
distintos (`bit`/`bruteforce` vs `fenwick tree`/`brute force`), tags que
faltan (`training`/`*NNNN`), y hasta un header copiado con el nombre y
dificultad de otro archivo (`D2_Magic_Powderr.cpp` tenía el header de
`D1_Magic_Powder.cpp`). Se corrige cada caso al llegar a su carpeta en el
orden descendente — ya resuelto en 1900, 1800, 1700, 1500 (1600 no tenía
casos). Carpetas que aún faltan y ya se sabe que tienen casos: **1400,
1300, 1200, 1000** (CDFC-D2 queda fuera de alcance, no es carpeta de
dificultad).

## Próximo paso al reanudar

Seguir en orden descendente desde la primera carpeta marcada ⏳ pendiente
(actualmente: **1100**). Regenerar el `README.md` de cada carpeta con
`tools/gen_index.py` al terminarla (o dejar que el hook lo haga al commitear).

Nota: `CDFC/1800/primeFactorization.cpp` no sigue el patrón de nombre de
problema de CF y tiene atribución de GeeksforGeeks en el código — se le puso
plantilla igual (training, *1800, math, number theory) sin confirmación
explícita de Russell sobre si debería tratarse distinto. Revisar si hace
falta revertir ese criterio.
