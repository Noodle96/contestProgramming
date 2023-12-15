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
void solve(){
	int n; cin>>n;
	vector< vector<char> > grid(n, vector<char>(n));
	vector< vector<int> > left(n, vector<int>(n));
	vector< vector<int> > right(n, vector<int>(n));
	vector< vector<int> > bottom(n, vector<int>(n));
	vector< vector<int> > up(n, vector<int>(n));

	char ch;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ;j <  n ; j++){
			cin>>grid[e][j];
		}
	}
	// cout << "print grid" << endl;
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ;j <  n ; j++){
	// 		cout << grid[e][j];
	// 	}cout << endl;
	// }cout << endl;

	//to the left
	for(int e = 0 ; e < n; e++){
		left[e][0] = (grid[e][0]=='o'?1:0);
		for(int j = 1 ;j <  n ; j++){
			left[e][j] = left[e][j-1] + (grid[e][j]=='o'?1:0);
		}
	}

	// cout << "left: " << endl;
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ;j <  n ; j++){
	// 		cout << left[e][j];
	// 	}cout << endl;
	// }cout << endl;

	// to the right
	for(int e = 0 ; e < n; e++){
		right[e][n-1] = (grid[e][n-1]=='o'?1:0);
		for(int j = n-2 ;j >= 0 ; j--){
			right[e][j] = right[e][j+1] + (grid[e][j]=='o'?1:0);
		}
	}
	// cout << "right: " << endl;
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ;j <  n ; j++){
	// 		cout << right[e][j];
	// 	}cout << endl;
	// }cout << endl;

	//to the bottom
	for(int col = 0 ;col < n ; col++){
		bottom[n-1][col] = (grid[n-1][col]=='o'?1:0);
		for(int row = n-2 ;row >= 0 ; row--){
			bottom[row][col] = bottom[row+1][col] + (grid[row][col]=='o'?1:0);
		}
	}
	// cout << "bottom: " << endl;
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ;j <  n ; j++){
	// 		cout << bottom[e][j];
	// 	}cout << endl;
	// }cout << endl;

	//to up
	for(int col = 0 ; col < n; col++){
		up[0][col] = (grid[0][col]=='o'?1:0);
		for(int row = 1 ;row < n ; row++){
			up[row][col] = up[row-1][col] + (grid[row][col]=='o'?1:0);
		}
	}


	ll cont = 0LL;
	int b,l,r,u;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < n ; j++){
			if(grid[e][j]== 'o'){
				b = --bottom[e][j];
				l = --left[e][j];
				r = --right[e][j];
				u = --up[e][j];
				cont += (ll)((b*l)+(b*r)+ (u*l)+(u*r));
				// cout <<"cont: " << cont << endl;
			}
		}
	}
	cout << cont << endl;


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