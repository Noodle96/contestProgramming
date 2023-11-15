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
	int n; cin>>n;
	vector<int> vec(n);
	int MIN = INT_MAX;
	int MAX = INT_MIN;
	int min_pos, max_pos;
	for(int e= 0; e<n ;e++){
		cin>>vec[e];
		if(vec[e] < MIN){
			min_pos = e;
			MIN = vec[e];
		}
		if(vec[e] > MAX){
			max_pos = e;
			MAX = vec[e];
		}
	}
	int leftleft = max(min_pos+1, max_pos+1); 
	// cout << leftleft << endl;
	int rightright = max(n-min_pos, n-max_pos);
	// cout << rightright << endl;
	int leftright = min_pos+1 + n-max_pos;
	// cout << leftright << endl;
	int rightleft = max_pos + 1 +  n-min_pos;
	// cout << rightleft << endl;
	cout << min(leftleft, min(rightright, min(leftright, rightleft))) << endl; 

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}