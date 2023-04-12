#include <bits/stdc++.h>
using namespace std;

int f(map<int,int> &g){
    int numTaxis = g[4];
    int e = 3;
    while(e > 1){
        if(g[e]){
            g[e]--;
            if(g[4-e]){
                g[4-e]--;
            }else if(g[4-e-1]){
                if(g[4-e-1] >= 2){
                    g[4-e-1] -=2;
                }else{
                    g[4-e-1]--;
                }
            }
            numTaxis++;
        }else{
            e--;
        }
    }
    if(g[1] %4 == 0){
        numTaxis += (g[1]/4);
    }else{
        numTaxis += (g[1]/4);
        numTaxis ++;
    }
    return numTaxis;
}


int main(){
    int n; cin>>n;
    map<int,int> grupos;
    int temp;
    while(n--){
        cin>>temp;
        grupos[temp]++;
    }
    // for(auto it = grupos.begin(); it != grupos.end() ; it++){
    //     cout << it->first << " : " << it->second << endl;
    // }
    // for(auto e = 0 ; e < 7 ; e++){
    //     cout << grupos[e] << endl;
    // }
    cout << f(grupos) << endl;
    return 0;
}