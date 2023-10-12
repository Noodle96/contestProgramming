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
	string line;
	map<char, vector<char> > map;
	for(int e = 0 ; e < 3; e++){
		cin>>line;
		if(line[1] == '>'){
			map[line[0]].pb(line[2]);
		}else{
			map[line[2]].pb(line[0]);
		}
	}
	if(map.size() == 3){
		cout << "Impossible" << endl;
	}else{
		vector<char> ans;
		for(auto it = map.begin() ; it != map.end(); it++){
			if(it->second.size() == 2){
				ans.pb(it->first);
				if(map.count(it->second[0]) > 0){
					ans.pb(it->second[0]);
					ans.pb(it->second[1]);
				}else{
					ans.pb(it->second[1]);
					ans.pb(map[it->second[1]][0]);
				}
			}
		}
		reverse(all(ans));
		for(auto it = ans.begin() ; it != ans.end(); it++){
			cout << *it;
		}cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}