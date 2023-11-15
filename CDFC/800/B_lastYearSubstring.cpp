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
const string twenty = "2020";
const string twentyR = "0202";
void solve(){
	int n; cin>>n;
	string s; cin>>s;
	int pos = 0;
	int e = 0;
	for( ;e < 4 ; e++){
		if(s[e] == twenty[pos]) pos++;
		else break;
	}
	// cout << "1: " << pos << endl;
	if(e == 4) {cout << "YES" << endl; return;}
	reverse(all(s));
	// cout << "s: " << s << endl;
	int t_pos = pos;
	for(int i = 0 ; i < (4-t_pos); i++){
		if(s[i] == twentyR[i]){
			 pos++;
			//  cout << "if" << endl;
		}
		else break;
	}
	// cout << "2: " << pos << endl;
	if(pos == 4) cout << "YES" << endl;
	else cout << "NO" << endl;

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