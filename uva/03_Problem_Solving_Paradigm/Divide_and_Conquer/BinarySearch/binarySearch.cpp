/*
==========================================================
|  Archivo       : binarySearch.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-25 11:33
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Template
|  - binary search
|  - training
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

/*
    lower_bound(x): primer elemento >= x
    upper_bound(x): primer elemento > x
*/

int binarySearch(vector<int> &arr, int target){
    int l = 0;
    int r = arr.size() -1;
    int idx = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] == target){
            idx = mid;
            break;
        }else if(arr[mid] < target){
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    return idx;
}

int myLowerBound(vector<int> &arr, int x){
    int l = 0;
    int r = arr.size() -1;
    int ans = arr.size();
    while(l <= r){
        int mid = l+ (r-l)/2;
        if(x <= arr[mid]){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}

int myUpperBound(vector<int>& arr, int x){
    int l = 0;
    int r = arr.size() - 1;
    int ans = arr.size();
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(x < arr[mid]){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}




/*
    Caso 1: Buscar el primer true (mínimo válido):
        - mínimo tiempo necesario
        - mínimo valor tal que condición se cumple
        - menor X que permite hacer algo

    long long l = 0;
    long long r = 1e18;
    long long ans = -1;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (can(mid)) {
            ans = mid;
            r = mid - 1;   // ir izquierda
        } else {
            l = mid + 1;
        }
    }
*/


/*
    Caso 2: Buscar el último true (máximo válido):
        - máximo valor permitido
        - mayor X que todavía funciona
        - máximo tamaño posible

    long long l = 0;
    long long r = 1e18;
    long long ans = -1;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (can(mid)) {
            ans = mid;
            l = mid + 1;   // ir derecha
        } else {
            r = mid - 1;
        }
    }
*/

void solve() {
    int n ; cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    int val; cin >> val;

    // auto idx = binarySearch(arr, val);
    // cout << idx << endl;

    // auto lb = myLowerBound(arr, val);
    // auto ub = myUpperBound(arr, val);

    // cout << lb << " " << ub << endl;
    // cout << ub - lb << endl;

    // Contar cuantas veces aparece val en todo arr
    auto lb_ = lower_bound(all(arr), val) - arr.begin();
    auto ub_ = upper_bound(all(arr), val) - arr.begin();
    cout<< "#1" << endl;
    cout << lb_ << " " << ub_ << endl;
    cout << ub_ - lb_ << endl;




    // Contar cuantas veces aparece val en arr[l,...,r]
    int l = 1;
    int r = 6;
    auto lb = lower_bound(arr.begin() + l, arr.begin() + r + 1, val) - arr.begin();
    auto ub = upper_bound(arr.begin() + l, arr.begin() + r + 1, val) - arr.begin();
    cout<< "#2" << endl;
    cout << lb << " " << ub << endl;
    cout << ub - lb << endl;


    // Contar cuántos valores están en el rango de valores [Lval, Rval] dentro del intervalo [l, r]
    l = 1;
    r = 6;
    int Lval = 2;
    int Rval = 5;
    int left  = lower_bound(arr.begin() + l, arr.begin() + r + 1, Lval) - arr.begin();
    int right = upper_bound(arr.begin() + l, arr.begin() + r + 1, Rval) - arr.begin();

    int count = right - left;
    cout<< "#3" << endl;
    cout << left << " " << right << endl;
    cout << count << endl;

    cout << "#4" << endl;
    // Cuantos elementos son <= x
    int x = 4;
    int countLessEqual = upper_bound(all(arr), x) - arr.begin();
    cout << countLessEqual << endl;






    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    int caseNum = 1;
    // t = 1;
    while (t--) {
        cout << "Case #" << (caseNum++) << endl;
        solve();
    }
    return 0;
}