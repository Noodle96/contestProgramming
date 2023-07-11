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
#define fi first
#define se second
void solve(){
	int n,m; cin>>n>>m;
	// int N[n], M[m];
	// int P[n+m];
	// for(auto e = 0 ; e < n; e++) cin>> N[e];
	// for(auto e = 0 ; e < m; e++) cin>> M[e];
	// int k = 0, i = 0, j = 0;
	// while(i < n || j < m){
	// 	if(j == m || (i < n && N[i] < M[j] )){
	// 		P[k++]=N[i++];
	// 	}else P[k++] = M[j++];
	// }
	// for(int e =0 ; e < n+m; e++){
	// 	cout << P[e] << " ";
	// }cout << endl;
	vector<int> N(n);
	vector<int> M(m);
	vector<int> P;
	for(auto e = 0 ; e < n; e++) cin>> N[e];
	N.push_back(INT_MAX);
	for(auto e = 0 ; e < m; e++) cin>> M[e];
	M.push_back(INT_MAX);
	// for(auto it = N.begin(); it != N.end() ; it++){
	// 	cout << *it << endl;
	// }
	// for(auto it = M.begin(); it != M.end() ; it++){
	// 	cout << *it << endl;
	// }
	// return;
	int i = 0, j = 0;
	int cont = 0;
	while(i < N.size()-1 || j < M.size()-1){
	// while(cont++ < 15){
		// cout << "i: " << i << "j: " << j << endl;
		if(N[i] < M[j]){
			P.pb(N[i++]);
		}else{
			P.pb(M[j++]);
		}
	}
	// cout << "dd: " << endl;
	for(auto it = P.begin() ;it != P.end() ; it++){
		cout << *it << " ";
	}cout << endl;
// 	6 7
// 1 6 9 13 18 18
// 2 3 8 13 15 21 25

}
int main(){
	solve();
	return 0;
}