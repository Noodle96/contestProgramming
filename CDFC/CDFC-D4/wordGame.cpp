#include <bits/stdc++.h>
using namespace std;
using HASH_SI = unordered_map<string, int>;

void solve(){
	vector< vector<string> > A;
	HASH_SI hash;
	int n; cin>>n;
	vector<string> temp;
	string str_temp;
	for(int e = 0 ; e < 3; e++){
		for(int j = 0 ;j < n ; j++){
			cin>> str_temp;
			hash[str_temp]++;
			temp.push_back(str_temp);
		}
		A.push_back(temp);
		temp.clear();
	}

	//A filled
	//now we traverse the matrix A
	int cont = 0;
	for(int e = 0; e < 3; e++){
		for(int j = 0 ;j < n ; j++){

			if( hash[ A[e][j] ] == 1) cont+=3;
			if( hash[ A[e][j] ] == 2) cont+=1;			
		}
		cout << cont << " ";
		cont = 0;
	}

}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}