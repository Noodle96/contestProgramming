#include <bits/stdc++.h>
using namespace std;
bool f(int  n, int m,int k){
	return k == (n-1 + n*(m-1));
}
int main(){

	int t; cin>>t;
	int n,m,k;
	while(t--){
		cin>>n>>m>>k;
		cout << ( f(n,m,k) ? "YES" : "NO") << endl;
	}
        
	return 0;
}
