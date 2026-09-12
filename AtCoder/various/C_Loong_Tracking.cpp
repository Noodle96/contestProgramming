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

int n,q;
void solve(){
	cin>>n>>q;
	deque<pair<int,int>> P;
	for(int e = 1 ; e <= n; e++){
		P.pb({e,0});
	}
	// cout << "P: " << endl;
	// for(auto p : P){
	// 	cout << "("<< p.first << "," << p.second << ") ";
	// }cout << endl;
	// return;
	int val,pos; char ch;
	for(int e = 0 ; e < q; e++){
		cin>>val;
		if(val == 1){
			cin>>ch;
			auto p_temp = *P.begin();
			if(ch == 'R'){
				p_temp.first++;
			}else if(ch == 'U'){
				p_temp.second++;
			}else if(ch == 'L'){
				p_temp.first--;
			}else{
				p_temp.second--;
			}
			P.push_front(p_temp);
			P.pop_back();
			// cout << "P: " << endl;
			// for(auto p : P){
			// 	cout << "("<< p.first << "," << p.second << ") ";
			// }cout << endl;
		}else{
			cin>>pos;
			pos--;
			cout << P[pos].first << " " << P[pos].second << endl;
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