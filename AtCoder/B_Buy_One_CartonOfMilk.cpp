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

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int ar[3];
int precio[3]={6,8,12};
void solve(){
	int ans = INT_MAX;
	int N;cin>>N;
	for(int e = 0 ; e < 3; e++)cin>>ar[e];
	for(int e = 0 ; e < 3; e++){
		int resto = N%precio[e];
		if(resto == 0){
			ans = min(ans,(N/precio[e])*ar[e]);
		}else{
			if(resto == 6 || resto == 8 || resto == 12){
				int r = N - N/precio[e];
				int temp = (N/precio[e])*ar[e] + r;
				ans = min(ans, temp);
			}
		}
	}if(ans == INT_MAX){
		for(int e = 0 ;e < 3  ; e++){
			ans = min(ans, (N/precio[e] +1 )*ar[e]);
		}
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
	solve();
	return 0;
}