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
const int N = 2e5;
int ar[N];

bool isSorted(int b, int f){
	if(b==f) return true;
	auto first = ar[b];
	for(int e = b+1; e < f; e++){
		if(first > ar[e]) return false;
		first = ar[e];
	}
	return true;
}


void solve(){
	int n; cin>>n;
	int minimo = INT_MAX;
	for(int e = 0 ; e < n; e++){
		cin>>ar[e];
		minimo = min(minimo, ar[e]);
	}
	int pos = 0;
	for(int e= 0 ; e < n; e++){
		if(ar[e] == minimo){
			pos = e;
			break;
		}
	}
	//pos con la posicion del minimo
	if(isSorted(pos+1,n)){
		cout << pos << endl;
	}else{
		cout << -1 << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}