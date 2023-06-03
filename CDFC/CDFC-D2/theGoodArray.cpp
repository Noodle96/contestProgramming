#include <bits/stdc++.h>
using namespace std;

int disionTecho(int i, int k){
	if(i%k==0) return i/k;
	return i/k +1;
}
void verifyString(string &str, int factor, int hasta){
	int cont = 0;
	for(int e = 0 ;e <= hasta ; e++){
		if(str[e] == '1') cont++;
	}

	if(cont < factor) str[hasta] = '1';
	cont = 0;

	int size = str.size();
	for(int  e = 0; e <= hasta; e++){
		if(str[size-e-1] == '1') cont++;
	}

	if(cont < factor) str[size-hasta-1] = '1';
}

void buildVector(vector<int> &vec, int k){
	for(int e = 0 ; e < vec.size(); e++){
		vec[e] = disionTecho(e+1,k);
	}
}

void f(vector<int> &divisiones, int n){
	string str(n,'0');
	int flag;
	for(int e = 0 ;e < n ; e++){
		verifyString(str,divisiones[e], e);
	}
	int countOnes = 0;
	for(int e = 0 ; e < n; e++){
		if(str[e] == '1') countOnes++;
	}
	cout << countOnes << endl;

}
void solve(){
	int n,k;
	cin>>n>>k;

	vector<int> divisiones(n);
	buildVector(divisiones, k);
	f(divisiones,n);
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}