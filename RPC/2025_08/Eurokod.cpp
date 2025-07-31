/*
==========================================================
|  Archivo       : Eurokod.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 14:51
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Data Structures
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

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

struct pair_hash {
    size_t operator()(const pii& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

void solve(){
    int n; cin>>n;
    vector<int> president(n);
    int n_ = n;
    for(int e = 0 ; e < n; e++){
        int pos; cin>>pos;
        president[pos-1] = n_--;
    }
 
    vector<int> associations_calification(n);
    vector<int> associations(n);
    for(int e = 0 ; e < n; e++){
        cin>>associations[e];
        associations_calification[e] = associations[e];
    }
    sort(all(associations_calification));
    unordered_map<int,int> calification_to_index;
    for(int e = 0 ;e < n ; e++){
        calification_to_index[associations_calification[e]] = e+1;
    }

    for(int e = 0 ; e < n; e++){
        associations[e] = calification_to_index[associations[e]];
    }

    vector<pair<int,int>> ans(n);
    // Para usar unordered_map con pair<int,int> necesitamos definir un hash personalizado:
    
    unordered_map<pii, int, pair_hash> who;
    for(int e = 0 ; e < n; e++){
        ans[e] = {president[e] + associations[e], associations[e]};
        who[ans[e]] = e+1;
    }
    sort(all(ans), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    });

    int cont = 1;
    for(auto &e : ans){
        int label = who[e];
        int total = e.first;
        string kod = (label < 10 ? "Kod0" : "Kod") + to_string(label);
        cout << cont << ". " << kod << " (" << total << ")\n";
        cont++;
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