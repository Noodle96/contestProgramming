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

pair<int,int> getDistance(string s){
	sort(all(s));
	pair<int,int> ans;
	ans.first = abs(s[0]-s[1]);
	// cout << abs(s[0]-'A') << " " <<   << endl;
	ans.second = abs(abs(s[0]-'A') +  abs(s[1]-'E') +1);
	// cout << ans.first << " " << ans.second << endl;
	return ans;
}

void solve(){
	string s1,s2;
	cin>>s1>>s2;
	auto [ans1, ans2] = getDistance(s1);
	auto [ans3, ans4] = getDistance(s2);
	if(ans1 == ans3 || ans1 == ans4 || ans2 == ans3 || ans2 == ans4){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}