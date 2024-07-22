#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
ll a,b;
int cont = 1;
vector<pair<ll,ll>> pares;
string line;
ll maximo;
const ll inf = 1e9;
const ll m_inf = -1e9;
int casoX = 1;
void solve(){
    while(getline(cin,line)){
        if(line == "0 0") break;
        maximo = m_inf;
        stringstream ss(line);
        while(ss >> a >> b){
            maximo = max(maximo, max(a,b));
            if(a != 0 || b != 0){
                pares.pb(mp(a,b));
            }
        }
        vector<vector<ll>> matrix(maximo,vector<ll>(maximo,INT_MAX));
        // cout << "print pares"<< endl;
        // for(auto e: pares){
        //     cout << e.first << "-" << e.second << " ";
        // }cout << endl;
        // cout << "maximo " << maximo << endl;
        for(auto e:  pares){
            matrix[e.first-1][e.second-1] = 1;
        }
        pares.clear();
        // cout << "print matrix" << endl;
        // for(int e = 0 ; e < maximo; e++){
        //     for(int j = 0 ; j < maximo; j++){
        //         cout << matrix[e][j] << " ";
        //     }cout <<endl;
        // }cout << endl;

        // floyd warshall
        for(int k = 0 ; k < maximo; k++){
            for(int i = 0 ; i < maximo; i++){
                for(int j = 0 ; j < maximo; j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        // cout << "print matrix" << endl;
        // for(int e = 0 ; e < maximo; e++){
        //     for(int j = 0 ; j < maximo; j++){
        //         cout << matrix[e][j] << " ";
        //     }cout <<endl;
        // }cout << endl;

        int total = 0;
        int contadorValidos = 0;
        for(int i = 0 ; i < maximo; i++){
            for(int j = 0 ; j < maximo; j++){
                if(i != j && matrix[i][j] != INT_MAX){
                    total  += matrix[i][j];
                    contadorValidos++;
                }
            }
        }
        double ans = ((double)total/(double)contadorValidos);
        cout << fixed << setprecision(3) <<  "Case " << casoX++ << ": average length between pages = " << ans << " clicks" << endl;
    }
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