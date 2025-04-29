/*
==========================================================
|  Archivo       : Office.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-29 11:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BruteForce
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const int INF = 1e9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int r,c;
int s,t;
string line;
const int N = 25;
int edgeTree[N][N];
void solve(){
    cin>>r>>c;
    int totalAgeTree = 0;
    vector< vector<vector<char>>> floorPlan4Rotation;
    for(int e = 0; e < r; e++){
        for(int j = 0 ; j < c; j++){
            cin>>edgeTree[e][j];
            totalAgeTree += edgeTree[e][j];
        }
    }
    cin>>s>>t;
    vector<vector<char>> floorPlanBase(s, vector<char>(t));
    for(int e = 0; e < s; e++){
        cin>>line;
        for(int j = 0 ; j < line.size(); j++){
            floorPlanBase[e][j] = line[j];
        }
    }
    floorPlan4Rotation.push_back(floorPlanBase);

    // hacemos la 1ra rotacion
    // basicamente es una rotacion de 90 grados del floodPlan Base
    vector<vector<char>> floorPlan01(t, vector<char>(s));
    for(int e = 0; e < t; e++){
        for(int j = 0 ; j < s; j++){
            floorPlan01[e][j] = floorPlanBase[s-j-1][e];
        }
    }
    floorPlan4Rotation.pb(floorPlan01);

    // hacemos la 2da rotacion
    // Basicamente es una rotacion de 180 grados de floorPlanBase
    vector<vector<char>> flootPlan02(s, vector<char>(t));
    for(int e = 0 ; e < s; e++){
        for(int j = 0 ; j < t; j++){
            flootPlan02[e][j] = floorPlanBase[s-e-1][t-j-1];
        }
    }
    floorPlan4Rotation.push_back(flootPlan02);

    // hacemos la 3ra rotacion
    // Basicamente es una rotacion de 270 grados de floorPlanBase
    vector<vector<char>> floorPlan03(t, vector<char>(s));
    for(int e = 0 ; e < t; e++){
        for(int j = 0 ; j < s; j++){
            floorPlan03[e][j] = floorPlan01[t-e-1][s-j-1];
        }
    }
    floorPlan4Rotation.push_back(floorPlan03);

    // imprimimos todoas las rotaciones;
    // for(int i = 0 ; i  < floorPlan4Rotation.size() ;i++){
    //     int rows = floorPlan4Rotation[i].size();
    //     int cols = floorPlan4Rotation[i][0].size();
    //     // cout << "rows: " << rows << " cols: " << cols  << endl;
    //     cout << "floodPlan " << i << endl;
    //     for(int e = 0;  e < rows; e++){
    //         for(int j = 0; j < cols ; j++){
    //             cout << floorPlan4Rotation[i][e][j];
    //         }cout << endl;
    //     }cout << endl;
    // }
    // cout << "Total Age: " << totalAgeTree << endl;
    int minimoCut = INF;
    for(int e = 0; e < r; e++){
        for(int j = 0; j < c; j++){
            int currentLenRows = r -e;
            int currentLenCols = c - j;
            for(int k = 0 ; k < 4; k++){
                int currLenFloorPlanRows = floorPlan4Rotation[k].size();
                int currLenFloorPlanCols = floorPlan4Rotation[k][0].size();
                if(currentLenRows >= currLenFloorPlanRows && currentLenCols >= currLenFloorPlanCols){
                    // cout << "coincidio en e: " << e << " j: "<< j << " para k: " << k << endl;
                    int totalCut_i = 0;
                    for(int l = e, c_i = 0; l < e + currLenFloorPlanRows; l++,c_i++){
                        for(int  r = j, r_i = 0; r < j + currLenFloorPlanCols; r++, r_i++){
                            if(floorPlan4Rotation[k][c_i][r_i] == '#'){
                                totalCut_i += edgeTree[l][r];
                            }
                        }
                    }
                    minimoCut = min(minimoCut, totalCut_i);
                    // cout << "totalCut_i: " << totalCut_i << endl;
                }
            }
        }
    }
    cout << totalAgeTree - minimoCut << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}