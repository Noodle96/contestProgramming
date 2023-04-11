#include <bits/stdc++.h>
using namespace std;
int main(){
    // int numbits; cin>>numbits;
    bitset<4> foo; // 0000
    // cin>>foo;
    // cout << foo.all() << endl;
    // cout << foo.any() << endl;
    // cout << foo << endl;
    foo.set(0,1); // 0001
    foo.set(3,1); // 1001
    cout << foo << endl;
    return 0;
}