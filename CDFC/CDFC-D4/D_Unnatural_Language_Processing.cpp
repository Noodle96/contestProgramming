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
bool isConsonant(char ch){
	return ch == 'b' || ch == 'c' || ch == 'd';
}
void solve(){
	int n; cin>>n;
	string s; cin>>s;
	if(n == 1){cout << s[0] << endl; return;}
	string ans;
	int e = 0 ; 
	while(e<n){
		ans += s[e];
		ans += s[e+1];
		e+=2;
		if(e < n){
			if(isConsonant(s[e+1]) || e+1>=n){
				ans += s[e];
				ans += '.';
				e+=1;
			}else{
				ans += '.';
			}
		}else break;
	}
	if(ans.back() == '.'){
		for(int e = 0 ; e < ans.size()-1; e++){
			cout << ans[e];
		}cout << endl;
	}else{
		for(int e = 0 ; e < ans.size(); e++){
			cout << ans[e];
		}cout << endl;
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