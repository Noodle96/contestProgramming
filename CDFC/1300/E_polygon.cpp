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
const int N = 50;
int arr[N][N];
char c;
void solve(){
	int n; cin>>n;
	for(int e = 0 ;e < n ; e++){
		for(int j = 0 ; j < n; j++){
			cin >>c; 
			arr[e][j] = c -'0';
		}
	}
	bool ans = true;
	for(int e = n-2 ;e >= 0 ; e--){
		for(int j = n-2 ; j >= 0; j--){
			if(arr[e][j] && !arr[e+1][j] && !arr[e][j+1]) ans = false;
		}
	}
	cout << (ans?"YES":"NO") << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--)solve();
	return 0;
}