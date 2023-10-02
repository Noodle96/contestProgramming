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

const int N = 3e2;
ll M[N][N];

void solve(){
	int n; cin>>n;
	for(int e = 0 ; e < n; e++){
		for(int j = 0;j < n ;j++){
			cin>>M[e][j];
		}
	}
	int k; cin>>k;
	ll a,b,c;
	while(k--){
		cin>>a>>b>>c;
		a--; b--;
		M[a][b] = M[b][a] = min(c,M[a][b]);
		for(int i = 0 ;i < n ; i++){
			for(int j = 0  ; j < n; j++){
				for(int t =0 ; t < 2 ; t++){
					M[i][j] = min(M[i][j], M[i][a] + M[a][b]+M[b][j]);
					swap(a,b);
				}
			}
		}
		ll sum = 0;
		for(int e = 0 ;e < n ; e++){
			for(int j = 0 ;j < e ; j++){
				// cout << e << " " << j <<endl;
				sum += M[e][j];
			}
		}
		cout << sum << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}