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
const int N = 20;
char A[N][N];
void solve(){
	int n,m; cin>>n>>m;
	memset(A, 'j', sizeof(A));
	// for(int e = 0 ;e < N ; e++){
	// 	for(int j = 0 ; j < N; j++){
	// 		cout << A[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// return;
	for(int e = 0 ; e <n; e++){
		for(int j = 0 ; j < m; j++){
			cin>> A[e][j];
		}
	}
	char goal[] = {'v', 'i', 'k', 'a'};
	int k = 0;
	for(int e = 0 ;e < m ; e++){
		for(int j = 0 ;j < n ; j++){
			if( A[j][e] == goal[k] ){
				k++; break;
			}
		}
		// cout << "k: " <<k << endl; 
		if(k == 4){
			cout << "YES" << endl; return;
		}
	}
	cout << "NO" << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}