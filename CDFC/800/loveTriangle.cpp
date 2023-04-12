#include <bits/stdc++.h>
using namespace std;
void buildMatrixAdjacency(int **adj, int *planes, int n){
    for(int e = 0 ; e < n; e++){
        adj[planes[e]-1][planes[planes[e]-1]-1] = 1;
    }
}

bool isTriangle(int **adj, int initial, int j, int N){
    for(auto e = 0 ; e < N ; e++){
        if(adj[j][e]){
            for(auto x = 0 ; x < N; x++){
                if(adj[e][x]){
                    if(initial==x){
                        return true;
                    }
                    return false;
                }
            }
            return false;
        }
    }
    return false;
}
void imprimirMatrix(int **matriz, int N){
    for(auto e = 0 ;  e < N; e++){
        for(auto j = 0 ; j < N; j++){
            cout << matriz[e][j] << " ";
        }cout <<endl;
    }
    cout << endl;
}
int main(){
    int N;cin>>N;

    int** adj = new int*[N];
    for (int i = 0; i < N; ++i)
        adj[i] = new int[N];

    for(int e = 0 ; e  < N; e++){
        for(int j = 0 ;j < N ; j++){
            adj[e][j] = 0;
        }
    }

    // imprimirMatrix(adj,N);
    int planes[N];
    int temp;
    for(auto e = 0 ; e < N ; e++){
        cin>>temp;
        planes[e] = temp;
    }
    // build adjacency Matrix
    buildMatrixAdjacency(adj, planes, N);
    // imprimirMatrix(adj,N);
    for(auto e = 0 ; e < N; e++){
        for (auto j = 0 ; j < N; j++){
            if(adj[e][j]){
                if(isTriangle(adj,e,j, N)){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}