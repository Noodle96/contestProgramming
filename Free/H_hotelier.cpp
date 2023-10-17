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
bitset<10> status;

void solve(){
	int n;cin>>n;
	string s; cin>>s;
	for(int e = 0 ; e < n; e++){
		if(s[e] == 'L'){
			for(int j = 9; j>=0; j--){
				if(status[j] == false){
					status.set(j,1);
					break;
				}
			}
		}else if(s[e] == 'R'){
			for(int j = 0 ; j < 10 ; j++){
				if(status[j] == false){
					status.set(j,1);
					break;
				}
			}
		}else{
			// cout << 9-(s[e]-'0') << endl;
			status.set( 9-(s[e]-'0'),0);
		}
	}
	cout << status << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	// bitset<4> any;
	// any.set(3,1);
	// cout << any << endl;
	return 0;
}