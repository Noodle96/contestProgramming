#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,D;
    cin>>N>>D;
    int temp;
    vector<int> vec;
    while(N--){
        cin>>temp;
        vec.push_back(temp);
    }
    auto before  = vec.begin();
    auto current = ++vec.begin();
    for(; current != vec.end(); current++){
        if(*current - *before <= D){
            cout << *current << endl;
            return 0;
        }
        before = current;
    }
    cout << -1 << endl;
    return 0;
}