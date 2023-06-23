#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string str; cin>>str;
	string temp;
	temp = toupper(str[0]);
	cout << temp<< str.substr(1,str.size()-1) << endl;
}
int main(){
	solve();
	return 0;
}