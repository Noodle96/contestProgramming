#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	vector<double> vec(100);
	vec[0] = 100.00000000000;
	vec[1] = 0.00000000000;
	cout << setprecision(100000);

	for(auto e = 2 ;e < 100 ;e++){
		vec[e] = (vec[e-2] + vec[e-1]) / 2.0;
	}
	if(n >= 99){
		cout << vec[99]<< " " << 100.0 - vec[99] <<  endl;
	}else{
		cout << vec[n-1]<< " " << 100.0 - vec[n-1] <<  endl;
	}

	// for(int e = 0 ;e < n ;e++){
	// 	cout <<  "e: " << e << " "<< vec[e-1]<< " " << 100.0 - vec[e-1] <<  endl;
	// }


	return 0;
}