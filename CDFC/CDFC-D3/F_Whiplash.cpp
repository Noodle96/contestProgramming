/*
==========================================================
|  Archivo       : F_Whiplash.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-04 11:02
|--------------------------------------------------------
|  Tópicos utilizados:
|  - algebra lineal sobre GF(2) / teoria de grupos (transvecciones)
|  - XOR hashing / matching de multisets por desplazamiento XOR
|  - sorting
|  - numeros grandes (__int128)
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
using u128 = unsigned __int128;
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

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

u128 readU128() {
    string s;
    cin >> s;
    u128 val = 0;
    for (char c : s) val = val * 10 + (u128)(c - '0');
    return val;
}

void solve() {
    int n;
    cin >> n;
    vector<u128> a(n), b(n);
    for (auto &x : a) x = readU128();
    for (auto &x : b) x = readU128();

    u128 totalA = 0, totalB = 0;
    for (u128 x : a) totalA ^= x;
    for (u128 x : b) totalB ^= x;

    u128 R = totalA ^ totalB;

    vector<u128> M(n + 1), Bp(n + 1);
    M[0] = 0 ^ R;
    for (int i = 0; i < n; i++) M[i + 1] = a[i] ^ R;
    Bp[0] = 0;
    for (int i = 0; i < n; i++) Bp[i + 1] = b[i];

    sort(all(M));
    sort(all(Bp));

    bool ok = true;
    for (int i = 0; i <= n; i++) {
        if (M[i] != Bp[i]) { ok = false; break; }
    }

    cout << (ok ? "YES" : "NO") << "\n";
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
    while (t--) {
        solve();
    }
    return 0;
}