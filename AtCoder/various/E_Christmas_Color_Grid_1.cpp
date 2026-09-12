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
const ll MOD = 998244353;
const int N = 1e3+5;
char grid[N][N];
bool isVisited[N][N];
int idComponents[N][N];
int currentComponent;
int h,w;
int dx[] = {0, -1, 0, 1};
int dy[] = {1,0,-1,0};

ll mod(ll a, ll m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

ll modPow(ll b, ll p, ll m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {                                    // repeats until b == 0
    ll q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

ll modInverse(ll b,ll m) {                   // returns b^(-1) (mod m)
  ll x, y;
  ll d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}

bool isValidPosition(int x, int y){
	return 0 <= x && x < h && 0 <= y  && y < w;
}

int contConnectedComponents;
void dfs(int x, int y){
	idComponents[x][y] = currentComponent;
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 4; e++){
		int new_x = x + dx[e];
		int new_y = y +  dy[e];
		if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == '#' && !isVisited[new_x][new_y]){
			dfs(new_x, new_y);
		}
	}

}
void solve(){
	cin>>h>>w;
	for(int e = 0 ; e < h; e++){
		for(int j = 0 ; j < w; j++){
			cin>>grid[e][j];
			isVisited[e][j] = false;
		}
	}
	// print grid
	// for(int e = 0 ; e < h; e++){
	// 	for(int j = 0 ; j < w; j++){
	// 		cout << grid[e][j];
	// 	}cout << endl;
	// }cout << endl;
	// print grid
	contConnectedComponents = 0;
	currentComponent = 0;
	for(int e = 0 ; e < h; e++){
		for(int j = 0 ; j < w; j++){
			if(grid[e][j] == '#' && !isVisited[e][j]){
				dfs(e,j);
				contConnectedComponents++;
				currentComponent++;
			}
		}
	}
	// cout << "comp conectados: " << contConnectedComponents << endl;
	// print idComponents
	// for(int e = 0 ; e < h; e++){
	// 	for(int j = 0 ; j < w; j++){
	// 		cout << idComponents[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	ll num = 0;
	ll den = 0;
	for(int e = 0 ; e < h; e++){
		for(int j = 0 ; j < w; j++){
			if(grid[e][j] == '.'){
				den++;
				set<int> set;
				for(int i = 0 ; i < 4; i++){
					int new_x = e + dx[i];
					int new_y = j + dy[i];
					if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == '#'){
						set.insert(idComponents[new_x][new_y]);
					}
				}
				// cout << "size: " << set.size() << endl;
				// int temp = (contConnectedComponents - (set.size() -1));
				// cout << "temp: "  << temp << endl;
				num += (contConnectedComponents - (set.size() -1));
			}
		}
	}
	// cout << num << " " << den << endl;
	// cout << mod(num, MOD) << " " << modInverse(den, MOD) << endl;
	// return;
	ll a = (ll)mod(num, MOD);
	ll b = (ll)modInverse(den, MOD);
	ll ans = (a*b)%MOD;
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	// cout << modInverse(6,MOD) << endl;
	return 0;
}