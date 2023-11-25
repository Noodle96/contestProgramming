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
int INF = 1e8;
map<string, int> juices;

void pre(){
	juices["A"] = INF;
	juices["B"] = INF;
	juices["C"] = INF;
	juices["AB"] = INF;
	juices["AC"] = INF;
	juices["BC"] = INF;
	juices["ABC"] = INF;
}

void solve(){
	int n, price;
	string vtm;
	cin>>n;
	for(int e = 0 ;e < n ; e++){
		cin>>price>>vtm;
		sort(all(vtm));
		juices[vtm] = min(juices[vtm], price);
	}
	int ans = INF;
	ans = min(ans,juices["A"]+juices["BC"]);
	ans = min(ans,juices["B"]+juices["AC"]);
	ans = min(ans,juices["C"]+juices["AB"]);
	ans = min(ans,juices["A"]+juices["B"]+juices["C"]);
	ans = min(ans,juices["AB"]+juices["AC"]);
	ans = min(ans,juices["AB"]+juices["BC"]);
	ans = min(ans,juices["AC"]+juices["BC"]);
	ans = min(ans,juices["ABC"]);
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	pre();
	solve();
	return 0;
}