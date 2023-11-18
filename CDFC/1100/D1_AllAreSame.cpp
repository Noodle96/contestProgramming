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
	int n; cin>>n;
	map<int, int> map;
	for(int e= 0, temp ; e<n; e++){
		cin>>temp;
		map[temp]++;
	}
	if(map.size() == 1){cout << -1 << endl; return;}
	// msg("Print mapa","");
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }

	vector<int> vec;
	auto it = map.begin();
	auto dataFirst = it->first;
	it++;
	for(; it != map.end() ; it++){
		vec.pb(it->first - dataFirst);
	}
	if(map.size() == 2){
		cout << vec[0] << endl; return;
	}
	vector<int> divisores;
	for(int i = 1;i*i<= vec[0] ; i++){
		if(vec[0]%i == 0){
			if(vec[0]/i == i) divisores.pb(i);
			else{
				divisores.pb(i); divisores.pb(vec[0]/i);
			}
		}
	}
	sort(all(divisores), [](const int &a, const int &b){
		return a > b;
	});

	// msg("printDivisores","");
	// for(auto it = divisores.begin(); it != divisores.end() ; it++){
	// 	cout << *it << endl;
	// }
	// msg("print vec","");
	// for(auto e: vec){
	// 	cout << e << " ";
	// }cout << endl;
	for(int e = 0 ; e < divisores.size(); e++){
		int cont = 0;
		for(int j = 0 ;j < vec.size() ; j++){
			if(vec[j]%divisores[e] == 0) cont++;
		}
		if(cont == vec.size()){
			cout << divisores[e] << endl; return;
		}
	}
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