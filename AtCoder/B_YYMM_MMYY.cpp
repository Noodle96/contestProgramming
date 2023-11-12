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
int ar[4];
char ch;

bool isMes(int a, int b){
	if(a == 0 & (b<=9 & b>0)) return true;
	if(a == 1 & (b<=2 & b> 0)) return true;
	return false;
}


void solve(){
	for(auto e =0 ; e< 4; e++){
		cin>>ch;
		ar[e] = ch-'0';
	}
	if( isMes(ar[0],ar[1]) ){
		if( isMes(ar[2],ar[3]) ){
			cout << "AMBIGUOUS" <<endl;
		}else{
			cout << "MMYY" << endl;
		}
	}else{
		if(isMes(ar[2], ar[3])){
			cout << "YYMM" << endl;
		}else{
			cout << "NA" << endl;
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}