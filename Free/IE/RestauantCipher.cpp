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
bool cmp(pair<int, char> &p1,pair<int, char> &p2){
	return p1.first> p2.first;
}

void solve(){
	string line;
	getline(cin,line);
	map<char, int> mapa;
	for(int e =0 ; e < (int)line.size(); e++){
		mapa[line[e]]++;
	}
	// cout << "mapa data : " << endl; 
	vector<pair<int,char>> ans;
	for(auto it = mapa.begin(); it != mapa.end() ; it++){
		ans.pb({it->second, it->first});
		// cout << it->first << " " << it->second << endl;
	}
	// for(auto it = ans.begin(); it != ans.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	sort(all(ans), cmp);
	// cout << "after sort:" << endl;
	// for(auto it = ans.begin(); it != ans.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	for(auto it = ans.begin() ;it != ans.end() ; it++){
		if(it->second == 'a' || it->second == 'b' || it->second == 'c' || it->second == 'd'
		|| it->second == 'e' || it->second == 'f' || it->second == 'g' ){
			cout << char(toupper(it->second)) << endl;
			return;
		}
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
	cin.ignore();
	while(t--)solve();
	return 0;
}