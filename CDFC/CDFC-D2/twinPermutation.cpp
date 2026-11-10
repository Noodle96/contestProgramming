#include <bits/stdc++.h>
using namespace std;

bool condition(vector<int> &vec, vector<int> &vecCopy, int n){
	for(int e = 0 ;e < n - 1 ; e++){
		if(  vec[e] + vecCopy[e] > vec[e+1] + vecCopy[e+1] ) return false;
	}
	return true;
}
void f(vector<int> &vec, int n){
	vector<int> vecCopy = vec;
	sort(vecCopy.begin(), vecCopy.end());
	do {
		// std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
		// cout << "\nprint" << endl;
		// for(auto it = vecCopy.begin(); it != vecCopy.end() ; it++){
		// 	cout << *it  << " ";
		// }cout << endl;
		// for(auto it = vec.begin(); it != vec.end() ; it++){
		// 	cout << *it  << " ";
		// }cout << endl;
		if( condition(vec,vecCopy,n) ) break; 
	} while ( std::next_permutation(vecCopy.begin(),vecCopy.end()) );

	for(auto it = vecCopy.begin(); it != vecCopy.end() ; it++){
		cout << *it << " ";
	}cout << endl;

}
void f2(vector<int> &vec, int n){
	int sumaMaxima = 1 + n;
	vector<int> temp;
	for(int e = 0 ; e < n; e++){
		temp.push_back(sumaMaxima - vec[e]);
	}
	for(auto it = temp.begin(); it != temp.end() ; it++){
		cout << *it << " ";
	}cout << endl;
}
int main(){
	int t;cin>>t;
	int n;
	vector<int> vec;
	while(t--){
		cin>>n;
		vec.resize(n);
		for( int e = 0 ; e < n; e++) cin>>vec[e];
		f2(vec,n);
		vec.clear();
	}
	return 0;
}