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
	int n,k; cin>>n>>k;
	vector<int> vec(n);
	int contPares = 0;
	int producto = 1;
	for(int e = 0 ;e < n ; e++){
		cin>>vec[e];
		producto *= vec[e];
		if(vec[e]%2==0) contPares++;
	}
	if(k==4){
		if(producto % k == 0) cout << 0 << endl;
		else{
			int pares = max(0, 2-contPares);
			int intervalo = INT_MAX;
			for(int e = 0 ; e < n; e++){
				if(vec[e]%k == 0) intervalo = 0;
				else{
					int a = k*(vec[e]/k +1) -vec[e];
					intervalo = min(intervalo,a);
				}
			}
			cout << min(pares, intervalo) << endl;
		}
	}else{
		int intervalo = INT_MAX;
		for(int e = 0 ; e < n; e++){
			if(vec[e]%k == 0) intervalo = 0;
			else{
				int a = k*(vec[e]/k +1) -vec[e];
				intervalo = min(intervalo,a);
			}
		}
		cout << intervalo << endl;
	}
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