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
	int n,q; cin>>n>>q;
	string temp;
	vector<string> vec;
	for(int e = 0 ; e < n; e++){
		cin>>temp;
		vec.push_back(temp);
	}
	sort(all(vec));
	// for(auto it = vec.begin(); it != vec.end() ; it++){
	// 	cout << *it << " ";
	// }cout << endl;
	int pages;
	for(int e = 0 ;e < q ;  e++){
		cin>>temp>>pages;
		auto lb = lower_bound(vec.begin(), vec.end(), temp);
		int position = (lb - vec.begin());
		position++;
		// cout << position << endl;
		if(position%pages == 0){
			cout << position/pages << endl;
		}else{
			cout << position/pages +1 << endl;
		}

	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	// string data[]={"a","ab","ac","b","bb","bz","c"};
	// set<string> dictionary(data, data+7);
	// for(auto it = dictionary.begin(); it != dictionary.end() ; it++){
	// 	cout << *it << endl;
	// }
	// while(1){
	// 	string s; cin>>s;
	// 	auto lb = dictionary.lower_bound(s);
	// 	cout << std::distance(dictionary.begin(), lb) << endl;
	// }
	return 0;
}