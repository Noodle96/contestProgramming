#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int main(){
	int t;
	vector<int> vec;
	vector<vector<int>> all;


	//NAILVE SOLUTION IN CODE
	// while(true){
	// 	cin>>t;
	// 	if(!t) break;
	// 	else{
	// 		vec.resize(t);
	// 		for(int e = 0  ;e < t ; e++) cin>>vec[e];
	// 		sort(vec.begin(), vec.end());
	// 		all.push_back(vec);
	// 		vec.clear();
	// 	}
	// }
	// for(int e = 0 ;e < all.size() ; e++){
	// 	int j = 0;
	// 	for( ; j < all[e].size()-1 ; j++){
	// 		cout << all[e][j] << " ";
	// 	}cout <<all[e][j] << endl;
	// }

	// BEST SOLUTION IN CODE
	while(cin>>t && t != 0){
		vec.resize(t);
		for(int e = 0; e < t; e++)cin >> vec[e];
		sort(all(vec));
		int  e = 0;
		for(;e < t-1 ; e++) cout << vec[e] << " ";
		cout << vec[e] << endl;
	}




	// std::string line;
    // std::vector<std::string> v;
    // while (std::getline(std::cin, line)) {
    //     if (line == "#") {
    //         break;
    //     }
    //     v.push_back(line);
    // }
	return 0;
}