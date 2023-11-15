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
ll F[N];
ll FF[N];

void fibonacciIterativo(){
	F[0] = 0; F[1] = 1;
	for(int e = 2; e <=N; e++){
		F[e] = F[e-1] + F[e-2];
	}
	for(int e = 0 ; e <= N; e++){
		cout << e << " " <<F[e] << endl;
	}
}
bool isComputed[100];
ll fibonacciRecursivo(int i){
	if(i<2) return i;
	if(isComputed[i]) return FF[i];
	FF[i] = fibonacciRecursivo(i-1) + fibonacciRecursivo(i-2);
	isComputed[i] = true;
	return FF[i];
}
void solve(){
	int n; cin>>n;
	cout << fibonacciRecursivo(n) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int e = 0 ; e < N; e++){
		isComputed[e] = false;
	}
	fibonacciIterativo();
	solve();
	return 0;
}