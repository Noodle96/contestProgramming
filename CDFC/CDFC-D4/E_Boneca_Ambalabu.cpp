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

void solve2(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int e = 0 ; e < n; e++){
        cin>>vec[e];
        cout << "work in " << vec[e] << endl;
        for(int j = 0 ;j < 31 ; j++){
            cout << (vec[e] >> j) << endl;
        }
    }
}
void solve() {
    int n; 
    cin >> n;
    vector<ll> v(n,0);
    vector<ll> bitSetCnt(30, 0);
    /*
        En este primer bucle guardamos en bitSetCnt[i], cuantos elementos(n)
        tiene el i-esimo bit encendido.
        v[i] = 10 => 1010
        bitSetCnt[0] += 0
        bitSetCnt[1] += 1
        bitSetCnt[2] += 0
        bitSetCnt[3] += 1
        .
        .
        .
        .
    */
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < 30; j++) {
            bitSetCnt[j] += ((v[i] >> j) & 1);
        }
    }
    cout << "print bitsetCnt" << endl;
    for(auto e: bitSetCnt){
        cout << e << " ";
    }cout << endl;
    /*
        Para que el bit j del XOR entre v[i] y v[k] sea 1, deben ser distintos en ese bit.
        - Si v[i] tiene el bit j en 1:
            - Solo hará contribución al XOR si se encuentra con un número que lo tenga en 0.
            - ¿Cuántos hay así? → n - bitSetCnt[j]
            - Cada uno de estos aporta 2^j al XOR.

        - Si v[i] tiene el bit j en 0:
            - El XOR será 1 si el otro número lo tiene en 1.
            - ¿Cuántos hay así? → bitSetCnt[j]
    */
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 0; j < 30; j++) {
            int bit = ((v[i] >> j) & 1);
            ll val = (1 << j);
            if (bit == 1){
                sum += val * (n - bitSetCnt[j]);
            }
            else{
                sum += val * bitSetCnt[j];
            }
        }
        cout << "sum " << sum << endl;
        ans = max(ans, sum);
    }
    cout << ans << endl;
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


// 5 0101 
// 9 1001
// 7 0111

// [0] 3
// [1] 1
// [2] 2
// [3] 1

// 0 + 2 + 4 + 8    => 14  
// 0 + 2 + 8 + 16   => 26
// 0 + 4 + 4 + 8    => 16