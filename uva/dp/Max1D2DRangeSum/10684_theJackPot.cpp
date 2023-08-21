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
void solve(int n){
	vector<int> vec(n);
	for(int e = 0 ; e < n; e++){
		cin>>vec[e];
	}
	int maximo = INT_MIN;
	int suma = 0;
	for(int e = 0 ;e < n ; e++){
		suma += vec[e];
		maximo = max(maximo,suma);
		if(suma < 0) suma = 0;
	}
	if(maximo <= 0){
		cout << "Losing streak." <<endl;
	}else{
		cout << "The maximum winning streak is "<< maximo <<"." << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int n;
	while(cin>>n){
		if(n==0) break;
		solve(n);
	}
	return 0;
}