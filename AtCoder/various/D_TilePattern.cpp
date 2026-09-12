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
int N;

ll countBlacks(ll x, ll y, vector<vector<ll>> &M_count ){
	ll c_square = M_count[N-1][N-1];
	ll rows, cols, resto_rows, resto_cols,total;
	if((x+1)%N == 0 && (y+1)%N == 0 ){
		rows = (x+1)/N;
		cols = (y+1)/N;
		total = rows*cols*c_square;
	}else if((y+1)%N ==0){
		cols = (y+1)/N;
		rows = (x+1)/N;
		resto_rows = (x+1)-rows*N;
		total = rows*cols*c_square;
		total += cols*M_count[resto_rows-1][N-1];
	}else if((x+1)%N == 0){
		cols = (y+1)/N;
		rows = (x+1)/N;
		resto_cols = (y+1) - cols*N;
		total = total = rows*cols*c_square;
		total += rows*M_count[N-1][resto_cols-1];
	}else{
		rows = (x+1)/N;
		resto_rows = (x+1) - rows*N;
		cols = (y+1)/N;
		resto_cols = (y+1) - cols*N;
		total = rows*cols*c_square;
		total += rows*M_count[N-1][resto_cols-1];
		total += cols*M_count[resto_rows-1][N-1];
		total += M_count[resto_rows-1][resto_cols-1];
	}
	return total;
}

ll countBlacksSquares(ll a,ll b, ll c, ll d, vector<vector<ll>> &M_count ){
	ll a_,b_,c_,d_;
	a_ = countBlacks(c,d,M_count);
	if(b == 0){
		b_ = 0;
	}else{
		b_ =  countBlacks(c,b-1,M_count);
	}
	if(a == 0){
		c_ = 0;
	}else{
		c_ = countBlacks(a-1,d,M_count);
	}
	if((a == 0) && (b == 0)){
		d_ = 0;
	}else{
		d_ = countBlacks(a-1,b-1,M_count);
	}
	// cout << a_ << " " <<  b_ << " " << c_ <<" " << d_ << endl; 
	return a_-b_-c_+d_;
	return countBlacks(c,d,M_count) - countBlacks(c,b,M_count) - 
			countBlacks(a,d,M_count) + countBlacks(a,b,M_count) ;
}
void solve(){
	int Q;
	cin>>N>>Q;
	char ch;
	vector<vector<bool>> M(N, vector<bool>(N,false));
	for(int e = 0 ; e < N; e++){
		for(int j = 0 ; j < N; j++){
			cin>>ch;
			if(ch == 'B') M[e][j] =false;
			else M[e][j] = true; 
		}
	}
	// cout << "M:" << endl;
	// for(int e = 0  ; e < N; e++){
	// 	for(int j = 0 ; j < N; j++){
	// 		cout << M[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;

	vector<vector<ll>> M_count(N, vector<ll>(N,0));
	//build M_count => primero construir una L
	//build M[0][e]
	M_count[0][0] = (M[0][0]==false?1:0);
	for(int col = 1 ; col < N;col++){
		M_count[0][col] = M_count[0][col-1] + (M[0][col]==false?1:0);
	}
	//build M[e][0]
	for(int row = 1 ; row < N ; row++){
		M_count[row][0] = M_count[row-1][0] + (M[row][0]==false?1:0);
	}
	//build the rest
	for(int row = 1; row < N; row++){
		for(int col =1; col < N; col++){
			M_count[row][col] = M_count[row][col-1] + M_count[row-1][col] - 
			M_count[row-1][col-1] + (M[row][col]==false?1:0);
		}
	}
	// cout << "M_count:" << endl;
	// for(int e = 0  ; e < N; e++){
	// 	for(int j = 0 ; j < N; j++){
	// 		cout << M_count[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	ll a,b,c,d;
	ll total;
	for(int e = 0 ; e < Q;e++){
		cin>>a>>b>>c>>d;
		total = countBlacksSquares(a,b,c,d, M_count);
		cout << total << endl;
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