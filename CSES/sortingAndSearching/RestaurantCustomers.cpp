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
const int N = 4e5;
pair<int,bool> arr_p[N];
int n;
void solve(){
	cin>>n;
	for(int e = 0 ; e < 2*n; e+=2){
		cin>>arr_p[e].first; arr_p[e].second = true;
		cin>>arr_p[e+1].first; arr_p[e+1].second = false;
	}
	sort(arr_p, arr_p+2*n, [&](pair<int, bool> &pair1,pair<int, bool> &pair2){
		return pair1.first < pair2.first;
	});
	// for(int e = 0 ;e < 2*n ; e++){
	// 	cout << arr_p[e].first << " " << arr_p[e].second << endl;
	// }
	int ans = INT_MIN;
	int temp = 0;
	for(int e = 0 ;e < 2*n  ;e++){
		if(arr_p[e].second){
			temp++;
			ans = max(ans, temp);
		}
		else temp--;
	}
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}