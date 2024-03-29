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
	int n; cin>>n;
	string s; cin>>s;
	if(n%2==0){
		int e = 0;
		for(;e < n-2 ;e+=2){
			cout << s[e] << s[e+1] << "-";
		}
		cout << s[e] << s[e+1] << endl;
	}else{
		int e = 0;
		for(;e < n-3 ;e+=2){
			cout << s[e] << s[e+1] << "-";
		}
		cout << s[e] << s[e+1] << s[e+2]<< endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}