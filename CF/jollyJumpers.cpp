#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void f(vector<int> &vec, int n){
	vector<int> distances;
	if(n==1){
			cout << "Jolly" << endl; return ;
	}
	int distance = abs(vec[0] - vec[1]);
	distances.push_back(abs(distance));
	for(int e = 1 ;e < n-1 ; e++){
		distance = vec[e] -vec[e+1];
		distances.push_back(abs(distance));
	}
	sort(all(distances));
	// HERE
	// for(auto it = distances.begin(); it != distances.end() ; it++){
	// 	cout << *it << endl;
	// }
	// HERE
	for(int e = 0 ; e < n-1; e++){
		if(distances[e] != e+1){
			// cout << "e: " << e << endl;
			cout << "Not jolly" << endl; return ;
		}
	}
	cout << "Jolly" << endl;
}
int main(){
	int n;
	int cont = 1;
	vector<int> vec;
	while(cin>>n && cont<=10){
		vec.assign(n,0);
		for(int &e: vec) cin>>e;
		f(vec,n);
		cont++;
	}
	return 0;
}