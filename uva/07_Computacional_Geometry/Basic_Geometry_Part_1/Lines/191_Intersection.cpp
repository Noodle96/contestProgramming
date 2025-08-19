/*
==========================================================
|  Archivo       : 191_Intersection.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-18 12:30
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Geometrie Computacional
|  - CCW(Counter Clock Wise) test
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

struct Point {
    double x,y;
    Point() {x = y = 0.0;}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (Point other) const {
        if ( fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (Point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct vec{
    double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};  

vec toVec(Point p1, Point p2){
    return vec(p2.x - p1.x, p2.y - p1.y); //p1->p2
}

double cross(const vec &a, const vec &b) {
    return a.x * b.y - a.y * b.x; // a x b
}
// ccw(a,b,c) > 0 => a->b->c CCW; < 0 => CW; ~0 => colineales
double ccw(Point p, Point q, Point r) {
    vec a = toVec(p, q);
    vec b = toVec(p, r);
    return cross(a, b); // cross product
}

// check if x is approximately zero
bool eq0(double x) {
    return fabs(x) < EPS;
}

// Verificar si p está dentro del segmento pq (asumiendo colinealidad)
bool onSegment(const Point& a, const Point& b, const Point& p){
    // x <= y : x < y + EPS
    // x >= y : x > y - EPS

    // p.x >= min(a.x,b.x )
    bool a_ = ( p.x > min(a.x, b.x) - EPS);
    //p.x <= max(a.x,b.x )
    bool b_ = (p.x < max(a.x, b.x) + EPS);
    // p.y >= min(a.y,b.y )
    bool c_ = (p.y > min(a.y, b.y) - EPS);
    // p.y <= max(a.y,b.y )
    bool d_ = (p.y < max(a.y, b.y) + EPS);
    
    return a_ && b_ && c_ && d_;
    // return (min(a.x,b.x) - EPS <= p.x && p.x <= max(a.x,b.x) + EPS &&
    //         min(a.y,b.y) - EPS <= p.y && p.y <= max(a.y,b.y) + EPS);
}

// Intersección de segmentos [a,b] y [c,d]
bool segInter(const Point &a, const Point &b, const Point &c, const Point &d){
    double o1 = ccw(a, b, c);
    double o2 = ccw(a, b, d);
    double o3 = ccw(c, d, a);
    double o4 = ccw(c, d, b);
    // cout << "o1: " << o1 << ", o2: " << o2 << ", o3: " << o3 << ", o4: " << o4 << endl;

    // caso general, signos opuestos
    // x <  y : x < y - EPS
    // x < 0 :  x < -EPS
    if (o1 * o2 < -EPS && o3 * o4 < -EPS) return true;

    // Casos colineales (punto sobre segmento)
    if(eq0(o1) && onSegment(a, b, c)) return true; // c sobre [a,b]
    if(eq0(o2) && onSegment(a, b, d)) return true; // d sobre [a,b]
    if(eq0(o3) && onSegment(c, d, a)) return true; // a sobre [c,d]
    if(eq0(o4) && onSegment(c, d, b)) return true; // b sobre [c,d]
    return false; // no intersectan
} 

// Punto dentro (o en el borde) del rectángulo alineado a ejes
bool inRect(const Point& p, double xl, double xr, double yb, double yt){
    return (xl - EPS < p.x && p.x < xr + EPS &&
            yb - EPS < p.y && p.y < yt + EPS);
}


void solve(){
    int n; cin >> n;
    double xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    while(n--){
        cin >> xstart >> ystart >> xend >> yend;
        cin >> xleft >> ytop >> xright >> ybottom;

        // Normalizamos el rectabgulo
        if(xleft > xright) swap(xleft, xright);
        if(ybottom > ytop) swap(ybottom, ytop);
        
        Point p1(xstart, ystart), p2(xend, yend);
        Point lt(xleft, ytop), rt(xright, ytop);
        Point lb(xleft, ybottom), rb(xright, ybottom);

        // if(p1 == p2){
        //     bool ans = p1.x > xleft -EPS && p1.x < xright + EPS &&
        //                p1.y > ybottom - EPS && p1.y < ytop + EPS;
        //     cout << (ans ? "T" : "F") << endl;
        //     continue;
        // }
        if( inRect(p1, xleft, xright, ybottom, ytop) || inRect(p2, xleft, xright, ybottom, ytop) ){
            cout << "T" << endl;
            continue;
        }

        bool ans = segInter(p1, p2, lt, rt) || // top edge
                   segInter(p1, p2, rt, rb) || // right edge
                   segInter(p1, p2, rb, lb) || // bottom edge
                   segInter(p1, p2, lb, lt);   // left edge
        cout << (ans ? "T" : "F") << endl;
        
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
// 5 10 5 10 4 7 7 5
