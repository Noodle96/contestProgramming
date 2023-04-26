#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while (t--){
		int n, a, z=0;
		cin>>n;
		for (int i=0; i<n; i++){
            cin>>a;
            if (a==1)z++;
        }
		cout<<n-z+(z+1)/2<<"\n";
	}
}