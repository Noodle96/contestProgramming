#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int> vec;
    int temp;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }

    int count = 0;
    int size = vec.size();
    for(int e = 0 ; e < size  ; e++){
        if((vec[e] >= vec[k-1]) and vec[e] != 0) count ++;
        else{
            break;
        }
    }
    cout << count << endl;
   return 0;
}