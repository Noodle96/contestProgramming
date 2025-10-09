/*
==========================================================
|  Archivo       : B_Abrahams_Great_Escape.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-05 11:59
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div2
|  - implementation
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

void solve(){
    int n,k; cin >> n >> k;
    // cout << "caso n = " << n << " k = " << k << endl;
    if(k == n*n - 1){
        cout << "NO" << endl;
        return;
    }
    vector<vector<char>> grid_ans(n, vector<char>(n, '.'));
    cout << "YES" << endl;
    int fillFilas = k/n;
    int columnas_reatantes = k%n;
    int i = 0;
    for(; i < fillFilas; i++){
        for(int j = 0 ; j < n; j++){
            grid_ans[i][j] = 'U';
        }
    }
    //i actualizado en la siguiete fila
    for(int j = 0; j < columnas_reatantes; j++){
        grid_ans[i][j] = 'U';
    }
    if(n - columnas_reatantes == 1){
        grid_ans[i][n-1] = 'D';
    }else{
        if(i < n){
            for(int j = columnas_reatantes; j < n; j++){
                if(j == n-1) grid_ans[i][j] = 'L';
                else grid_ans[i][j] = 'R';
            }
        }
       
    }
    // actualizamos para la siguiebte fila;
    i++;
    for(; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == n-1) grid_ans[i][j] = 'L';
            else grid_ans[i][j] = 'R';
        }
    }

    // prit grid
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ;j < n ; j++){
            cout << grid_ans[i][j];
        }cout << endl;
    }



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}