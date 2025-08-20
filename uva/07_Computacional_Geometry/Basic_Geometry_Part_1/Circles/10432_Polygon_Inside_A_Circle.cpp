/*
==========================================================
|  Archivo       : 10432_Polygon_Inside_A_Circle.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-20 13:26
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Computational Geometry
|  - Circles and Polygons
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
const double EPS = 1e-9;
const double PI = acos(-1.0);

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

// 1−cos(θ) = 2sin^2(θ/2​)
double chord(double r, double degree){
    double toRadian = degree * PI / 180.0; // convert degree to radian
    // return sqrt(2*r*r*(1-cos(toRadian)));
    return 2 *  r * sin(toRadian / 2.0); // chord length
}

double heron(double side1, double side2, double side3 ){
    double s = (side1 + side2 + side3) / 2.0; // semi-perimeter
    return sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Heron's formula
}

void solve(){
    double r;
    int num_sides;
    while( cin >> r >> num_sides){
         double degree = 360.0/num_sides;
        // calculamos el area de cada triángulo

        // way 01
        // double area_i = 0.5 * r *r * sin(degree * PI / 180.0);
        // cout << fixed << setprecision(3);
        // cout << area_i * num_sides << endl; // area total del polígono

        // way02
        double base = chord(r, degree); // base of the triangle
        double area_i = heron(r, r, base); // area of the triangle
        cout << fixed << setprecision(3);
        cout << area_i * num_sides << endl; // total area of the polygon
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