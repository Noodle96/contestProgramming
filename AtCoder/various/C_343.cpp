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
vector<ll> cubos;
ll N;
string s;

bool isPalindrome(string s){
	int n = s.size();
	for(int i = 0; i < n/2; i++){
		if(s[i] != s[n-i-1]) return false;
	}
	return true;
}

void solve(){
	cin>>N;
	auto it_find = find(all(cubos),N);
	
	if(it_find != cubos.end()){
		for(; ; it_find--){
			s = to_string(*it_find);
			if(isPalindrome(s)){
				cout << s << endl;
				return;
			}
		}
	}else{
		auto it = lower_bound(all(cubos),N);
		it--;
		for(; ; it--){
			s = to_string(*it);
			if(isPalindrome(s)){
				cout << s << endl;
				return;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	for(ll e = 1 ; e*e*e <= 1e18; e++){
		cubos.pb(e*e*e);
	}
	solve();
	return 0;
}