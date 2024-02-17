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
string ADN;
int q;
int a,b;
void solve(){
	cin>>ADN>>q;
	int n_ADN = (int)ADN.size();
	vector<int> prefix_A(n_ADN,0), prefix_T(n_ADN,0), prefix_G(n_ADN,0), prefix_C(n_ADN,0);
	//calculo de prefix
	prefix_A[0] = (ADN[0]== 'A'?1:0);
	prefix_T[0] = (ADN[0]== 'T'?1:0);
	prefix_G[0] = (ADN[0]== 'G'?1:0);
	prefix_C[0] = (ADN[0]== 'C'?1:0);
	for(int e = 1 ;e < (int)ADN.size() ;e++){
		prefix_A[e] = (ADN[e]=='A'?1:0) + prefix_A[e-1];
		prefix_T[e] = (ADN[e]=='T'?1:0) + prefix_T[e-1];
		prefix_G[e] = (ADN[e]=='G'?1:0) + prefix_G[e-1];
		prefix_C[e] = (ADN[e]=='C'?1:0) + prefix_C[e-1];
	}
	for(int e = 0 ; e < q; e++){
		vector<pair<char, int>> ans;
		cin>>a>>b;
		a--,b--;
		if(a==0){
			ans.pb({'A',prefix_A[b]});
			ans.pb({'B', prefix_T[b]});
			ans.pb({'C', prefix_G[b]});
			ans.pb({'D', prefix_C[b]});
		}else{
			ans.pb({'A',prefix_A[b]-prefix_A[a-1]});
			ans.pb({'B', prefix_T[b]-prefix_T[a-1]});
			ans.pb({'C', prefix_G[b]-prefix_G[a-1]});
			ans.pb({'D', prefix_C[b]-prefix_C[a-1]});
		}
		sort(all(ans), [](const pair<char, int> &a, const pair<char, int> &b){
			if(a.second == b.second){
				return a.first < b.first;
			}
				
			return a.second > b.second;
		});
		for(auto e: ans){
			if(e.first == 'A') cout << "A";
			if(e.first== 'B') cout << "T";
			if(e.first== 'C') cout << "G";
			if(e.first== 'D') cout << "C";
		}cout << endl;
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