#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl
using namespace std;
void solve(){
	string line;
	// getline(std::cin, line);
    // getline(std::cin, line) ;
	map<string, int> mapa;
	int total = 0;
	std::getline(std::cin,line);
	while(line != ""){
		// std::cout << "line is: " << line << endl;
		mapa[line]++; total ++;
		std::getline(std::cin,line);
	}
	// HERE;
	// for(auto it = mapa.begin(); it != mapa.end() ; it++){
	// 	std::cout << it->first << " : " << it->second << endl;
	// }
	// std::cout << "total: " << total << std::endl;
	for(auto it = mapa.begin() ; it != mapa.end(); it++){
		double d = (it->second)/double(total) *100;
		std::cout << std::fixed;
		std::cout << std::setprecision(4);
		// std::cout << d;
		// float val = float(it->second)/total *100;
		// stringstream tmp;
		// tmp << setprecision(4) << fixed << val;
		// double new_val = stod(tmp.str());   // new_val = 3.143
		// tmp.str(string());  
		std::cout << it->first  << " "<< d << endl;
	}
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int t; std::cin>>t;std::cin.ignore();
	string line;
	std::getline(cin,line);
	int caso = t;
	while(t--){
		solve();
		if(caso > 1) std::cout << endl;
		caso--;
	}
	return 0;
}