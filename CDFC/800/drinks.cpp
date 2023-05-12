#include <bits/stdc++.h>

using namespace std;
int main(){
        double n; cin>>n;
	double mean = 0.0;
	double temp;
        for(int e = 0 ; e < n; e++){
        	cin>>temp;
        	mean += temp;
        } 
        cout << mean / n << endl;
        
	return 0;
}
