#include <bits/stdc++.h>
using namespace std;
int f(int a, int b){
	if(a>=13) return b;
	if(a >=6) return b/2;
	return 0;
}
int main(){
	int A,B; cin>>A>>B;
	cout << f(A,B) << endl;
	return 0;
}