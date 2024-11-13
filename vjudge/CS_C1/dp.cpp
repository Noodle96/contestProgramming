#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int &e:vec) cin>>e;
    sort(all(vec));
    int middle;
    auto value1 = vec[n/2 -1];
    auto value2 = vec[n/2];
    cout << value2 - value1 << endl;
    return  0;
}
// 1 4 4 6 7 9