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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	string s; cin>>s;
	vector<int> vec((int)s.size());
	for(int e = 0 ; e < s.size(); e++){
		vec[e] = s[e];
	}
	// for(auto it = vec.begin(); it != vec.end() ; it++){
	// 	cout << *it << endl;
	// }
	sort(all(vec));
	int temp =  vec[0];
	for(int e = 1 ; e < (int)s.size(); e++){
		if(vec[e] - temp != 1){
			cout << "No"<< endl; return;
		}
		temp = vec[e];
	}
	cout <<"Yes" << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--)solve();
	return 0;
}