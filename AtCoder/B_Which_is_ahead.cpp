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
int n,pi,pj,q;
map<int,int> mapa;
void solve(){
	cin>>n;
	for(int e = 0 ; e < n; e++){
		cin>>pi;
		mapa[pi] = e;
	}
	cin>>q;
	for(int e = 0 ;e < q ; e++){
		cin>>pi>>pj;
		if(mapa[pi] < mapa[pj]) cout << pi << endl;
		else cout << pj << endl;
	}

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