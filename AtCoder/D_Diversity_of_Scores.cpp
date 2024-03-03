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
int N,T;

void solve(){
	cin>>N>>T;
	vector<ll> points(N);
	map<ll,int> hash;
	hash[0] = N;
	for(int e = 0 ; e < T; e++){
		int a,b;
		cin>>a>>b;
		a--;
		--hash[points[a]];
		if(hash[points[a]] == 0) hash.erase(points[a]);
		points[a] += b;
		++hash[points[a]];
		cout << hash.size() << endl;
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