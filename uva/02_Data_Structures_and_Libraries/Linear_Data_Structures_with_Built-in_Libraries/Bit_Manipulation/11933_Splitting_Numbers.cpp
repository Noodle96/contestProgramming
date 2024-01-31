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
	int n;
	while(1){
		cin>>n;
		if(n == 0) break;
		else{
			bitset<31> bs(n);
			bitset<31> a,b;
			bool flag = 1;
			// cout << bs << endl;
			for(int e = 0; e <=30; e++){
				if(bs[e] == 1){
					if(flag){
						a.set(e,1);
						flag = false;
					}else{
						b.set(e,1);
						flag = 1;
					}
				}
			}
			// cout << a << endl;
			// cout << b << endl;
			cout << a.to_ulong() << " " << b.to_ulong() << endl;
		}
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