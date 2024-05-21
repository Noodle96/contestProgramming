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

int UMBRAL_ANALISIS=4;

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
int contLakes;
const int N = 100;
char grid[N][N];
bool isVisited[N][N];
int r,c;
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int maxUnits = -100;
int contUnits;
unordered_map<int,int> index_total;
vector<char> secuence;


bool isValidPosition(int x, int y){
    return x >= 0 && x < r && y>=0 && y < c;
}

void flodFill(int x, int y){
    if(isVisited[x][y]) return;
    contUnits++;
    secuence.push_back(grid[x][y]);
    // temp
    // cout << "for " << x << " " << y << endl;
    // for(auto t: secuence){
    //     cout << t;
    // }cout << endl;

    if((int)secuence.size() == UMBRAL_ANALISIS){
        cout << "Alert in " <<  contLakes +1 << endl;
    }

    isVisited[x][y] = true;
    for(int e = 0 ;  e < 8 ;e++){
        int new_x = x + dx[e];
        int new_y = y + dy[e];
        if(isValidPosition(new_x,new_y) && grid[new_x][new_y] != 'T'){
            flodFill(new_x,new_y);
        }
    }
    secuence.pop_back();
}

void solve(){
    cin>>r>>c;
    for(int e = 0;e<r;e++){
        for(int j = 0;j<c;j++){
            cin>>grid[e][j];
        }
    }
    // for(int e = 0;e<r;e++){
    //     for(int j = 0;j<c;j++){
    //         cout << grid[e][j];
    //     }cout << endl;
    // }cout << endl;

    contLakes = 0;

    for(int e = 0;e<r;e++){
        for(int j = 0;j<c;j++){
            if(grid[e][j] != 'T' && !isVisited[e][j]){
                contUnits = 0;
                flodFill(e,j);
                contLakes++;
                index_total[contLakes]= contUnits;
                maxUnits = max(maxUnits,contUnits);
            }
        }
    }
    cout << "cant lakes: " << contLakes << endl;
    cout << "max Units: " << maxUnits << endl;
    cout << "idx-total" << endl;
    for(auto &[f,s]: index_total){
        cout << f << " " << s << endl;
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
