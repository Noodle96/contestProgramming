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
void solve(){
	int n; cin>>n;
	vector<vector<int>> vec(2);
	for(int e = 1 ; e <= n; e++){
		vec[e&1].pb(e);
	}
	if(n== 1){cout << 1 << endl; return;}
	if(n <=3) cout << "NO SOLUTION" << endl;
	else{
		for(auto e: vec[0]){
			cout << e << " ";
		}
		for(auto e: vec[1]){
			cout << e << " ";
		}cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}