#include <bits/stdc++.h>
using namespace std;
void solve(int caso){
	int cont = 0;
	int a,b; cin>>a>>b;
	if(a%2==0) a++;
	for(int e = a ; e <= b; e+=2){
		cont += e;
	}
	cout <<"Case " << caso << ": " <<cont << endl;
}
int main(){
	int t; cin>>t;
	int caso =1;
	while(t--){
		solve(caso);
		caso++;
	}
	return 0;
}	