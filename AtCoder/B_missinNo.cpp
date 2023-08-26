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
	vector<int > vec(n);
	int minimo  = INT_MAX;
	int maximo = INT_MIN;
	for(int e = 0 ; e < n; e++){
		cin>>vec[e];
	}
	sort(all(vec));
	for(int e = 0  ; e < n-1; e++){
		if(abs(vec[e] - vec[e+1]) != 1){
			cout << vec[e] +1 << endl;
			return;
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}