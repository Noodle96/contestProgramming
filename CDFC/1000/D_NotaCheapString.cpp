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
string s;
int p;
int freq[27];
void solve(){
	for(int e = 0 ;e < 27 ; e++) freq[e] = 0;
	cin>>s>>p;
	for(int e = 0 ;e < (int)s.size() ; e++){
		freq[s[e]-'`']++;
	}
	#ifdef DEBUGG
		cout << "frquencias" << endl;
		for(int e = 0 ; e < 27 ; e++){
			cout <<  e << " : " << freq[e] << endl;
		}
	#endif
	map<char, int> map;
	for(int e = 1; e< 27; e++){
		if(freq[e]*e <= p){
			// cout << "any: " <<  char(e+'`') << endl;
			map[char(e+'`')] = freq[e];
			p-= freq[e]*e;
			// cout << "p restante: " << p << endl;
		}else{
			map[char(e+'`')] = p/e;
			break;
		}
	}
	#ifdef DEBUGG
		cout << "mapa" << endl;
		for(auto e: map){
			cout << e.first << " : " <<e.second << endl; 
		}
	#endif
	string ans;
	for(int e= 0 ; e < (int)s.size(); e++){
		if(map[s[e]] > 0){
			// cout << "in:  " <<  map[s[e]] << endl; 
			ans += s[e];
			map[s[e]]--;
		}
	}
	cout << ans << endl;
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