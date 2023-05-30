#include <bits/stdc++.h>
using namespace std;
using V = vector<int>;

void printVector(V &vector){
    for(auto e = vector.begin(); e!= vector.end() ; e++){
        cout << *e << " ";
    }
    cout << endl;
}

int findMixing(V &vector){
    for(int e = 0 ;e < vector.size() ; e++){
        if(vector[e] == 0){
            return e+1;
        }
    }
    return -100;
}



int main(){
    // solution1
    // int n;
    // int temp;
    // cin>>n;
    // V vec(n,0);
    // for(int e =0 ; e!= vec.size()-1; e++){
    //     cin>>temp;
    //     vec[temp-1] = temp;
    // }
    // // printVector(vec);
    // cout << findMixing(vec) << endl;


    // solution2
    long long n;
    long long temp = 0;
    cin>>n;
    long long suma = 0;
    for (auto i = 0; i < n-1; i++){
        cin >> temp;
        suma += temp;
    }
    long long sumaTotal = (n*(n+1)/2);
    cout << sumaTotal-suma << endl;
    return 0;
}
