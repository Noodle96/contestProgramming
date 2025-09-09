/*
==========================================================
|  Archivo       : C_any.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-17 13:31
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Greedy
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

bool allOne(vector<ll> &vec){
    for(int e = 0 ; e < vec.size(); e++){
        if(vec[e] != 1) return false;
    }
    return true;
}

void solve(){
    int n,m; cin>>n>>m;
    ll maximoMatriz = -INF;
    vector< vector<ll> > matriz(n, vector<ll>(m));
    for(int e = 0;e < n ; e++){
        for(int j = 0 ; j < m; j++){
            cin>>matriz[e][j];
            maximoMatriz = max(maximoMatriz, matriz[e][j]);
        }
    }
    // cout << "matriz: " << endl;
    // for(int e = 0;e < n ; e++){
    //     for(int j = 0 ; j < m; j++){
    //         cout << matriz[e][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "maximoMatriz: " << maximoMatriz << endl;
    // recorrerFilas
    vector<ll> filas_len(n,0), columnas_len(m,0);
    map<ll, set<pair<ll,ll> >> map_filas, map_columnas;
    for(int e = 0;e < n ; e++){
        for(int j = 0 ; j < m; j++){
            if(matriz[e][j] == maximoMatriz){
                filas_len[e]++;
                map_filas[e].insert({e,j});
            }
        }
    }
    // cout << "map_filas: " << endl;
    // for(auto it = map_filas.begin() ; it != map_filas.end(); it++){
    //     cout << "Fila " << it->first << ": ";
    //     for(auto [e,j] : it->second){
    //         cout << "(" << e << "," << j << ") ";
    //     }
    //     cout << endl;
    // }
    for(int j = 0 ; j < m; j++){
        for(int e = 0 ; e < n; e++){
            if(matriz[e][j] == maximoMatriz){
                columnas_len[j]++;
                map_columnas[j].insert({e,j});
            }
        }
    }
    // cout << "map_columnas: " << endl;
    // for(auto it = map_columnas.begin() ; it != map_columnas.end(); it++){
    //     cout << "Columna " << it->first << ": ";
    //     for(auto [e,j] : it->second){
    //         cout << "(" << e << "," << j << ") ";
    //     }
    //     cout << endl;
    // }

    if(n == 1 || m == 1){
        // cout << "ans: "<<maximoMatriz -1 << endl;
        cout <<maximoMatriz -1 << endl;

        return;
    }
    
    if(  allOne(filas_len)){
        // cout << "all one file" << endl;
        // analizamos a las columnas
        // encontrar el indice que tiene mayor veces el maximoTotal
        ll maximoLen = -1, indexLen = -1;
        for(int j = 0 ;j < m  ; j++){
            if(columnas_len[j] > maximoLen){
                maximoLen = columnas_len[j];
                indexLen = j;
            }
        }
        // cout << "maximoLen: " << maximoLen << " indexLen: " << indexLen << endl;
        // eliminar todas los (i,j) de filas que estan en la columna maximoLen
        auto pairs = map_columnas[indexLen];
        for(auto [e,j]: pairs){
            map_filas[e].erase({e,j});
        }
        // ahora analizamos las filas restantes
        ll diferentZero = 0;
        for(auto it = map_filas.begin() ; it != map_filas.end(); it++){
            // cout << it->second.size() << " ";
            if(it->second.size() != 0) diferentZero++;
        }
        // cout << endl;
        // cout << "diferentZero: " << diferentZero << endl;

        if(diferentZero >= 2){
            cout <<maximoMatriz << endl;
            // cout << "ans: " <<maximoMatriz << endl;

        }else{
            cout <<maximoMatriz -1<< endl;
            // cout << "ans: " <<maximoMatriz -1<< endl;
        }
    }else{
        // analizamos a las filas
        ll indexLen = -1, maximoLen = -1;
        for(int e = 0 ;e < n ; e++){
            if(filas_len[e] > maximoLen){
                maximoLen = filas_len[e];
                indexLen = e;
            }
        }
        // cout << "maximoLen: " << maximoLen <<  " indexLen: " << indexLen <<endl;
        auto pairs = map_filas[indexLen];
        for(auto [e,j]: pairs){
            map_columnas[j].erase({e,j});
        }
        ll diferentZero = 0;
        for(auto it = map_columnas.begin() ; it != map_columnas.end(); it++){
            // cout << it->second.size() << " ";
            if(it->second.size() != 0) diferentZero++;
        }
        // cout << endl;
        // cout << "diferentZero: " << diferentZero << endl;
        if(diferentZero >= 2){
            // cout << "ans: " <<maximoMatriz  << endl;
            cout <<maximoMatriz  << endl;

        }else{
            // cout << "ans: " << maximoMatriz -1<< endl;
            cout << maximoMatriz -1<< endl;
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
    int t; cin>>t;
    while(t--) solve();
    return 0;
}