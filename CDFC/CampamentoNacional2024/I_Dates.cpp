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
void processWithPoint(string str, string &first, string &second, string &third){
	stringstream ss(str);
	getline(ss,first,'.');
	getline(ss,second,'.');
	getline(ss,third,'.');
}

void processWithSlash(string str, string &first, string &second, string &third){
	stringstream ss(str);
	//str = "12.12.12";
	getline(ss,first,'/');
	getline(ss,second,'/');
	getline(ss,third,'/');
}

bool containPoint(string &str){
	for(int e =0 ; e < str.size(); e++){
		if(str[e] == '.') return true;
	}
	return false;
}

void solve(){
	string first, second, third;
	string dia, mes;
	string date; cin >> date;
	if(containPoint(date)){
		processWithPoint(date, first, second, third);
		dia = first;
		mes = second;
	}
	else{
		processWithSlash(date, first, second, third);
		mes = first;
		dia = second;
	}
	// cout << "firs: " << first << " second: " << second << " third: " << third << endl;
	if(third.size() < 4){
		string s((4-(int)third.size()),'0');
		third = s + third;
	}
	if(dia.size() < 2){
		string s((2-(int)dia.size()),'0');
		dia = s + dia;
		
	}
	if(mes.size() < 2){
		string s((2-(int)mes.size()),'0');
		mes = s + mes;
	}
	cout << dia << "." << mes << "." << third << " " << mes << "/"<< dia << "/" << third << endl;
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