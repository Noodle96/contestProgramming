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
	int cont = 0;
	int n,i; cin>>n>>i;
	vector<bool> A(n);
	bool temp;
	for(int e = 0 ; e < n; e++){
		cin>>temp;
		A[e] = temp;
	}
	int left = i-1;
	int right = n-i;
	if(right >= left){
		int e = 0;
		for(; e < left;e++ ){
			if(A[i+e] & A[i-2-e]) cont+=2;
		}
		for(;e < right ; e++){
			if(A[i+e]) cont++;
		}
	}else{ //right < left
		int e = 0;
		for(; e < right; e++){
			if(A[i+e] & A[i-2-e]) cont+=2;
		}
		for(;e < left ; e++){
			if(A[i-2-e]) cont++;
		}
	}
	cont += (A[i-1]==1?1:0);
	cout <<cont << endl;

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