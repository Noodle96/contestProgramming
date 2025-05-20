/*
==========================================================
|  Archivo       : Internal.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-17 14:27
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
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
vector<vector<int>> M;
void solve(){
    int n; cin>>n;
    int total = n;
    M.assign(n,vector<int>(5,0));
    int currentRow = 0;
    array<int, 3> arr_ans;
    arr_ans.fill(0);
    vector<int> currentRowBigger(5,0);
    while(total--){
        for(int e = 0 ;e < 5 ; e++){
            int a; cin>> M[currentRow][e];
        }
        if(currentRow == 0){
            for(int e  = 0 ;e <5 ; e++){
                currentRowBigger[e] = M[0][e];
            }
            arr_ans[2]++; // la primera fila siempre es la mejor
            currentRow++;
            continue;
        }
        //contar
        int contador = 0;
        for(int e = 0 ;e < 5 ; e++){
            if(M[currentRow][e] > currentRowBigger[e]){
                contador++;
                currentRowBigger[e] = M[currentRow][e];
            }
        }
        if(contador == 5) arr_ans[2]++;
        else if(contador == 4) arr_ans[1]++;
        else if(contador == 3) arr_ans[0]++;
        currentRow++;
        // test
        // cout << "current iterator\n";
        // cout << arr_ans[0] << " " << arr_ans[1] << " " << arr_ans[2] << "\n";
        
    }
    cout << arr_ans[0] << " " << arr_ans[1] << " " << arr_ans[2] << "\n";

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