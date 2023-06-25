#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
void ReadIntLine(unordered_map<int,int> &u_map){
    // string line;
    // getline(cin, line);
    // istringstream is(line);
	// vector<int>vec;
    // vec = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
	// // std::cout << "orint: " << endl;
	// // for(auto it = vec.begin(); it != vec.end() ; it++){
	// // 	cout << *it << endl;
	// // }
	// int num;
	// while(cin>>num){
	// 	std::cout << "any" <<endl;
	// }


	// for(auto it = vec.begin() ;it != vec.end() ; it++) u_map[*it]++;
	// stack<pair<int,int>> stack;

	// for(auto it = u_map.begin(); it != u_map.end() ; it++){
	// 	// cout << it->first << " " << it->second << endl;
	// 	stack.push(std::make_pair(it->first, it->second));
	// 	// queue.push(it->first);
	// }
	// while (!stack.empty()){
    // 	auto it = stack.top();
	// 	std::cout << it.first << " " << it.second << endl;
    // 	stack.pop();
  	// }
}
// void solve(){
// 	int num;
// 	unordered_map<int,int> hash;
// 	stack<int>  mystack;
// 	while(cin>>num) hash[num]++;
// 	// for(auto it = hash.begin(); it != hash.end() ; it++){
// 	// 	cout << it->first << " : " << it->second << endl;
// 	// }
// 	// std::cout << "print hash" << endl;
// 	// for(auto it = hash.begin(); it != hash.end() ; it++){
// 	// 	cout << it->first << " : " << it->second << endl;
// 	// } 
// 	stack<pair<int,int>> stack;
// 	for(auto it = hash.begin(); it != hash.end() ; it++) stack.push(std::make_pair(it->first, it->second));
// 	while (!stack.empty()){
// 			auto it = stack.top();
// 			std::cout << it.first << " " << it.second << endl;
// 			stack.pop();
// 	}
// }
// int main(){
// 	solve();
// 	return 0;
// }

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	int num;
	unordered_map<int, int> mapa;
	vector<int> vec;
	while(std::cin>>num){
		mapa[num]++;
		if(mapa[num]==1) vec.push_back(num);
	}
	for(auto &num: vec){
		cout << num << " " << mapa[num] << endl;
	}
}
int main(){
	solve();
	return 0;
}

// 0 -2 45 673 45 -22 -2 22 -673
// 9 -8 -88 88  9 0