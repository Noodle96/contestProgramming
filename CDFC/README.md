# CDFC — índice de problemas por tópico

Cada subcarpeta de `CDFC/` corresponde a una dificultad de Codeforces
(`800`, `900`, ..., `2200`). Dentro de cada una, un `README.md` se genera
automáticamente con dos tablas: los problemas de esa carpeta con sus
tópicos, y un índice inverso de tópico → problemas. El objetivo es poder
responder "¿qué problemas de *1600 usé binary search?" sin tener que abrir
archivo por archivo.

Este sistema aplica **solo a `CDFC/`**. Carpetas vecinas (`CSES`, `uva`,
`vjudge`, etc.) usan otras convenciones y no se tocan.

## 1. La plantilla

Cada `.cpp` debe tener este bloque de comentario antes de `#include`:

```cpp
/*
==========================================================
|  Archivo       : C_Hamburgers.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-09 14:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1600
|  - binary search
==========================================================
*/
```

Reglas para la lista de tópicos:

- **Tags planos, uno por línea**, en inglés, estilo Codeforces (`binary
  search`, `segment tree`, `dfs and similar`). Nunca compuestos con `:`
  (ej. `shortest path: dijkstra`) — eso fragmenta el índice generado, que
  agrupa por coincidencia exacta de texto.
- Si un problema necesita más especificidad, el tópico extra va en **su
  propia línea** (`shortest path` + `dijkstra`, no combinados). El
  problema aparecerá repetido bajo ambas entradas en el índice — es
  intencional, permite buscar por la categoría amplia o la específica.
- `training` y la etiqueta de dificultad `*NNNN` siempre se escriben en el
  `.cpp` (son parte de la plantilla), pero el generador las excluye del
  índice porque no aportan señal para filtrar.
- Minúsculas siempre, sin abreviar de forma inconsistente (`dfs and
  similar`, no `DFS`/`Dfs`). Mismo concepto = mismo texto exacto en todos
  los archivos (ej. siempre `fenwick tree`, nunca `bit` en unos y `fenwick
  tree` en otros).
- Si un archivo es viejo y nunca tuvo plantilla, usa como `Fecha` la del
  **primer commit real**, no la de hoy:
  ```bash
  git log --follow --diff-filter=A --format="%ad" \
    --date=format:"%Y-%m-%d %H:%M" -- <archivo>
  ```
  Esto importa porque GitHub muestra en "Last commit date" la fecha del
  commit más reciente que tocó el archivo — si lo editas hoy para
  agregarle la plantilla, esa columna mostrará hoy sin importar qué
  pongas. La fecha real queda preservada dentro del propio archivo.

`input.txt`, `output.txt`, `a.out` no necesitan nada — ya están en
`.gitignore` y el generador solo escanea `*.cpp`.

## 2. El generador (`tools/gen_index.py`)

Lee todos los `.cpp` de una carpeta, extrae su bloque de tópicos, y escribe
el `README.md` de esa carpeta con:

1. **Detalle por problema** — una tabla con cada archivo y sus tópicos.
2. **Índice por tópico** — una tabla con cada tópico y los problemas que lo
   usan (excluyendo `training` y `*NNNN`).

Uso manual:

```bash
python3 tools/gen_index.py CDFC/<dificultad>
```

Solo requiere Python 3 estándar (sin dependencias externas).

## 3. El hook automático

`scripts/hooks/pre-commit` corre antes de cada `git commit`. Si detecta
`.cpp` en staging dentro de `CDFC/<dificultad>/`, corre el generador para
esa carpeta y agrega el `README.md` resultante al mismo commit — sin que
tengas que hacer nada manualmente.

## 4. Configurar esto en una máquina nueva (clon del repo)

Después de `git clone`, correr **una sola vez**:

```bash
git config core.hooksPath scripts/hooks
```

Esto es necesario porque `.git/config` es local a cada copia del repo y
nunca se clona junto con el historial — git no sabe por defecto que los
hooks viven en `scripts/hooks/` en vez de `.git/hooks/`. El script del hook
sí viaja con el repo (es un archivo normal, versionado), así que no hay que
copiarlo ni darle permisos de nuevo.

Después de ese comando, cada commit que toque `CDFC/` se comporta igual que
en cualquier otra máquina.

## 5. Estado del retrofit

El progreso de agregar/corregir plantillas en archivos viejos está en
[RETROFIT_PROGRESS.md](RETROFIT_PROGRESS.md) — esa es la lista de qué
carpetas ya están completas y cuáles faltan.
