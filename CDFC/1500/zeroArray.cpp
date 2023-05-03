#include<iostream>
using namespace std;
int main(){
	long long n,a,k=0,s=0;
	cin>>n;
	while(n--){
		cin>>a;
		if (a>k)k=a;
		s+=a;
	}
	if (s%2!=0 || s/2<k)cout<<"NO\n";
	else cout<<"YES\n";
}
