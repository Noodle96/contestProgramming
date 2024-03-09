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
ll num;
void solve(){
	cout << "PERFECTION OUTPUT" << endl;
	while(cin>>num){
		if(num == 0){
			printf("END OF OUTPUT\n");
			break;
		}
		//divisores de n
		vector<ll> divisores;
		for(ll e = 1; e*e <= num ; e++){
			if(num%e == 0){
				if(e == num/e) divisores.pb(e);
				else{
					divisores.pb(e); divisores.pb(num/e);
				}
			}
		}
		sort(all(divisores));
		divisores.pop_back();
		ll sum = accumulate(all(divisores),0);
		if(sum == num) printf("%5d  PERFECT\n",num);
		else if(sum < num) printf("%5d  DEFICIENT\n",num);
		else printf("%5d  ABUNDANT\n",num);
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