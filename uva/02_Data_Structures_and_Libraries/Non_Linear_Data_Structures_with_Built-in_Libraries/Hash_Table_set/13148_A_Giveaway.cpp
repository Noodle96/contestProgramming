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
std::unordered_map<ll, int> hashTable;
void solve(){
	ll a;
	while(1){
		cin>>a;
		if(a == 0) break;
		if(hashTable[a] == 1) cout << "Special" << endl;
		else cout << "Ordinary" << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// Agregar elementos a la tabla hash con frecuencia 1
	hashTable[1] = 1;
	hashTable[64] = 1;
	hashTable[729] = 1;
	hashTable[4096] = 1;
	hashTable[15625] = 1;
	hashTable[46656] = 1;
	hashTable[117649] = 1;
	hashTable[262144] = 1;
	hashTable[531441] = 1;
	hashTable[1000000] = 1;
	hashTable[1771561] = 1;
	hashTable[2985984] = 1;
	hashTable[4826809] = 1;
	hashTable[7529536] = 1;
	hashTable[11390625] = 1;
	hashTable[16777216] = 1;
	hashTable[24137569] = 1;
	hashTable[34012224] = 1;
	hashTable[47045881] = 1;
	hashTable[64000000] = 1;
	hashTable[85766121] = 1;
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}