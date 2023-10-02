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
	int n; cin>>n;
	int sum = 0;
	vector<int> vec(n);
	for(int e =0; e<n; e++){
		cin>> vec[e];
		sum += vec[e];
	}
	sort(vec.begin(), vec.end(), greater<int>());
	for(int e = 1 ;e < n ; e++){
		vec[e] = vec[e-1]+vec[e];
	}
	int cont = 0;
	int e = 0;
	for(;e< n ;e++){
		if(vec[e] > sum/2){
			cout << e+1 << endl;
			return;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();	
	return 0;
}
// 2 2 2 2 4
// 2 4 6 8 12