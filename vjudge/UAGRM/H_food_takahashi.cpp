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
	int n,k; cin>>n>>k;
	vector<int> A(n);
	vector<int> B(k);
	int maximo = INT_MIN;
	for(int e = 0 ; e < n; e++){
		cin>>A[e];
		if(A[e] > maximo) maximo = A[e];
	}
	// cout << "A: " << endl;
	// for(int e = 0 ; e < n ;e++){
	// 	cout << A[e] <<" ";
	// }cout << endl;

	for(int e = 0 ;e < k ; e++) cin>>B[e];
	// cout << "B: " << endl;
	// for(int e = 0 ;e < k ; e++){
	// 	cout << B[e] <<" ";
	// }cout << endl;
	// cout << "maximo: " << maximo << endl;

	for(int e = 0 ; e < k ; e++){
		if( A[ B[e]-1 ] == maximo  ){
			cout << "Yes\n"; return;
		}
	}
	cout << "No\n";
}
int main(){
	solve();
	return 0;
}