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
	int m; cin>>m;
	int total = 0;
	vector<int> vec(m);
	for(int e = 0 ; e <(int)vec.size();e++){
		cin>>vec[e];
		total += vec[e];
	}
	vector<int> pref(m);
	pref[0] = vec[0];
	for(int e = 1; e < m; e++){
		pref[e] = pref[e-1] + vec[e];
	}
	// cout << "print pref" << endl;
	// for(int e =0 ; e< pref.size(); e++){
	// 	cout << pref[e] << " ";
	// }cout << endl;


	int factor;
	if(total &1) factor = total/2 +1;
	else factor = total /2;
	
	auto lb = lower_bound(all(pref), factor);
	int position = (lb-pref.begin());

	// if(pref[position] == factor){
	// 	cout << position +1 <<  " " << factor - pref[position-1] << endl;
	// }else{
	// 	cout << position +1 << " " << factor - pref[position-1] << endl;
	// }
	cout << position +1 <<  " " << factor - pref[position-1] << endl;



}
int main(){
	solve();
	return 0;
}