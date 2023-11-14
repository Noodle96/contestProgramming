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
	vector<int> vec(n);
	for(int e = 0 ; e < n; e++) cin>>vec[e];
	sort(all(vec), [](const int &a, const int &b){
		return a > b;
	});
	// for(auto it = vec.begin(); it != vec.end() ; it++){
	// 	cout << *it << endl;
	// }
	// return;
	ll alicia = 0, bob = 0;
	for(int e = 0 ;e < n ; e++){
		if(e%2 == 0){
			//alicia
			if(vec[e]%2 == 0)  alicia += vec[e];
		}else{
			//bob
			if(vec[e]%2 == 1) bob += vec[e];
		}
	}
	ll diff =  alicia - bob;
	if(diff == 0){
		cout << "Tie" << endl;
	}else{
		if(diff > 0){
			cout << "Alice" << endl;
		}else{
			cout << "Bob" << endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}