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
int arr[9][9];

bool t(int t, int r){
	int ls = t+3;
	int ls2 = r+3;
	map<int,int> map;
	for(int e = t;e< ls ; e++){
		for(int j = r ;j < ls2 ; j++ ){
			map[arr[e][j]]++;
		}
	}
	return map.size() == 9;
}

void solve(){
	for(int e = 0 ;e < 9 ; e++)
		for(int j = 0 ; j < 9; j++)
			cin>> arr[e][j];
	for(int e = 0 ; e < 9; e++){
		map<int, int> map;
		for(int j = 0 ; j < 9; j++){
			map[arr[e][j]]++;
		}
		if(map.size() != 9){
			cout << "No" << endl; return;
		}
		map.clear();
	}
	for(int j = 0 ; j < 9; j++){
		map<int, int> map;
		for(int e = 0 ; e < 9; e++){
			map[arr[e][j]]++;
		}
		if(map.size() != 9){
			cout << "No" << endl; return;
		}
		map.clear();
	}
	//division de cada tres
	for(int e = 0 ; e < 9; e+=3){
		for(int j = 0 ; j < 9; j+=3){
			bool ans = t(e,j);
			if(!ans){
				cout << "No" << endl; return;
			}
		}
	}
	cout << "Yes" << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}