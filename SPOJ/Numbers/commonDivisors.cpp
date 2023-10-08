#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll gcd(ll a, ll b){
    return b == 0 ? a: gcd(b, a%b);
}
void solve(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll  number = gcd(a,b);
	ll total = 1;
	for(int i = 2; (ll)i*i <= number; i++){
		if(number % i == 0){
			int e = 0;
			while(number % i == 0){
				e++; number /= i;
			}
			total *= (e+1);
		}
	}
	if(number > 1) total *= 2;
	printf("%lld\n", total);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;scanf("%d", &t);
	while(t--)solve();
	return 0;
}