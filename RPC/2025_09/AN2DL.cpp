/*
==========================================================
|  Archivo       : AN2DL.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-16
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Sliding Window Maximum
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
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

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

// Sliding window máximo en 1D
void sliding_max_1D(const vector<int>& arr, int k, vector<int>& res) {
    deque<int> dq;
    int n = arr.size();
    res.resize(n - k + 1);

    for (int i = 0; i < n; i++) {
        // Eliminar los índices que salen de la ventana
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // Eliminar los menores al actual (mantener en orden descendente)
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Guardar el máximo actual
        if (i >= k - 1)
            res[i - k + 1] = arr[dq.front()];
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    int r, s;
    cin >> r >> s;

    int new_n = n - r + 1;
    int new_m = m - s + 1;

    // Paso 1: máximos horizontales
    vector<vector<int>> rowMax(n, vector<int>(new_m));
    for (int i = 0; i < n; i++) {
        vector<int> res;
        sliding_max_1D(matrix[i], s, res);
        rowMax[i] = res;
    }

    // Paso 2: máximos verticales
    vector<vector<int>> result(new_n, vector<int>(new_m));
    for (int j = 0; j < new_m; j++) {
        vector<int> col(n);
        for (int i = 0; i < n; i++)
            col[i] = rowMax[i][j];

        vector<int> res;
        sliding_max_1D(col, r, res);

        for (int i = 0; i < new_n; i++)
            result[i][j] = res[i];
    }

    // Imprimir resultado
    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_m; j++) {
            cout << result[i][j] << (j + 1 == new_m ? '\n' : ' ');
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}
