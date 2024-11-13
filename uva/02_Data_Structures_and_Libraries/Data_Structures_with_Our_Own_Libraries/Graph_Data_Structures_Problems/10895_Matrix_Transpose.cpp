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

const int N = 1e4;
int matriz[N][N];
int n,m,r;

void solve(){
	while(cin>>m>>n){
		for(int e = 0 ; e < m; e++){
			cin>>r;
			vector<int> index;
			for(int j = 0, idx ;j < r ; j++){
				cin>>idx;
				idx--;
				index.pb(idx);
			}
			for(int j = 0,val ; j < r; j++){
				cin>>val;
				matriz[e][index[j]] = val;
			}

		}
		// print matriz
		// msg("print matriz","");
		// for(int e = 0 ; e < m; e++){
		// 	for(int j = 0 ;j < n ; j++){
		// 		cout << matriz[e][j] << " ";
		// 	}cout << endl;
		// }cout << endl;
		cout << n << " " << m << endl;
		for(int e = 0 ; e < n; e++){
			vector<pair<int,int>> idx_val;
			for(int j = 0 ; j < m; j++){
				if(matriz[j][e] != 0) idx_val.emplace_back(j, matriz[j][e]);
			}
			//recorremos idx_val;
			if(idx_val.size() != 0){
				cout << idx_val.size() << " ";	
			}else{
				cout << idx_val.size();
			}
			for(int e = 0 ; e < idx_val.size(); e++){
				if(e) cout << " ";
				cout << idx_val[e].first+1;
			}cout << endl;
			for(int e = 0 ; e < idx_val.size(); e++){
				if(e) cout << " ";
				cout << idx_val[e].second;
			}cout <<endl;
		}
		for(int e = 0 ; e < m; e++){
			for(int j = 0 ;j < n ;j++){
				matriz[e][j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}