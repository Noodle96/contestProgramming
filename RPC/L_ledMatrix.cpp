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
int r,c,k;
const int N = 1e3+5;
char led[N][N];
char pattern[N][N];
string m,p;
void solve(){
	cin>>r>>c>>k;
	for(int e = 0 ; e < r; e++){
		cin>>m>>p;
		for(int j = 0 ; j < c; j++){
			led[e][j] = m[j];
		}
		for(int j = 0 ; j < k; j++){
			pattern[e][j] = p[j];
		}
	}
	
	// cout << "print ma" << endl;
	// for(int e =0 ;e < r ; e++){
	// 	for(int j = 0 ;j < c ; j++){
	// 		cout << led[e][j] <<" ";
	// 	}cout << endl;
	// }cout << endl << endl;
	// for(int e =0 ;e < r ; e++){
	// 	for(int j = 0 ;j < k ; j++){
	// 		cout << pattern[e][j] <<" ";
	// 	}cout << endl;
	// }cout << endl << endl;
	vector<bool> colCheckLed(r);
	for(int e = 0 ; e < r; e++){
		bool flag = true;
		for(int j = 0 ; j < c; j++){
			if(led[e][j] == '-'){
				flag = false;
				break;
			}
		}
		colCheckLed[e] = flag;
	}

	vector<bool> inPatternContainAsterisk(r);
	for(int e = 0 ; e < r; e++){
		bool flag = false;
		for(int j = 0 ; j < k; j++){
			if(pattern[e][j] == '*'){
				flag = true;
				break;
			}
		}
		inPatternContainAsterisk[e] = flag;
	}
	for(int e = 0 ; e < r ;e++){
		if(inPatternContainAsterisk[e]){
			if(!colCheckLed[e]){
				cout << "N" << endl;
				return;
			}
		}
	}
	cout << "Y" << endl;
	
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

// ****** --*
// ****** -**
// ****** ***
// ****** ***
// ****** -**
// *****- --*