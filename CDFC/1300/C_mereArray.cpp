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

const int N = 1e5;
int ar[N];
int ar2[N];
void solve(){
	int n; cin>>n;
	int minElement = INT_MAX;
	for(int e = 0  ; e < n; e++){
		cin>>ar[e];
		ar2[e] = ar[e];
		minElement = min(minElement, ar[e]);
	}
	sort(ar2, ar2+n);

	for(int e = 0 ;e <n ; e++){
		if(ar[e] != ar2[e]){
			// gcd(ar[e],ar2[e]) != minElement
			if( ar[e] % minElement != 0){
				cout << "NO" << endl; return;
			}
		}
	}
	cout << "YES" << endl;
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