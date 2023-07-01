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
	int n; cin>>n;
	vector<int> A(n);
	for(auto &e:A) cin>>e;
	vector<int> B(n);
	for(auto&e:B)cin>>e;
	vector<int> C(n-1);
	for(auto &e:C) cin>>e;
	int total = 0;
	total += B[A[0]-1];

	for(int e = 1 ;e < n ; e++){
		if(A[e]-A[e-1] == 1){
			total += C[A[e-1]-1];
			total += B[A[e]-1];
		}
		else{
			total += B[A[e]-1];
		}
	}
	cout << total << endl;

}
int main(){
	solve();
	return 0;
}