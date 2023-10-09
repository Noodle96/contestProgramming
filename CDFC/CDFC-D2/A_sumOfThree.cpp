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
	for(int num1 = 1; num1 < n ; num1++){
		for(int num2 = num1 +1 ; num2 < n ; num2++){
			int num3 = n - num1 - num2;
			if(num3 > 0){
				if(num1 != num2 && num1 != num3 && num2 != num3 && num1 %3 != 0 && num2 % 3!= 0 && num3 %3 != 0){
					cout << "YES\n";
					cout << num1 << " " << num2 << " " <<num3 << endl;
					return;
				}
			}
			
		}
	}
	cout << "NO\n" ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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