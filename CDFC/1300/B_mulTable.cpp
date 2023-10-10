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
const int N = 1e3;
int n;
ll arr[N][N];
void solve(){
	cin>>n;
	for(int e = 0 ; e < n; e++){
		for(int j= 0 ;j < n ; j++){
			cin>>arr[e][j];
		}
	}

	ll a = sqrt(arr[0][1]*arr[0][2]/arr[1][2]);
	cout << a << " ";
	for(int e =  1;e < n ; e++){
		cout << arr[0][e] / a << " ";
	}cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}