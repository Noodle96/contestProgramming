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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<string,int> mapa;
	mapa["tourist"] = 3858;
	mapa["ksun48"] = 3679;
	mapa["Benq"] = 3658;
	mapa["Um_nik"] = 3648;
	mapa["apiad"] = 3638;
	mapa["Stonefeang"] = 3630;
	mapa["ecnerwala"] = 3613;
	mapa["mnbvmar"] = 3555;
	mapa["newbiedmy"] = 3516;
	mapa["semiexp"] = 3481;
	string S;
	cin>>S;
	cout << mapa[S] << endl;

	return 0;
}