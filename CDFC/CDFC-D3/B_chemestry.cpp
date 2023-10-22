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
	int k,n; cin>>n>>k;
	string s; cin>>s;
	vector<int> ar(30);
	for(int e = 0 ; e <n; e++){
		//cout << s[e]-'`' << endl;
		ar[s[e]-'`']++;
	}
	// for(int e = 0 ;e < 30 ;e++){
	// 	cout << ar[e] << " ";
	// }cout << endl;
	
	//sort(all(ar));
	int oddCOunt = 0;
	for(int e = 0 ; e <30; e++){
		if(ar[e] != 0){
			if(ar[e]%2 != 0) oddCOunt ++;
		}
	}
	if(oddCOunt > (k+1)){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
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