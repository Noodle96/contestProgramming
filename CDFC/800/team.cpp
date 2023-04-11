#include <bits/stdc++.h>
using namespace std;
int main(){
    int count = 0;
    bool a,b,c;
    int n; cin>>n;
    bitset<3> BS;
    while(n--){
        cin>>a>>b>>c;
        BS.set(0,a); BS.set(1,b);BS.set(2,c);
        if(BS.count() >=2)count ++;
        BS.reset();
    }
    cout << count << endl;
    return 0;
}