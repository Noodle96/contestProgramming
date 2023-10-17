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
const int N = 3;
char ar[N];
char goalA[3] = {'y','e','s'};
char goalB[3] = {'Y','E','S'};
void solve(){
	for(int e = 0 ; e < N; e++)cin>>ar[e];
	// for(int e =0 ; e < 3; e++){
	// 	cout << ar[e] << " ";
	// }cout << endl; return;
	for(int e = 0 ; e < N; e++){
		if(ar[e] == goalB[e] || ar[e] == goalA[e]){;}
		else{cout << "NO" <<endl;return;}
	}

	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
	solve();
	return 0;
}