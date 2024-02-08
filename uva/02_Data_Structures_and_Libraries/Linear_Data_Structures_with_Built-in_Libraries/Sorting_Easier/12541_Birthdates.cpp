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
int n;
struct Person{
	string name;
	int dia;
	int mes;
	int anhio;
};

bool cmp(Person a, Person b){
	if(a.anhio != b.anhio) return a.anhio < b.anhio;
	if(a.mes != b.mes) return a.mes < b.mes;
	return a.dia < b.dia;
}
void solve(){
	cin>>n;
	vector<Person> vec(n);
	for(int e = 0 ;e < n ;e++){
		cin>>vec[e].name>>vec[e].dia>>vec[e].mes>>vec[e].anhio;
	}
	sort(all(vec), [](const Person &a, const Person &b){
		if(a.anhio == b.anhio){
			if(a.mes == b.mes){
				return a.dia > b.dia;
			}
			return a.mes > b.mes;
		}
		return a.anhio > b.anhio;
	});
	cout << vec[0].name <<endl;
	cout << vec[n-1].name << endl;
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