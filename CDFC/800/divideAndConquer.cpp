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
	vector<int> pares,impares;
	int suma = 0;
	for(int e = 0, temp ;e < n ; e++){
		cin>>temp; suma+= temp;
		if(temp &1) impares.pb(temp);
		else pares.pb(temp);
	}
	if(!(suma&1)){cout << 0 << endl;return;}
	sort(all(pares));
	sort(all(impares));

	// for (size_t i = 0; i < pares.size(); i++)
	// {
	// 	cout << pares[i] << " ";
	// }cout << endl;
	// for (size_t i = 0; i < pares.size(); i++)
	// {
	// 	cout << impares[i] << " ";
	// }cout << endl;
	

	int minimoPares = INT_MAX;
	if(!pares.empty()){
		for(int e = 0 ;e < pares.size() ; e++){
			auto f = pares[e];
			int contp = 0;
			while(!(f&1) ){ // mientras sea par
				// cout << "f: " << f << endl;
				contp++;
				f = f>>1;
			}
			minimoPares = min(minimoPares, contp);
		}
		
	}
	int minimoImpares = INT_MAX;
	if(!impares.empty()){
		for(int e = 0 ; e < impares.size(); e++){
			int conti = 0;
			auto f = impares[e];
			while(f&1 ){ // mientras sea impar
				conti++;
				f = f>>1;
			}
			minimoImpares = min(minimoImpares, conti);
		}
	}

	if(!pares.empty() && !impares.empty()){
		cout << min(minimoPares, minimoImpares) << endl; return;
	}
	// solo impares
	cout << minimoImpares << endl;

}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}