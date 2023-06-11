#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string , string> data;
	data["HELLO"] = "ENGLISH";
	data["HOLA"] = "SPANISH";
	data["HALLO"] = "GERMAN";
	data["BONJOUR"] = "FRENCH";
	data["CIAO"] = "ITALIAN";
	data["ZDRAVSTVUJTE"] = "RUSSIAN";

	std::string line;
    std::vector<std::string> v;


	//NAIVE SOLLUTION
    // while (std::getline(std::cin, line)) {
    //     if (line == "#") {
    //         break;
    //     }
    //     v.push_back(line);
    // }
	// int cont = 1;
	// for(int e = 0 ; e < v.size(); e++){
	// 	if(data.count(v[e]) != 0){
	// 		cout << "Case " << cont << ": " << data[v[e]] << endl;
	// 	}else{
	// 		cout << "Case " << cont << ": " << "UNKNOWN" << endl;
	// 	}
	// 	cont++;
	// }

	// BEST SOLUTION
	int caso = 1;
	while(cin>> line && line != "#"){
		if(data.count(line) != 0){
			cout << "Case " << caso << ": " << data[line] << endl;
		}else cout << "Case " << caso << ": " << "UNKNOWN" << endl;
		caso++;
	}
	return 0;
}
