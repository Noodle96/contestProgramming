/*
==========================================================
|  Archivo       : B_Strange_Machine.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-24 10:10
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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
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
int bitlen_unsigned(unsigned long long n){
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n,q; cin >> n >> q;
    string str; cin >> str;
    bool tipoB = false;
    for(int i = 0 ; i < n; i++){
        if(str[i] == 'B') tipoB = true;
    }

    auto procesar = [&](int a){
        int ans = 0;
        // Si es del tupo b proceso secuencialmente cada maquina
        if(tipoB){
            while(a > 0){
                for(int t: str){
                    if(t == 'A'){
                        a--;
                        ans++;
                        if(a == 0) return ans;
                    }else{
                        if(a % 2 == 0){
                            a /= 2;
                            ans++;
                            if(a == 0) return ans;
                        }else{
                            a++;
                            a /= 2;
                            a--;
                            ans++;
                            if(a == 0) return ans;
                        }
                    }
                }
            }

        }
        else{ // Es del tipo A es decir siempre reduce en 1
            return a;
        }
        return -1; // Nunca deberia llegar aqui
    };

    while(q--){
        int a; cin >> a;
        int ans = procesar(a);
        cout << ans << endl;
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