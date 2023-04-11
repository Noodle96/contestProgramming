#include <bits/stdc++.h>
using namespace std;

int reverse(int a){
    int rev=0;
	while(a!=0){
        rev=rev*10;
	    rev=rev+a%10;
	    a=a/10;
	}
	return rev;
}
int f(int &a, int &b){
    a = reverse(a);
    b = reverse(b);
    return reverse(a+b);
}

int main(){
    int N; cin>>N;
    int a,b;
    while(N--){
        cin>>a>>b;
        cout << f(a,b) << endl;
    }
    return 0;
}