#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &vec){
    for(auto e = vec.begin() ; e != vec.end() ; e++){
        cout << *e << " ";
    }
    cout << endl;
}
int main(){
    int n,m; cin>>n>>m;
    int m_=m;
    int temp;
    vector<int> vec;
    while(m--){
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    // printVector(vec);
    int least = vec[n-1] - vec[0];
    for(auto e = 1 ; e <= (m_-n) ; e++){
        if(vec[n-1+e] - vec[e] < least){
            least = vec[n-1+e] - vec[e];
        }
    }
    cout << least << endl;
    return 0;
}