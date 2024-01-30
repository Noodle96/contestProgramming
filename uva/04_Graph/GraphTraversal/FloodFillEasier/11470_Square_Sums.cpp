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
int n;
const int N = 10;
int grid[N][N];

int f(int idx){
	int sum = 0;
	//add rows
	for(int e = idx; e <= n-1-idx; e++){
		sum += grid[idx][e];
	}
	for(int e = idx; e <= n-1-idx; e++){
		sum += grid[n-1-idx][e];
	}
	// add cols
	for(int e = idx; e <= n-1-idx; e++){
		sum += grid[e][idx];
	}
	for(int e = idx; e <= n-1-idx; e++){
		sum += grid[e][n-1-idx];
	}
	//quitar los extremos
	sum -= grid[idx][idx];
	sum -= grid[idx][n-1-idx];
	sum -= grid[n-1-idx][idx];
	sum -= grid[n-1-idx][n-1-idx];
	return sum;
}
void solve(){
	int caso = 1;
	while(1){
		cin>>n;
		if(n == 0) break;
		else{
			vector<int> ans;
			for(int e = 0; e < n; e++){
				for(int j = 0 ; j < n; j++){
					cin>> grid[e][j];
				}
			}
			for(int e = 0; e < n/2; e++){
				int sum = f(e);
				ans.pb(sum);
			}
			if(n & 1){
				ans.pb(grid[n/2][n/2]);
			}
			cout << "Case " << caso++ << ": ";
			int e = 0 ;
			for( ;e < (int) ans.size()-1; e++){
				cout << ans[e] << " ";
			}cout << ans[e] << endl;
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