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
//know if a number is a power of 2
bool isPowerOfTwo(int x){
	return !(x & (x-1));
}

//count the number of 1's in the binary representation of a number
int countSetBits(int x){
	int count = 0;
	while(x){
		x &= (x-1);
		count++;
	}
	return count;
}

// set turn on
int setBit(int x, int pos){
	return x | (1<<pos);
}

void solve(){
	/*
		View Felix Halim's book
	*/
	/*
		01.-bit representation of a number
	*/
	// int x ; cin>>x;
	// cout << "x: " << x << endl;
	// for(int e = 30; e>=0; e--){
	// 	if(x&(1<<e)) cout<<1;
	// 	else cout<<0;
	// }cout << endl<< endl;

	/*
		02.- Divide and Multiply by 2^pow
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int pow; cin>>pow;
	// cout << "pow: " << pow << endl;
	// cout << "x/2: " << (x>>pow) << endl;
	// cout << "x*2: " << (x<<pow) << endl;

	/*
		03.- Encender el bit pos(indexing 0) de un numero.
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int pos; cin>>pos;
	// cout << "pos: " << pos << endl;
	// x |= (1<<pos);
	// cout << "set bit: " << x << endl;

	/*
		4.- Verificar si el j-esimo bit de un numero esta encendido.
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int j; cin>>j;
	// cout << "j: " << j << endl;
	// int ans = x&(1<<j);
	// if(ans) cout << "j-th item of the set is on, ans: " << ans <<   endl;
	// else cout << "j-th item of the set is off, ans: " << ans <<  endl;

	/*
		5.- Apagar el j-esimo bit de un numero.
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int j; cin>>j;
	// cout << "j: " << j << endl;
	// x &= ~(1<<j);
	// cout << "x: " << x << endl;

	/*
		6.- Alternar el j-esimo bit de un numero.
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int j; cin>>j;
	// cout << "j: " << j << endl;
	// x ^= (1<<j);
	// cout << "x: " << x << endl;

	/*
		7.- Obtener el valor del bit menos significativo que esta
			encendido.
	*/
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// int ans = x&(-x);
	// cout << "ans: " << ans << endl;

	/*
		8.- __builtin_popcount(S) to count how many bits that are on in S
			and __builtin_ctz(S) to count how many trailing zeroes in S.
	*/
	int x; cin>>x;
	cout << "x: " << x << endl;
	cout << __builtin_popcount(x) << endl;

	//pow of 2
	// int x; cin>>x;
	// cout << "x: " << x << endl;
	// cout << "is power of 2: " << isPowerOfTwo(x) << endl;

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