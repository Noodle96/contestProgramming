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

Cada `.cpp` nuevo arranca de este template completo (bloque de comentario
+ boilerplate de siempre):

```cpp
/*
==========================================================
|  Archivo       : A_cheapTravel.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-10 18:30
|--------------------------------------------------------
|  Tópicos utilizados:
|  - sorting
|  - training
|  - greedy
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const int INF = 1e9;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}

ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int bitlen_unsigned(unsigned long long n) {
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
```

Lo único que importa para el índice generado es el bloque de comentario del
inicio — el resto del boilerplate (`gcd`, `floordiv`, `ceildiv`, etc.) es
solo utilidades que el generador ignora por completo.

Este template completo está disponible como snippet de VS Code en
[`.vscode/cpp.code-snippets`](../.vscode/cpp.code-snippets) — escribe
`cpptemplate` y Tab en un archivo `.cpp` para insertarlo. El snippet llena
automáticamente `Archivo` (nombre real del archivo) y `Fecha` (fecha/hora
actual), y deja los 3 tópicos como campos editables con Tab.

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
