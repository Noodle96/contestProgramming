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

int main(){
	string s1,s2; cin>>s1>>s2;
	int cont = 0;
	for(int e = 0 ;e < s1.size() ; e++){
		if(s1[e] != s2[e]) cont++;
	}
	cout << cont << endl;
	return 0;
}