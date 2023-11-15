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
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1 == x2){
		int d = abs(y2-y1);
		cout << d +x1<< " " << y1 << " " << d+x1 << " " << y2 << endl;
	}else if(y1 == y2){
		int d = abs(x2-x1);
		cout << x1 << " " << d+y1 << " " << x2 << " " << d+y1 << endl;
	}else{
		if( abs(x1-x2) != abs(y2-y1)){
			cout << -1 << endl;
		}else{
			cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}