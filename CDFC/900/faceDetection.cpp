#include <bits/stdc++.h>
using namespace std;
int verify(int e, int j, int n, int m, vector<string> &square){
    string strTemp;
    if(j+1>=m) return 0;
    if(e+1>=n)return 0;
    strTemp += square[e][j];
    strTemp += square[e][j+1];
    strTemp += square[e+1][j];
    strTemp += square[e+1][j+1];
    auto it = strTemp.find('f');
    if(it != std::string::npos){
        it = strTemp.find('a');
        if(it != std::string::npos){
            it = strTemp.find('c');
            if(it != std::string::npos){
                it = strTemp.find('e');
                if(it != std::string::npos){
                    return 1;
                }return 0;
            }else return 0;
        }else return 0;
    }else return 0;
}

int main(){
    // int n,m; cin>>n>>m;
    // vector< string > square;
    // string temp;
    // for(int e = 0;e < n ; e++){
    //     cin>>temp;
    //     square.push_back(temp);
    // }
    // int cont = 0;
    // for(int e = 0 ; e  <n; e++){
    //     for(int j = 0 ; j < m ; j++){
    //         cont += verify(e,j,n,m,square);
    //         // cout << verify(e,j,n,m,square) << endl;
    //     }
    // }
    // cout << cont << endl;
    cout << std::string::npos << endl;
    return 0;
}