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
const int N = 100;
int h,w,n;
char grid[N][N];
enum Direction {Top,Right,Bottom,Left};

Direction rotateClockwise(Direction dir){
	if(dir == Top) return Right;
	if(dir == Right) return Bottom;
	if(dir == Bottom) return Left;
	return Top;
}
Direction rotateCounterclockwise(Direction dir){
	if(dir == Top) return Left;
	if(dir == Left) return Bottom;
	if(dir == Bottom) return Right;
	return Top;
}


void solve(){
	cin>>h>>w>>n;
	for(int e = 0 ; e < h; e++){
		for(int j = 0 ; j < w; j++){
			grid[e][j] = '.';
		}
	}
	int x = 0, y = 0;
	Direction curDir = Top;
	for(int e = 0 ; e < n; e++){
		if(grid[x][y] == '.'){
			grid[x][y] = '#';
			curDir = rotateClockwise(curDir);
			if(curDir == Right){
				y += 1;
				y %= w;
			}
			if(curDir == Left){
				y -=1;
				if(y<0) y = w-1;
				y %= w;
			}
			if(curDir == Top){
				x -=1;
				if(x < 0) x = h-1;
				x %= h;
			}
			if(curDir == Bottom){
				x += 1;
				x %= h;
			}
		}else{
			grid[x][y] = '.';
			curDir = rotateCounterclockwise(curDir);
			if(curDir == Right){
				y += 1;
				y %= w;
			}
			if(curDir == Left){
				y -=1;
				if(y<0) y = w-1;
				y %= w;
			}
			if(curDir == Top){
				x -=1;
				if(x < 0) x = h-1;
				x %= h;
			}
			if(curDir == Bottom){
				x += 1;
				x %= h;
			}
		}
	}
	for(int e = 0 ; e < h; e++){
		for(int j = 0 ; j < w; j++){
			cout << grid[e][j];
		}cout << endl;
	}cout << endl;

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