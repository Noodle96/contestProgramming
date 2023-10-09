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
void solve(){
	int n,k; cin>>n>>k;//scanf("%d%d",&n,&k);
	int maximoDivisor = INT_MIN;
	for(int i = 1 ;i*i <= n ; i++){
		if(n%i ==0){
			if(i <= k) maximoDivisor = max(maximoDivisor, i);
			if(n/i <= k) maximoDivisor = max(maximoDivisor, n/i);
		}
	}
	cout << n / maximoDivisor << endl;
	// printf("%d", n/maximoDivisor);
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef IN_OUT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t; cin>>t;
	while(t--)solve();
	return 0;
}