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

int days[] = {0,31,28,31,30,31,30,31,31,30,31,30};
string day[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
vector<int> prefixDays(12,0);
int a,b;

void solve(){
	cin>>a>>b;
	int totalDays = prefixDays[a-1] + b;
	totalDays %= 7;
	if(totalDays <= 0) totalDays += 7;
	cout << day[totalDays-1] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	for(int e = 1 ; e < 12;e++){
		prefixDays[e] = prefixDays[e-1] + days[e];
	}
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}