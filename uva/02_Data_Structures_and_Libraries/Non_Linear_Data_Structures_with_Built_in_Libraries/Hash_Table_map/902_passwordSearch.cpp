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
int a; 
string str;
map<string,int> mapa;
int maximoRepetido = INT_MIN;
void solve(){
	while(cin>>a>>str){
		int n = str.size();
		for(int e = 0 ;e <= n-a ; e++){
			string tmp = str.substr(e,a);
			mapa[tmp]++;
		}
		string str2;
		for(auto it = mapa.begin();it!=mapa.end();it++){
			if(it->second > maximoRepetido){
				maximoRepetido = it->second;
				str2 = it->first;
			}
		}
		cout << str2 << endl;
		mapa.clear();
		maximoRepetido = INT_MIN;
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