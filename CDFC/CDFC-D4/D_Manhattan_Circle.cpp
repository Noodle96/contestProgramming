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
vector<string> grid;
string line;
int n,m;

int contNumeral(string &str){
    int cont = 0;
    for(auto &c : str){
        if(c == '#') cont++;
    }
    return cont;
}

void solve(){
    cin>>n>>m;
    grid.clear();
    int row = 0;
    int maximoNumeral = -10;
    if(n == 1 && m == 1){
        cin>>line;
        // cout << "OJO: " << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    for(int e = 0 ; e < n; e++){
        cin>>line;
        auto numNumerales = contNumeral(line);
        if(numNumerales > maximoNumeral){
            maximoNumeral = numNumerales;
            row = e;
        }
        grid.pb({line});
    }
    // cout << row+1 << " " << maximoNumeral << endl;
    cout << row+1 << " ";
    string rowStr = grid[row];
    // cout << rowStr << endl;
    auto findUniqueNumeral = find(rowStr.begin(), rowStr.end(), '#');
    if(maximoNumeral == 1){
        cout << findUniqueNumeral - rowStr.begin() + 1 << endl;
    }
    else{
        auto pos = findUniqueNumeral - rowStr.begin();
        cout << pos + 1 + (maximoNumeral/2)<< endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}