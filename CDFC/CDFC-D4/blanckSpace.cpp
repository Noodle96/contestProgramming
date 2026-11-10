#include <bits/stdc++.h>
using namespace std;
int blankSpace(vector<int> &vector, int n){
    int maxZeros = 0;
    int cont = 0;
    for(int e = 0 ; e < n; e++){
        if(vector[e] == 0){
            cont++;
            maxZeros = max(maxZeros,cont);
        }
        else cont = 0;
    }
    return maxZeros;
}
int main(){
    int t; cin>>t;
    int n;
    vector<int> vector;
    while(t--){
        cin>>n;
        vector.resize(n);
        for(auto e = 0 ; e < n;e++ ) cin>> vector[e];
        cout << blankSpace(vector,n) << endl;

        vector.clear();
    }
    return 0;
}