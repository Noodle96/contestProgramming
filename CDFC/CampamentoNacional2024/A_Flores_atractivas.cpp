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
	vector<int> a(n);
	for(int e = 0,val ; e < n; e++){
		cin>>val;
		if(val & 1) a[e] = val;
		else a[e] = val-1;
	}
	sort(all(a), [](int x, int y){
		return x > y;
	});
	if((int)a.size() & 1){
		auto sum = accumulate(all(a),0);
		cout << sum << endl;
	}else{
		auto sum = accumulate(a.begin(), a.end()-1,0);
		cout << sum << endl;
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