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
string str1,str2;

string toLower(string str){
	for(int e = 0;e < str.size();e++){
		if(str[e] >= 'A' && str[e] <= 'Z'){
			str[e] = str[e] - 'A' + 'a';
		}
	}
	return str;
}
int sumDigits(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}
int myAccumulate(string str){
	int ans = 0;
	for(int e = 0 ; e < str.size(); e++){
		if(str[e] >= 'a' && str[e] <= 'z'){
			ans+= (str[e]-'a'+1);
		}
	}
	return ans;
}

void solve(){
	// string abc = "abcdefghijklmnopqrstuvwxyz";
	// for(int e = 0 ;e< 26 ; e++){
	// 	cout << abc[e] << " " << abc[e]-'a'+1 << endl; 
	// }
	// cout <<endl;
	cout << setprecision(2) << fixed;
	while(getline(cin,str1) && getline(cin,str2)){
		str1 = toLower(str1);
		str2 = toLower(str2);

		int value1 = sumDigits(myAccumulate(str1));
		while(1){
			if(value1 < 10) break;
			value1 = sumDigits(value1);
		}
		int value2 = sumDigits(myAccumulate(str2));
		while(1){
			if(value2<10) break;
			value2 = sumDigits(value2);
		}
		float val1 = static_cast<float>(value1);
		float val2 = static_cast<float>(value2);
		if(val1 > val2) swap(val1,val2);
		cout << (val1/val2)*100 << " %" << endl;		
	}
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