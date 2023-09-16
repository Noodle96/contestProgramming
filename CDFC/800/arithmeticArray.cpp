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
	int total = 0;
	for(int e = 0,temp ; e < n; e++){
		cin>>temp;
		total += temp;
	}
	if(total >= n){
		cout << total - n << endl;
	}else{
		//total es -
		cout << 1 << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}