/*
==========================================================
|  Archivo       : Split.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-07 17:02
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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
    int n;
    cin >> n;
    vector<string> W(n);
    for(int i = 0; i < n; ++i)
        cin >> W[i];

    // clave = L + "|" + pos + "|" + min(A,B) + "|" + max(A,B)
    unordered_map<string,int> pistaCount;
    pistaCount.reserve(n * 2);

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if (W[i].size() != W[j].size()) 
                continue;
            int L = W[i].size();
            int first = -1, second = -1, diffs = 0;
            for(int k = 0; k < L && diffs <= 2; ++k){
                if (W[i][k] != W[j][k]) {
                    if (diffs == 0) first = k;
                    else if (diffs == 1) second = k;
                    ++diffs;
                }
            }
            if (diffs == 2 && second == first + 1) {
                string A = W[i].substr(first, 2);
                string B = W[j].substr(first, 2);
                string a = min(A,B), b = max(A,B);
                // Incluimos longitud y posición en la clave
                string key = to_string(L) + "|" 
                           + to_string(first) + "|" 
                           + a + "|" + b;
                ++pistaCount[key];
            }
        }
    }
    // cout << "print map: " << endl;
    // for (const auto &kv : pistaCount) {
    //     cout << kv.first << " -> " << kv.second << endl;
    // }cout << endl;
    int answer = 0;
    for (auto &kv : pistaCount)
        if (kv.second == 1)
            ++answer;

    cout << answer << "\n";
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