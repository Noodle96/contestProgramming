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
const int N = 1e3+5;
int adj[N];
int n,u;
string blankLine;
void solve(){
	cin>>n;
	cin.ignore();
	for(int e = 0 ;e <n ; e++){
		getline(cin,blankLine);
		stringstream ss(blankLine);
		while(ss>>u){
			adj[e]++;
		}
	}
	// print adj
	// cout << "adj: " << endl;
	// for(int e = 0 ; e < n; e++){
	// 	cout << "e->" << e << " "<< adj[e]<<  endl;
	// }

	getline(cin,blankLine);
	// cout << "blankline: "<< blankLine << endl;
	int mn = *min_element(adj,adj+n);
	vector<int> ans;
	for(int e = 0 ; e < n; e++){
		if(adj[e]==mn){
			ans.pb(e+1);
		}
	}
	for(int e = 0 ; e < ans.size(); e++){
		if(e) cout<<" ";
		cout<<ans[e];
	}cout << endl;
	for(int e = 0 ; e < N; e++) adj[e] = 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}