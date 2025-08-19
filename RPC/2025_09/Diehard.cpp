/*
==========================================================
|  Archivo       : Diehard.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-16
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementatio
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

pair<int,int> beats_counts(const array<int,6>& a, const array<int,6>& b){
    int p=0,q=0;
    for(int x: a){
        for(int y: b){
            if(x>y) ++p;
            else if(x<y) ++q;
        }
    }
    return {p,q};
}

void solve(){
    array<array<int,6>,3> dice;
    for(int i=0;i<3;i++)
        for(int k=0;k<6;k++)
            cin>>dice[i][k];

    auto valid = [&](int i)->bool{
        for(int j=0;j<3;j++){
            if(j==i) continue;
            auto [p,q]=beats_counts(dice[i], dice[j]);
            if(p+q==0) return false; // solo empates -> no ganador
            if(p<q)    return false; // peor que el otro dado
        }
        return true;
    };

    for(int i=0;i<3;i++){
        if(valid(i)){
            cout<< (i+1) << endl;
            return;
        }
    }
    cout<<"No dice" << endl;;
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