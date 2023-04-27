#include <bits/stdc++.h>
using namespace std;
using M = vector<vector<char>>;
bool containStrawberryRow(M &m, int row, int numColumns){
    for(int e = 0 ; e < numColumns ; e++){
        if(m[row][e] == 'S') return true;
    }
    return false;
}

bool containStrawberryColumn(M &m, int column, int numRows){
    for(int e = 0 ; e < numRows ; e++){
        if(m[e][column] == 'S') return true;
    }
    return false;
}
int main(){
    int c,r; cin>>r>>c;
    M molde;
    vector<char> vtemp;
    char ctemp;
    for(int e = 0 ; e < r; e++){
        for(int j = 0; j < c; j++){
            cin >> ctemp;
            vtemp.push_back(ctemp);
        }
        molde.push_back(vtemp);
        vtemp.clear();
    }
    // for(int e = 0 ; e < r; e++){
    //     for(int j = 0; j < c; j++){
    //         cout << molde[e][j] << " ";
    //     }cout << endl;
    // }
    int filas = 0;
    int columns  = 0;
    for(int e = 0 ; e < r; e++){
        if( !containStrawberryRow(molde, e, c) )filas++;
    }
    for(int e = 0 ; e < c; e++){
        if( !containStrawberryColumn(molde, e, r) )columns++;
    }
    // cout << "filas: " << filas << " columnas: " << columns << endl;
    cout << (filas*c + columns*r) - (filas*columns) << endl; 
    return 0;
}