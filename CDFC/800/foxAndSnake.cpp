#include <bits/stdc++.h>
using namespace std;
void f(int n, int m){
	bool flag = true;
	for(int e = 0 ; e < n; e++){
		if(!(e%2)){
			for(int j = 0 ; j < m; j++) cout << "#";
			cout << endl;
		}else{
			if(flag){
				for(int j = 0 ;j < m -1; j++)cout << ".";
				cout << "#" <<endl;
				flag = false;
			}else{
				cout << "#";
				for(int j = 0 ;j < m-1  ; j++){
					cout << ".";
				}cout <<endl;
				flag = true;
			}
		}
	}
}
int main(){
	int n,m; cin>>n>>m;
	f(n,m);
	return 0;
}