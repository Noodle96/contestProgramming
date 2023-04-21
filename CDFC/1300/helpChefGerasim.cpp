#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> vec(n); 
    int sum = 0;
    for(int e = 0 ; e < n; e++){
        cin>> vec[e];
        sum += vec[e];
    }
    int left = 0,right = 0 ;
    int average = sum / n;
    if(sum%n != 0){
        cout << "Unrecoverable configuration." << endl;
        return 0;
    }
    int cont = 0;
    for(int  e= 0 ; e < n ; e++){
        if(vec[e] == average) cont++;
        else if(vec[e] < average)left = e;
        else if (vec[e] > average) right = e;

    }
    if(cont == n){
        cout<<"Exemplary pages."<<endl;
        return 0;
    }
    if(cont != n-2){
        cout << "Unrecoverable configuration." << endl;
        return 0;
    }
    cout << abs(vec[left] - vec[right])/2 <<" ml. from cup #"<< (vec[right] < vec[left] ? right+1 : left+1) << " to cup #" << (vec[right] < vec[left] ? left+1 : right+1 ) << "." << endl;
    // cout << left+1 << " : " << right+1 << endl;
    return 0;
}