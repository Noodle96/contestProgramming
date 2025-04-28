/*
==========================================================
|  Archivo       : Triangles.cpp,.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-26 15:57
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
const ll TOPE = 2024;
const ld DIAGONAL = sqrt(2)*(ld)TOPE;
const ld EPSILON = 1e-9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int a,b,c,d;

ld distancia(ld x1, ld y1, ld x2, ld y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

bool verificarExtremosVertices(){
    ld a_ = (ld)a, b_ = (ld)b, c_ = (ld)c, d_ = (ld)d; 
    ld dis = distancia(a_,b_,c_,d_);
    if ( abs(dis - DIAGONAL) < EPSILON) return true;
    // cout << "dis fun: " << dis << endl;
    // cout << "dis DEFINE: " << DIAGONAL << endl;
    return false;
    // if(a == 0 && b == 0 && c == TOPE && d == TOPE) return true;
    // if(a == TOPE && b == TOPE && c == 0 && d == 0) return true;
    // if(a == 0 && b == TOPE && c == TOPE && d == 0) return true;
    // if(a == TOPE && b == 0 && c == 0 && d == TOPE) return true;
    // return false;
}

bool verificarMismoLado(){
    return (a == 0 && c == 0) ||
            (a == TOPE && c == TOPE) ||
            (b == 0 && d == 0) ||
            (b == TOPE && d == TOPE);
}

bool verificarVerticalHorizontal(){
    return (a == c) || (b == d); 
}

bool verificarDiagonalUnPunto(){
    bool ans = false;
    if( (a == 0 && b == 0 && d == TOPE ) || (c == 0 && d == 0 && b == TOPE) || (a == 0 && b == 0 && c == TOPE ) || (c == 0 && d == 0 && a == TOPE) ) ans |= true;
    if( (a == TOPE && b == 0 && d == TOPE) || (c == TOPE && d == 0 && b == TOPE) || (a == TOPE && b == 0 && c == 0) || (c == TOPE && d == 0 && a == 0)) ans |= true;
    if ((a == 0 && b == TOPE && d == 0)||(c == 0 && d == TOPE && b == 0) || (a == 0 && b == TOPE && c == TOPE)||(c == 0 && d == TOPE && a == TOPE)) ans |= true;
    if((a == TOPE && b == TOPE && d == 0) || (c == TOPE && d == TOPE && b == 0) || (a == TOPE && b == TOPE && c == 0) || (c == TOPE && d == TOPE && a == 0)) ans |= true;
    return ans;
}

bool verificarDiagonalNoPunto(){
    bool ans = false;
    if((b == TOPE && d == 0) || (b == 0 && d == TOPE)) ans |= true;
    if((a == 0 && c == TOPE) || a == TOPE && c == 0) ans |= true;
    return ans;
}

int ans = 0;
void solve(){
    cin>> a >> b >> c >> d;
    if( verificarMismoLado() ) ans = 1;
    else if(verificarExtremosVertices() ) ans = 0;
    else if(verificarVerticalHorizontal()) ans = 2;
    else if(verificarDiagonalUnPunto()) ans = 1;
    // else if(verificarDiagonalNoPunto()) ans = 2;
    else ans = 2;
    cout << ans << endl;

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