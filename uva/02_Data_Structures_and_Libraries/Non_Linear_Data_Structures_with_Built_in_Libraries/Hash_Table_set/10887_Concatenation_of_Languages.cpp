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
string str;
set<string> M,N;
void solve(int caso){
	M.clear(), N.clear();
	int m,n;
	cin>>m>>n;
	cin.ignore();
	// cout << "m: " << m << " n: " << n << endl;
	for(int e = 0 ;e < m ; e++){
		getline(cin,str);
		// cout << "the line is: " << str << endl;
		M.insert(str);
	}
	for(int e = 0 ;e < n ; e++){
		getline(cin,str);
		// cout << "the line is: " << str << endl;
		N.insert(str);
	}
	map<string,int> mapa;
	for(auto e: M){
		for(auto f: N){
			mapa[e+f]++;
		}
	}
	cout << "Case " << caso << ": "<< mapa.size() << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	int caso = 1;
	while(t--){
		solve(caso++);
	}
	
	return 0;
}