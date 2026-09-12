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
	int n; cin>>n;
	vector<int> vec(n);
	map<int,int> mapa;
	int max = -1e5;
	for(int e = 0,temp ; e < n; e++){
		cin>>temp;
		mapa[temp]++;
		vec[e] = temp;
		if(temp > max) max = temp;
	}

	int temp = vec[0];
	bool iguales = true;
	for(int e = 1 ;e < n ; e++){
		if(temp != vec[e]){
			 iguales = false;break;
		}
	}
	if(n == 1 ){cout << 0 << endl;return;}
	if(max == vec[0]){
		if( mapa[vec[0]] > 1){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
		return;
	}

	if(iguales){ cout << 1 << endl; return;}
	cout << max - vec[0] +1 << endl;
}
int main(){
	solve();
	return 0;
}