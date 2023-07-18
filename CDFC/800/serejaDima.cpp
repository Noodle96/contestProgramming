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
	int n; cin>>n;
	vector<int> vec(n);
	for(auto &e:vec)cin>>e;
	
	int e = 0, j = n-1;
	int caso = 0;
	int sereja = 0, dima = 0;
	while(caso < n){
		if(caso&1){ //caso dima
			if(vec[e] >= vec[j]){
				dima +=vec[e];
				e++;
			}else{
				dima+= vec[j];
				j--;
			}
		}else{ // caso sereja
			if(vec[e] >=vec[j]){
				sereja += vec[e];
				e++;
			}else{
				sereja += vec[j];
				j--;
			}
		}
		caso ++;
	}
	cout << sereja << " " << dima << endl;
}

int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}