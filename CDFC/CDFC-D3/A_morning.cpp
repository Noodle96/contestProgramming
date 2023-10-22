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

map<int,int>mapa;

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int  ar[4];
void solve(){
	string s; cin>>s;
	for(int e = 0 ; e < 4 ;e++){
		ar[e] = s[e] - '0';
	}
	for(int e = 0 ; e < 4 ;e++){
		if(ar[e] == 0) ar[e] = 10;
	}
	int ans = 0;
	int puntero =  mapa[1];
	for(int e = 0 ;e < 4 ;e++){
		ans += ( (abs(ar[e]-puntero))+1) ;
		puntero = mapa[ar[e]];		
	}
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	mapa[0]=10;
	mapa[1]=1;
	mapa[2]= 2;
	mapa[3]=3 ;
	mapa[4]=4 ;
	mapa[5]=5 ;
	mapa[6]=6 ;
	mapa[7]=7 ;
	mapa[8]=8 ;
	mapa[9]=9 ;
	mapa[10] = 10;
	int t; cin>>t;
	while(t--)solve();
	return 0;
}