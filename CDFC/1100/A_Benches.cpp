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

const int N = 100;
int n,m,MAX = INT_MIN,total,goal;
int min_k, max_k;
int benches[N];
void solve(){
	cin>>n>>m;
	for(int e = 0,temp ; e<n;e++){
		cin>>temp;
		MAX = max(MAX, temp);
		total += temp;
	}
	goal = total + m;
	min_k = max ( ( goal%n==0?goal/n:(goal/n)+1), MAX);
	max_k = MAX + m;
	cout << min_k << " " << max_k << endl;

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