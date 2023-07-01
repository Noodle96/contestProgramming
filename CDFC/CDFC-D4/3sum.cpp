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

vector< vector<int> > triples;

void solve(){
	// msg("cont: ", cont);
	// for(auto it = triples.begin(); it != triples.end() ; it++){
	// 	for(auto et = it->begin() ;et != it->end() ; et++){
	// 		cout << *et << " ";
	// 	}cout << endl;
	// }
	int n;cin>>n;
	int temporal;
	// vector<int> dp(10,0);
	map<int,int> mapa;
	for(int e = 0 ;e < n ; e++){
		cin>>temporal;
		mapa[temporal%10]++;
		// dp[temporal%10] = 1;
	}
	// msg("dp","");
	// for(auto it = dp.begin(); it != dp.end() ; it++){
	// 	cout << *it << " ";
	// }cout << endl;
	// msg("endp","");
	vector<int> vec_temp;
	for(auto it=triples.begin() ; it != triples.end(); it++){
		int cont = 0;
		vec_temp.clear();
		for(auto et = it->begin() ; et != it->end(); et++){
			// if(dp[*et] == 1) cont++;
			if(mapa[*et] >= 1) {
				cont++;
				mapa[*et]--; vec_temp.pb(*et);
			}
		}
		//add values 
		for(int e = 0 ; e < vec_temp.size(); e++){
			mapa[vec_temp[e]]++;
		}
		if(cont == 3){msg("YES",""); return;}
	}
	msg("NO","");

}
int main(){
	vector<int> temp(3);
	// int cont=0;
	for(int e = 0 ; e < 10; e++){
		for(int j = 0  ;j < 10 ; j++){
			for(int k = 0 ; k < 10; k++){
				if((e+j+k)%10 == 3){
					// cont++;
					temp[0] = e; temp[1] = j; temp[2]=k;
					triples.push_back(temp);
				}
			}
		}
	}
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
