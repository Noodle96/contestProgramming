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
#define fi first
#define se second

int calculate(int a,int b, int c, int x){
	int t = 1,pausa = 1;
	int cont = 0;
	while(t <= x){
		if(pausa <= a){
			cont +=b;
			pausa++;
			t++;
		}else{
			pausa = 1;
			t+=c;
		}
	}
	// cout << "cont: " <<cont << endl;
	return cont;
}
void solve(){
	int a,b,c,d,e,f,x;
	cin>>a>>b>>c>>d>>e>>f>>x;
	int takahashi = calculate(a,b,c,x);
	int aoki = calculate(d,e,f,x);
	if(takahashi > aoki){cout << "Takahashi\n"; return;}
	else if(takahashi < aoki){ cout << "Aoki\n"; return;}
	else{cout << "Draw\n";}
}
int main(){
	solve();
	return 0;
}