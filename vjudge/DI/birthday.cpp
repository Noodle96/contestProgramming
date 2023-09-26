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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
bool comp(pair<string , pair<int, pair<int,int>>> &a, pair<string , pair<int, pair<int,int>>> &b){
	if( a.second.first == b.second.first){
		if(a.second.second.first == b.second.second.first){
			return a.second.second.second > b.second.second.second;
		}
		return a.second.second.first > b.second.second.first;
	}
	return a.second.first > b.second.first;
}

void solve(){
	int n; cin>>n;
	vector<  pair<string , pair<int, pair<int,int>>> > data;
	string name;
	for(int e = 0, year,month,day ; e < n; e++){
		cin>> name >>day>>month>>year;
		data.push_back(make_pair(name, make_pair(year, make_pair(month,day))));
	}
	sort(data.begin(), data.end(), comp);
	cout << data[0].first << "\n" << data[n-1].first << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}