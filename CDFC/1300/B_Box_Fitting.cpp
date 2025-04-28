/*
==========================================================
|  Archivo       : B_Box_Fitting.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-28 11:17
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BinarySearch
|  - DataStructures: Multiset
|  - Greedy
|  - *1300
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
    int n, W;
    cin>>n>>W;
    multiset<int> s;
    for(int e = 0 ;e <n ; e++){
        int w_i; cin>>w_i;
        s.insert(w_i);
    }
    //print s
    // for(auto e: s) cout << e << " ";
    // cout << endl;
    // return;
    int w_restante = W;
    int height = 0;
    while(!s.empty()){
        height++;
        w_restante = W;
        // cout << "w_restante: " << w_restante << " height: " << height << endl;
        while(1){
            // cout << "\tw_restante: " << w_restante << " height: " << height << endl;
            if(s.empty()) break;
            auto last = s.end();
            last--;
            if(w_restante >= *last){
                w_restante -= *last;
                s.erase(last);

            }else{
                // seleccionamos el mayor elemento que no exceda el peso restante
                auto first_R = s.lower_bound(w_restante);
                // Caso cuando sea mayor estrictamente
                if(*first_R > w_restante){
                    auto first = s.begin();
                    // caso cuando first_R es justo el primero,
                    // ya no puedo retroceder
                    if(first == first_R){
                        // nothing to do
                        w_restante = 0; // forzar el break
                    }else{
                        --first_R;
                        w_restante -= *first_R;
                        s.erase(first_R);
                    }
                }
                // caso cuando sea igual estrictamente
                else{
                    w_restante -= *first_R;
                    s.erase(first_R);
                }
                if(w_restante == 0) break;
            }
        }
    }
    cout << height << endl;
}
void solve2(){
    vector<int> a = {10, 10, 30, 30, 50};
    auto upperBound = upper_bound(all(a), 4);
    auto lowerBound = lower_bound(all(a), 4);

    auto totalUpper = upperBound - a.begin();
    auto totalLower = lowerBound - a.begin();

    cout << totalUpper << " " << totalLower << endl;
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