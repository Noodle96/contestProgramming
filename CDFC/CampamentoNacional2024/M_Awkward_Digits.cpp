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
ll convertDecimal(string num, int base){
	int n = num.size();
	ll res = 0;
	for(int i = 0; i < n; i++){
		res += (num[i]-'0')*pow(base,n-i-1);
	}
	return res;
}
void solve(){
	string base2, base3;
	cin>>base2>>base3;
	int n_b2 = base2.size();
	int n_b3 = base3.size();
	set<ll> set;
	for(int e = 0 ; e < n_b2; e++){
		string str_temp;
		str_temp = base2;
		str_temp[e] = (str_temp[e] == '0') ? '1' : '0';
		bitset<64> b2(str_temp);
		ll num = b2.to_ulong();
		set.insert(num);
	}
	// print set
	// for(auto it = set.begin(); it != set.end(); it++){
	// 	cout << *it << " ";
	// }

	for(int e = 0 ; e < n_b3; e++){
		string str_temp;
		str_temp = base3;
		if(str_temp[e] == '2'){
			str_temp[e] = '0';
			int num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
			str_temp[e] = '1';
			num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
		}else if(str_temp[e] == '1'){
			str_temp[e] = '0';
			int num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
			str_temp[e] = '2';
			num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
		}else{ // str_temp[e] == 0
			str_temp[e] = '1';
			int num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
			str_temp[e] = '2';
			num = convertDecimal(str_temp,3);
			if(set.find(num) != set.end()){
				cout << num << endl;
				break;
			}
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