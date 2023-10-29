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
char findValue(char current, int key){
	int position = current - '`';
	int resta = position - key;
	if(resta > 0){
		return resta + '`';
	}else{
		return 'z' - abs(resta);
	}
}

char findValue2(char current, int key){
	int position = current - '`';
	int suma = position + key;
	if(suma > 26){
		int diferenia = suma -26;
		return '`'+ diferenia;
	}else{
		return suma + '`';
	}
}

string solve(){
	int n; cin>>n;
	cin.ignore();
	string line;
	getline(cin,line);
	string word;
	map<string,int> mapa;
	for(int e = 0 ; e < (int)line.size(); e++){
		if(line[e] == ' '){
			mapa[word]++;
			word = "";
		}else{
			word += line[e];
		}
	}
	mapa[word]++;
	// for(auto it = mapa.begin(); it != mapa.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	string ans;
	string descipherText;
	string the = "the";
	if(mapa.count(the) > 0){ // plainText
		for(int e = 0 ;e < (int)line.size() ; e++){
			if(line[e] == ' '){
				descipherText += " ";
			}else{
				char temp = findValue(line[e], n);
				// cout << "char: " << temp << endl;
				descipherText += temp;
			}
		}
		//cout << descipherText << endl;
		ans = descipherText;
	}else{
		string cipherText ;
		for(int e = 0 ; e < (int)line.size(); e++){
			if(line[e] == ' '){
				cipherText += " ";
			}else{
				char temp = findValue2(line[e], n);
				cipherText += temp;
			}
		}
		// cout << cipherText << endl;
		ans = cipherText;
	}
	return ans;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	string ans;
	while(t){
		ans = solve();
		if(t!= 1){
			cout << ans << endl;
		}else{
			cout << ans;
		}
		t--;
	}
	return 0;
}
//
// abcdefghijklmnopqrstuvwxyz