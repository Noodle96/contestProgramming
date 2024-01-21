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

vector<int > solution;
void solve(int caso){
	int n,p,q; cin>>n>>p>>q;
	vector<int> grm(n);
	for(int e = 0 ;e < n ; e++)cin>>grm[e];
	// sort(all(grm));
	int cont = 0;
	int contgrm = 0;
	for(int e = 0 ;e < p ; e++){
		if(e>=n) break;
		if(contgrm + grm[e] <= q){
			contgrm += grm[e];cont++;
		}else{
			break;
		}
	}
	// solution.pb(cont);
	cout << "Case " << caso << ": " << cont << endl;

}
int main(){
	int t; cin>>t;
	int caso = 1;
	while(t--){
		solve(caso++);
	}
	// for(int e = 0 ;e < solution.size() ; e++){
	// 	cout << "Case " << e+1 << ": " << solution[e] << endl;
	// }
	
	return 0;
}