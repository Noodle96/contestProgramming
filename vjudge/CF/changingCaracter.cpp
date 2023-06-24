#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	int n,k; cin>>n>>k;
	string str; cin>> str;
	str[k-1] = tolower(str[k-1]);
	cout << str<< endl;
}

int main(){
	solve();
	return 0;
}