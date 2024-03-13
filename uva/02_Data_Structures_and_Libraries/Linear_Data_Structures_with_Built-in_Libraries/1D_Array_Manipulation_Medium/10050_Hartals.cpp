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
int N,P,h;
void solve(){
	cin>>N>>P;
	vector<bool> vec(N+1);
	for(int e = 0 ; e < P; e++){
		cin>>h;
		int incr = h;
		while(h <=N){
			if(h%7 == 0 || (h+1)%7 == 0){;}
			else{
				vec[h] = true;
			}
			h+=incr;
		}
	}
	int cont = 0;
	for(int e = 1 ; e < N+1; e++){
		if(vec[e]) cont++;
	}
	cout << cont << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}