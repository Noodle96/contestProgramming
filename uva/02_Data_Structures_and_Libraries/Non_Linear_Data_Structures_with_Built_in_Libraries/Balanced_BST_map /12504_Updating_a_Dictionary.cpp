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
map<string , string> old,neww;

pair<string,string> split(string str){
	pair<string, string> p;
	auto it = find(all(str), ':');
	p.first = str.substr(0,it-str.begin());
	p.second = str.substr(it-str.begin()+1); // desde it hasta el final
	// cout << "first: " << p.first << " second: " << p.second << endl;
	return p;
}

void tokenizarOldDictionary(string str){
	str = str.substr(1,str.size()-2);
	// cout << str << endl;
	stringstream ss(str);
	string token;
	while(getline(ss,token,',')){
		auto [key, value] = split(token);
		old[key] = value;
	}
}
void tokenizarNewDictionary(string str){
	str = str.substr(1,str.size()-2);
	stringstream ss(str);
	string token;
	while(getline(ss,token,',')){
		auto [key, value] = split(token);
		neww[key] = value;
	}
}

void solve(){
	string s_old, s_neww;
	getline(cin,s_old);
	getline(cin,s_neww);
	// cout << "old: " << old << endl;
	// cout << "new: " << neww << endl;
	tokenizarOldDictionary(s_old);
	tokenizarNewDictionary(s_neww);
	// print old
	// for(auto e: ::old){
	// 	cout << e.first << " " << e.second << endl;
	// }cout << endl;
	// //print neww
	// for(auto e: ::neww){
	// 	cout << e.first << " " << e.second << endl;
	// }cout << endl;
	
	// comparacion del old con el nuevo:
	// eliminados y modificados
	vector<string> eliminados, modificados, agregados;
	for(auto e: ::old)	{
		if(::neww.count(e.first) > 0 ){// existe
			if(::neww[e.first] != e.second){ // modificado
				modificados.pb(e.first);
			}
		}else{ // eliminado
			eliminados.pb(e.first);
		}
	}
	// comparacion entre el nuevo y el antiguo para ver los agregados
	for(auto e: ::neww){
		if(::old.count(e.first) == 0){
			agregados.pb(e.first);
		}
	}
	if(eliminados.size() == 0 && modificados.size() == 0 && agregados.size() == 0){
		cout << "No changes" << endl;
	}else{
		int e;
		if(agregados.size() > 0){
			cout << '+';
			e = 0;
			for( ; e < (int)agregados.size()-1; e++){
				cout << agregados[e] << ',';
			}cout << agregados[e] << endl;
		}
		if(eliminados.size()  > 0){
			cout << '-';
			e = 0;
			for(;e < (int)eliminados.size() -1; e++){
				cout << eliminados[e] << ",";
			}cout << eliminados[e] << endl;
		}
		if(modificados.size() >  0){
			cout << "*";
			e = 0;
			for(;e < (int)modificados.size() -1; e++){
				cout << modificados[e] << ",";
			}cout << modificados[e] << endl;
		}
	}
	::old.clear();
	::neww.clear();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	cin.ignore();
	while(t--){
		solve();
		// if(t > 0) cout << endl;
		cout << endl;
	}

	return 0;
}