#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
	while (b > 0) {
		cout << "b > 0" << endl;
		int carry = a & b;
		cout << "carry: " << carry << endl;
		a ^= b;
		cout << "a ^= b : " << a << endl;
		b = carry << 1;
		cout << "b: " << b << endl;
	}
	return a;
}

void f(int x){
	for(int e = 31 ;e >= 0 ; e--){
		if((x & (1<<e)) != 0) cout << 1 ;
		else cout << 0;
	}cout << endl;
}
int main(){
	// cout << add(2,7) << endl;
	f(10);

	return 0;
}