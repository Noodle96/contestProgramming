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
int N,M;
int x;
void solve(){
    cin>>N>>M;
    vector<int> totalNutrientes(M),goal(M);
    for(int e = 0 ; e < M; e++) cin >> goal[e];
    for(int e = 0 ; e < N; e++){
        for(int j = 0 ; j < M; j++){
            cin>>x;
            totalNutrientes[j]+=x;
        }
    }
    // for(int e = 0 ; e < M; e++){
    //     cout<< totalNutrientes[e] << " ";
    // }cout << endl;
    for(int e = 0 ; e < M; e++){
        if(totalNutrientes[e] < goal[e]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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