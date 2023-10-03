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

const int N = 500;
ll M[N][N];
const ll INF = 1e17;

void floydWarshall(int n){
	for(int k = 0 ;k < n ; k++){
		for(int i = 0 ;i < n ; i++){
			for(int j = 0 ; j < n; j++){
				M[i][j]= min(M[i][j], M[i][k]+M[k][j]);
				// if (M[i][j] > (M[i][k] + M[k][j])
                //     && (M[k][j] != INF
                //         && M[i][k] != INF))
                //     M[i][j] = M[i][k] + M[k][j];
			}
		}
	}

}
void solve(){
	int n,m,q; cin>>n>>m>>q;
	int a,b;
	ll c;
	for(int e =0; e < m; e++){
		cin>>a>>b>>c;
		a--;b--;
		M[a][b] = M[b][a] = min(M[a][b],c);
	}
	floydWarshall(n);
	while(q--){
		cin>>a>>b;
		a--;b--;
		if(M[a][b] != INF) cout << M[a][b] << endl;
		else cout << -1 << endl;
		// cout << M[a][b] << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	for(int e = 0 ; e < N;e++){
		for(int j = 0 ;j < N ; j++){
			if(e==j) M[e][j] = 0;
			else M[e][j] = INF;
		}
	}
	solve();
	return 0;
}