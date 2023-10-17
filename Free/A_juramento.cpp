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
const int N = 1e5 +5;
int ar[N];
void solve(){
	int n; cin>>n;
	int maximo = INT_MIN;
	int minimo = INT_MAX;
	for(int e = 0 ; e <n;e++){
		cin>>ar[e];
		minimo = min(minimo, ar[e]);
		maximo = max(maximo, ar[e]);
	}
	if(n<=2){cout << 0 << endl; return;}
	int cont = 0 ;
	for(int e = 0; e < n; e++){
		if(ar[e] > minimo && ar[e] < maximo) cont++;
	}
	cout << cont << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}