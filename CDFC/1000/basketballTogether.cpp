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
	int N,D; cin>>N>>D;
	vector<int> vec(N);
	for(int e = 0 ; e < N; e++)cin>>vec[e];

	sort(all(vec));
	int teams = 0;
	while(1){
		if(vec.size() > 0){
			if(vec[vec.size()-1] > D){
				vec.pop_back(); teams ++;
			}else{
				int a;
				if((D+1)%vec[vec.size()-1] == 0){
					a = ((D+1)/vec[vec.size()-1]);
				}else{
					a = ((D+1)/vec[vec.size()-1]) +1;
				}
				
				if(a<= vec.size() ){
					vec.pop_back();
					vec.erase(vec.begin(), vec.begin() + (a-1));
					teams++;
				}else break;
			}
		}else break;
	}
	cout << teams << endl;
}

int main(){
	solve();
	return 0;
}