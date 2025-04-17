/*
==========================================================
|  Archivo       : A_Odd_One_Out.cpp                        
|  Autor         : Russell                               
|  Fecha         : 2025-04-17
|  Hora          : 15:41     
|--------------------------------------------------------
|  Tópicos utilizados:                           
|  - bitmask
|  - implementation
|  - *800
==========================================================
*/
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
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
    array<int,3> a;
    cin>>a[0]>>a[1]>>a[2];
    vector<int> bitsOfNumbers(4);
    for(int e = 0 ;e < 3 ; e++){
        for(int j = 0 ; j < 4; j++){
            if( (a[e] >> j) & 1 ) bitsOfNumbers[j]++;
        }
    }
    int ans = 0;
    for(int e = 0 ;e < 4 ; e++){
        if(bitsOfNumbers[e] == 1 || bitsOfNumbers[e] == 3){
            ans += (1<<e);
        }
    }
    cout << ans << endl;
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