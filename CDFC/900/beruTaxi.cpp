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
#define fi first
#define se second

double a,b;
vector<double>distancias;
vector<double> velocidad;
vector<double> tiempo;
double computeDistance(double x, double y){
	return  sqrt(pow(x-a,2) + pow(y-b,2));
}


int main(){
	double x,y; cin>>a>>b;
	int n; cin>>n;
	distancias.resize(n);
	velocidad.resize(n);
	tiempo.resize(n);
	for(int e = 0 ; e < n; e++){
		cin>>x>>y;
		distancias[e] = computeDistance(x,y);
		cin>>velocidad[e];
	}
	for(int e = 0 ; e < n; e++){
		tiempo[e] = distancias[e]/velocidad[e];
	}
	sort(all(tiempo));

	// std::cout << std::setprecision(5) << f << '\n';
	// std::cout << std::setprecision(9) << f << '\n';
	std::cout << std::fixed;
	std::cout << std::setprecision(20) << tiempo[0] << '\n';
	// cout << tiempo[0] << endl;

	return 0;
}