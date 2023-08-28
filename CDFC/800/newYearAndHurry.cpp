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
const int N = 10;
int times[N];
void buildDp(){
	for(int e = 0 ; e < N; e++){
		times[e] = 5*(e+1);
	}
	for(int e = 1 ; e < N; e++){
		times[e] = times[e-1] + times[e];
	}
}

void solve(){
	int n,k; cin>>n>>k;
	int restante = 240 -k;
	auto lb = lower_bound(times, times+N, restante);
	int position = (lb-times);
	// cout << position << endl;
	if(times[position] == restante){
		if(position +1 >= n){
			cout << n<< endl;
		}else{
			cout << position + 1 << endl;
		}
		
	}else{
		if(position >= n){
			cout << n<< endl;
		}else{
			cout << position<< endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	buildDp();
	solve();
	return 0;
}