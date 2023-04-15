#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
ll f(ll a, ll b){
  if(a < b) return f(b,a);
  if(b==0) return -1;
  return (a / b) + f(b,a%b);
}
int main(){
    long long A,B; cin>>A>>B;
    long long cont = 0;
    cout << f(A,B) << endl;
    return 0;
}