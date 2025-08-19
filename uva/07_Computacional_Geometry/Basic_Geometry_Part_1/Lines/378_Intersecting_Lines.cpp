/*
==========================================================
|  Archivo       : 378_Intersecting_Lines.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-19 00:39
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Computational Geometry
|  - Line Intersection
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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

struct Point{
    double x,y;
    Point(): x(0.0), y(0.0){}
    Point(double x_, double y_): x(x_), y(y_){}
    bool operator < (Point other) const{
        // si las x son diferentes
        if( fabs(x - other.x) > EPS)
            return x < other.x;
        // si las x son iguales, comparar las y
        return y < other.y;
    }
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
    }
};

struct Line{
    double a, b, c; // ax + by + c = 0
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(Point p1, Point p2) {
        if(abs(p1.x - p2.x) < EPS){
            a = 1.0; b = 0.0; c = -p1.x; // vertical line
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(double)(a * p1.x) - p1.y; // y-intercept
        }
    }
};

bool areParallel(const Line &l1, const Line &l2){
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(const Line &l1, const Line &l2){
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(Line l1, Line l2, Point &intersection){
    if(areParallel(l1, l2)) return false; // Lines are parallel, no intersection
    // solve system of 2 linear algebraic equations with 2 variables
    intersection.x = (-l1.b * l2.c + l2.b * l1.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS)
        intersection.y = -l1.c - l1.a * intersection.x;
    else
        intersection.y = -l2.c - l2.a * intersection.x; // handle vertical line case
    return true; // Lines intersect at point 'intersection'
}
void solve(){
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(n--){
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Point p1(x1,y1), p2(x2,y2), p3(x3,y3), p4(x4,y4);
        Line l1(p1,p2), l2(p3,p4);
        Point inter;

        bool ans_same = areSame(l1, l2);
        if(ans_same){
            cout << "LINE" << endl;
            continue;
        }
        bool ans_parallel = areParallel(l1, l2);
        if(ans_parallel){
            cout << "NONE" << endl;
            continue;
        }
        areIntersect(l1, l2, inter);
        cout << "POINT "<< fixed << setprecision(2 )<< inter.x << " " << inter.y << endl;
    }
    cout <<"END OF OUTPUT" << endl;
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