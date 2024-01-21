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


const int M = 200;
const int C = 20;
const int K = 20;

vector< vector<int> > garments;
vector< vector<int> > dp;

int m,c; 

int f(int position, int m_restante){
	// cout << "position: " << position << " m_Restante: " << m_restante << endl;
	if(m_restante < 0){
		// cout << "m_r4estante < 0 " << endl;
		return -100;
	}
	if(position == c ){
		// cout << "inside base case\n";
		// cout << "M-m: " << m-m_restante << endl;
		return m-m_restante;
	}
	int maximo = INT_MIN;
	int size = garments[position][0];
	for(auto e = 1 ; e <= size; e++){
		int result;
		if(m_restante-garments[position][e] >= 0 ){
			if(dp[position+1][m_restante-garments[position][e]] != -1){
				// cout << "inside condition" << endl;
				result = dp[position+1][m_restante-garments[position][e]];
			}else{
				result = f(position+1,m_restante-garments[position][e]);
				dp[position+1][m_restante-garments[position][e]] = result;
			}
			maximo = max(maximo, result);
		}
	}
	return maximo;
}



void solve(){
	// cout << "print dp: " << endl;
	// for(int  e = 0 ; e < C+1; e++){
	// 	for(int j = 0 ;j < M+1 ; j++){
	// 		cout << dp[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// return;
	garments.resize(C, vector<int>(K,0));
	for(auto e = 0 ;e < C ; e++){
		for(auto j = 0 ;j < K ; j++){
			garments[e][j] = 0;
		}
	}
	dp.resize(C+1, vector<int>(M+1, -1));
	for(auto e = 0 ;e < C+1 ; e++){
		for(auto j = 0 ;j < M+1 ; j++){
			dp[e][j] = -1;
		}
	}

	cin>>m>>c;
	for(int e = 0,len ; e < c; e++){
		cin>>len;
		garments[e][0]  = len;
		for(int j = 1 ; j <= len ; j++){
			cin>> garments[e][j];
		}
	}
	// for(){}
	// msg("print garments","");
	// for(int e = 0 ; e < c; e++){
	// 	int size = garments[e][0];
	// 	for(int j = 0  ;j <= size; j++){
	// 		cout << garments[e][j] << " ";
	// 	}cout << endl;
	// 	// for(auto it = garments[e].begin() ; it != garments[e].end(); it++){
	// 	// 	cout << *it << " ";
	// 	// }cout << endl;
	// }
	int ans = f(0,m);
	if(ans < 0){
		cout << "no solution" << endl;
	}else{
		cout << ans << endl;
	}
	// cout << "print dp after : " << endl;
	// for(int  e = 0 ; e < C+1; e++){
	// 	for(int j = 0 ;j < M+1 ; j++){
	// 		cout << dp[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// cout << dp[2][-1] << endl;
}

int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
		
	return 0;
}