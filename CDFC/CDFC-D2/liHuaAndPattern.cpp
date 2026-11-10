#include <bits/stdc++.h>
using namespace std;
void printVector(vector< vector<int> > &vector){
    for(auto e = vector.begin() ; e != vector.end(); e++){
        for(auto j = e->begin(); j != e->end() ; j++){
            cout << *j << " ";
        }
        cout << endl;
    }
}

string analize(vector< vector<int> > &vector, int limite){
    auto tam = vector.size();
    auto contador = 0;
    for(int e = 0 ; e < (tam/2) && (contador < limite); e++){
        for(auto j = 0 ; (j < tam) && (contador < limite)  ; j++){
            if(vector[e][j] != vector[tam-1-e][tam-1-j]){
                vector[e][j] =vector[tam-e-1][tam-j-1];
                contador++;
            }
        }
    }
    // cout << "any" << endl;
    for(int e = 0 ; e < (tam/2); e++){
        for(auto j = 0 ; (j < tam) ; j++){
            // cout <<  vector[e][j] << " and " << vector[tam-e-1][tam-j-1] << endl;
            if(vector[e][j] != vector[tam-e-1][tam-j-1]){
                return "NO";
            }
        }
    }
    return "YES";
}

int main(){
    int t; cin>>t;
    int n,k;
    int color;
    while(t--){
        cin>>n>>k;
        vector<vector<int>> vec;
        for(int e = 0 ;e< n ; e++){
            vector<int> temp;
            for(int j = 0 ;j< n ;j++){
                cin>> color;
                temp.push_back(color);
            }
            vec.push_back(temp);
        }
        cout << analize(vec,k) << endl;
    }

    return 0;
}