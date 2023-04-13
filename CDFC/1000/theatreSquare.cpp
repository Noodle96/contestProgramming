#include <bits/stdc++.h>
using namespace std;
typedef long long LL ;
int main(){
    LL n,m,a; cin>>n>>m>>a;
    LL x,y;
    if(n%a==0) x = n/a;
    else x = (n/a) +1;
    if(m%a == 0) y = m/a;
    else y = (m/a) +1;
    cout << x*y << endl;
    return 0;
}