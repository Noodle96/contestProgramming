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

char grid[10][10];


int evaluate(int x, int y){
	if(x>=5 && x<=6&& y >=5 && y<=6 ) return 5;
	if(x>=4 && x<=7&& y >=4 && y<=7 ) return 4;
	if(x>=3 && x<=8&& y >=3 && y<=8 ) return 3;
	if(x>=2 && x<=9&& y >=2 && y<=9 ) return 2;
	return 1;
}

void solve(){
	for(int e = 0 ; e < 10; e++){
		for(int j = 0 ; j <10; j++){
			cin>> grid[e][j];
		}
	}
	int cont = 0;
	for(int e = 0 ; e < 10; e++){
		for(int j = 0 ; j <10; j++){
			if(grid[e][j] == 'X'){
				cont += evaluate(e+1,j+1);
			}
		}
	}
	cout << cont << endl;
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