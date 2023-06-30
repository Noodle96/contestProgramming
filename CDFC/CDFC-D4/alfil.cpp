#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
void solve(){
	vector<vector<char>> tablero('.',vector<char>(8) );
	// vector<vector<int>> matrix(RR, vector<int>(CC));
	// for(int e = 0 ;e < 8 ; e++){
	// 	for(int j = 0 ; j < 8; j++){
	// 		tablero[e][j] = 'd';
	// 	}
	// }
	for(auto r = 0; r <8; r++){
		for(auto c = 0 ; c < 8; c++){
			cin>> tablero[r][c];
		}
	}
	for(auto r = 1; r <7; r++){
		for(auto c = 1 ; c < 7; c++){
			if(tablero[r][c] =='#'){
				if(tablero[r-1][c-1] == '#'&& tablero[r-1][c+1] == '#'&& tablero[r+1][c-1] == '#'&& tablero[r+1][c+1] == '#' ){
					cout << r+1 << " " << c+1 << endl;
					return;
				}
			}
		}
	}
	//end
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	string line;
	while(t--){
		cin.ignore();
		getline(cin,line);
		// cout << "line es: " << line << endl;
		solve();
	}
	
	return 0;
}