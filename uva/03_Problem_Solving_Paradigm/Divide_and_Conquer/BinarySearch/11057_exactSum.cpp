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
string line;
void solve(int n){
	vector<int> vec;
	vector<pii> solution;
	for(int e = 0,temp ;e < n ; e++){
		cin>>temp;
		vec.pb(temp);
	}
	int M; cin>>M;
	sort(all(vec));
	for(int e = 0 ; e < n; e++){
		int restante = M - vec[e];
		auto lb = lower_bound(all(vec), restante);
		int position = lb - vec.begin();
		if(e <= position){
			if(vec[position] == restante){
				solution.pb(mp( abs(vec[position]-vec[e]),vec[e] ));
			}
		}
	}
	sort(all(solution));
	cout << "Peter should buy books whose prices are " << solution[0].second << " and "  << M - solution[0].second << "." << endl;
	cout << endl;
	cin.ignore();
	getline(cin, line);

}

int main(){
	int n;
	while(cin>>n){
		solve(n);
	}
	return 0;
}