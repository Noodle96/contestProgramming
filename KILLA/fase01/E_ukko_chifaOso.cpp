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
	int n,k;cin>>n>>k;
	map<int,int> map;
	for(int e = 0,a ;e < n ; e++){
		cin>>a;
		map[a]++;
	}
	//find maximo
	int maximo = INT_MIN;
	int nroCubiertos = 0;
	for(auto it = map.begin(); it != map.end() ; it++){
		nroCubiertos += it->second;
		if(it->second > maximo) maximo = it->second;
	}
	int rondas = (maximo%k==0?maximo/k:(maximo/k +1));
	int total = (int)map.size()*k*rondas;
	cout << total - nroCubiertos << endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}