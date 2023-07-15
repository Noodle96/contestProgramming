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

string compare(string a, string b){
	string result = "";
	for(int e = 0 ; e < a.size() ;e++){
		if( (a[e] - '0' <=2 && b[e]-'0' <= 2) || (a[e]-'0' >=7 && b[e]-'0' >= 7)  ) result+="0";
		else result+="9";
	}
	return result;
}
string getZeros(int t){
	string result;
	for(int e = 0 ;e < t ; e++){
		result += "0";
	}
	return result;
}
void solve(){
	string a,b; cin>>a>>b;
	if(a.size() ==  b.size()){
		cout << compare(a,b) << endl; return;
	}else{
		int size_a = a.size();
		int size_b = b.size();
		int max_len = max(size_a, size_b);
		if(size_a > size_b){
			b = getZeros(size_a-size_b) + b;
			cout << compare(a,b) << endl; return;
		}else{
			a = getZeros(size_b - size_a) + a;
			cout << compare(a,b) << endl; return;
		}
	}
}
int main(){
	solve();
	// cout << compare("22776", "15954") <<endl;
	return 0;
}