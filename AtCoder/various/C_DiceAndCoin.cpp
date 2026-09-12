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

double binPow(double a, int b){
	if(b==0) return 1;
	double ans =binPow(a,b/2);
	if(b%2) return ans*ans*a;
	else return ans*ans;
}



int n,k;
void solve(){
	cin>>n>>k;
	double sum = 0.0;
	for(int i =  1;i <= n ; i++){
		int temp = i;
		int cont = 0;
		while(temp<k){
			temp*=2;
			cont +=1;
		}
		sum += binPow(0.5,cont);
	}
	sum /= n;
	printf("%.15f\n", sum);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}