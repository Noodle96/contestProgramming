/*
==========================================================
|  Archivo       : Duel.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-26 14:12
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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

void solve(){
    int n; cin>>n;
    set<int> Alice, Bob, visited;;
    for(int e = 0 ; e < 2*n; e++) visited.insert(e+1);
    for(int e = 0; e < n; e++){
        int a; cin>>a;
        Alice.insert(a);
        visited.erase(a);
    }
    for(auto e: visited){
        Bob.insert(e);
    }
    // cout << "Alice: ";
    // for(auto e: Alice){
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout << "Bob: ";
    // for(auto e: Bob){
    //     cout << e << " ";
    // }
    // cout << endl;
    // return;
    int maximos  = 0, minimos = 0;
    auto cpyBob = Bob;
    // para maximos
    for(auto alice_i: Alice){
        auto it = cpyBob.lower_bound(alice_i);
        // cout << *it << endl;
        auto first = cpyBob.begin();
        if(it != cpyBob.begin()){
            cpyBob.erase(first);
            maximos++;
        }
       // print BOB
        // cout << "Bob: ";
        // for(auto e: Bob){
        //     cout << e << " ";
        // }
        // cout << endl;
    }
    //para minimos
    for(auto alice_i: Alice){
        auto it = Bob.upper_bound(alice_i);
        if(it != Bob.end()){
            Bob.erase(it);
            minimos++;
        }
    }
    minimos = n - minimos;
    cout << minimos << " " << maximos << endl;
}
void solve2(){
    // vector<int> a = {1,5,6};
    // auto lower = lower_bound(all(a), 2);
    // cout << (lower- a.begin()) << endl;
    
    std::set<int> v = {1, 2, 3, 4, 5, 7, 8};
    int x = 8;
    auto it = v.upper_bound(x);
    if(it != v.end()){
        cout << "El siguiente elemento mayor a " << x << " es: " << *it << endl;
    }else{
        cout << "No hay elementos mayores a " << x << endl;
    }

    // Encontrar la cantidad de elementos menores que x
    // auto it = std::upper_bound(v.begin(), v.end(), x);
    // int count = it - v.begin();
    // // std::cout << "Cantidad de elementos menores a " << x << " es: " << count << std::endl;
    // std::cout<< count << std::endl;

    // auto final = prev(v.end());
    // cout << "fina: " << *final << endl;

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