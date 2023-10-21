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
	map<int, int> map01;
	vector<int> vec(n);
	for(int e = 0,tmp ; e < n; e++){
		cin>>tmp;
		map01[tmp]++;
		vec[e] = tmp;
	}
	int sz = map01.size();
	map<int,int> map02;
	for(int e = n-1;e >= 0 ; e--){
		map02[vec[e]]++;
		if(map02.size() == sz){
			cout << vec[e] << endl;
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