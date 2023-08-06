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
// 1 7 2 11 15

void solve(){
	int n; cin>>n;
	vector<int> vec(n);
	for(int e = 0 ;e < n ;e++) cin>>vec[e];
	int cont = 1;
	int maxIncrease = 1;
	for(int e = 0 ; e < n-1; e++){
		if(vec[e] < vec[e+1]){
			cont++;
			maxIncrease = max(cont,maxIncrease);
		}else{
			cont = 1;
		}
	}
	cout << maxIncrease << endl;

}
int main(){
	solve();
	return 0;
}