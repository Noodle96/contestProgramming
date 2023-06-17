#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

void ReadIntLine(vector<int>& numbers){
    string line;
    getline(cin, line);
    istringstream is(line);
    numbers = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}
int main(){
	vector<int> vec;
	ReadIntLine(vec);
	for(auto it = vec.begin(); it != vec.end() ; it++){
		cout << *it +100 << endl;
	}
	return 0;
}