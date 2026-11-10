#include <bits/stdc++.h>
using namespace std;

int minValue(vector<int> &vec, vector<bool> &tablaVerificacion){
    int minimo = INT_MAX;
    for(int e = 0 ; e < vec.size(); e++){
        if(vec[e] > 0 && tablaVerificacion[e] == 0){
            if(vec[e] < minimo){
                minimo = vec[e];
                tablaVerificacion[e]  = 1;
            }
        }
    }
    return minimo;
}
void printVector(vector< vector<int> > &vector){
    for(auto e = vector.begin() ; e != vector.end(); e++){
        for(auto j = e->begin() ; j != e->end(); j++){
            cout << *j << " " ;
        }
        cout << endl;
    }
}
int main(){
        int n; cin>>n;
        vector< vector<int> > costos;
        int costo_temporal;
        
        for(int e = 0 ; e < n ; e++){
            vector<int> temp;
            for(int j  = 0 ; j< n; j++){
                cin>>costo_temporal;
                temp.push_back(costo_temporal);
            }
            costos.push_back(temp);
        }
        
        // printVector(costos);
        vector<bool> BS(12,0);
        vector<int> row;
        int contador = 0;
        for(auto e = costos.begin(); e != costos.end() ; e++){
            row = *e;
            contador += minValue(row, BS);
        }
    return 0;
}


