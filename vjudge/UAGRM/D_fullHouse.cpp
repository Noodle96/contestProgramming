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
void solve(){
	map<int,int> map;
	for(int e = 0,temp ; e < 5; e++){
		cin>>temp;
		map[temp]++;
	}
	if(map.size() == 2){
		auto begin = map.begin();
		auto end = ++map.begin();
		if((begin->second == 3 && end->second == 2) || (begin->second == 2 && end->second == 3)){
			cout << "Yes" << endl; return;
		}else{
			cout << "No" << endl;	
		}
	}else{
		cout << "No" << endl;
	}
}
int main(){
	solve();
	return 0;
}