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
#define fi first
#define se second
void solve(){
	vector<int> vec(4);
	bool zero = false;
	int sumaTotal = 0;
	for(int e = 0 ;e < 4 ; e++){
		cin>>vec[e];
		if(vec[e] == 0) zero = true;
		sumaTotal += vec[e];
	}
	if(zero){
		cout << "Yes" << endl; return;
	}
	if(sumaTotal ==0 ){
		cout << "Yes" << endl; return;
	}
	//(a,b)
	for(int e = 0 ;e < 4 ; e++){
		for(int j = e+1 ; j < 4; j++){
			if(vec[e] + vec[j] == 0){cout << "Yes" << endl; return;}
		}
	}
	//(a,b,c)
	for(int e = 0 ;e < 4 ; e++){
		for(int j = e+1 ;j <4 ; j++){
			for(int k = j+1 ;k < 4 ; k++){
				if(vec[e]+vec[j]+vec[k] == 0){cout << "Yes" << endl; return;}
			}
		}
	}
	cout << "No" << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}