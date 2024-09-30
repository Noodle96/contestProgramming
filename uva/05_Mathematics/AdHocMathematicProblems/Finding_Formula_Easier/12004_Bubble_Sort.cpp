#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str, str2) cout << str << str2 << endl
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b){
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(int caso)
{
    ll n;
    cin >> n;
    ll num = n * (n - 1);
    ll den = 4;
    ll g = gcd(num, den);
    num /= g;
    den /= g;
    if (den == 1)
    {
        cout << "Case " << caso << ": " << num << endl;
    }
    else
    {
        cout << "Case " << caso << ": " << num << "/" << den << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int caso = 1;
    while (t--)
    {
        solve(caso++);
    }
    return 0;
}