/*
==========================================================
|  Archivo       : 11343_Isolated_Segments.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-19 16:23
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Geometry Computational
|  - Lines: segments intersection
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
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (const Point &other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (const Point &other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};
struct vec{
    double x,y;
    vec() : x(0), y(0) {}
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(Point p1, Point p2) {
    return vec(p2.x - p1.x, p2.y - p1.y); // vector from p1 to p2
}
double cross(const vec &a, const vec &b) {
    return a.x * b.y - a.y * b.x; // cross product of vectors a and b
}

double ccw(Point p, Point q, Point r) {
    vec a = toVec(p, q);
    vec b = toVec(p, r);
    return cross(a, b); // cross product
}

bool eq0(double x){
    return fabs(x) < EPS; // check if x is approximately zero
}

// verificar que el punto p esta dentro del segmento [a,b]
// asumiendo la colinealidad de los puntos
bool onSegment(Point p, Point a, Point b) {
    // Check if point p is on segment [a,b]
    // x <= y : x < y + EPS
    // x >= y : x > y - EPS
    bool a_ = (p.x > min(a.x, b.x) - EPS);
    bool b_ = (p.x < max(a.x, b.x) + EPS);
    bool c_ = (p.y > min(a.y, b.y) - EPS);
    bool d_ = (p.y < max(a.y, b.y) + EPS);
    return a_ && b_ && c_ && d_;
}


bool segInter(Point p1, Point p2, Point p3, Point p4){
    double o1 = ccw(p1, p2, p3);
    double o2 = ccw(p1, p2, p4);
    double o3 = ccw(p3, p4, p1);
    double o4 = ccw(p3, p4, p2);

    // caso general, signos opuestos
    // x < y : x < y - EPS
    // x < 0 : x < -EPS
    if( o1*o2 < -EPS && o3*o4 < -EPS) return true;

    if(eq0(o1)  && onSegment(p3, p1, p2)) return true; // p3 sobre [p1,p2]
    if(eq0(o2) && onSegment(p4, p1, p2)) return true; // p4 sobre [p1,p2]
    if(eq0(o3) && onSegment(p1, p3, p4)) return true; // p1 sobre [p3,p4]
    if(eq0(o4) && onSegment(p2, p3, p4)) return true; // p2 sobre [p3,p4]
    return false; // no intersectan
}

void solve(){
    int n; cin >> n;
    vector<pair<Point, Point>> points;
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.emplace_back(Point(x1, y1), Point(x2, y2));
    }
    int ans = 0;
    for(int e = 0 ;e < points.size() ; e++){
        // al menos una intersección con otro segmento
        bool intersect = false;
        for(int j  = 0 ;j < points.size() ; j++){
            if(e != j){
                intersect |= segInter(points[e].first, points[e].second, points[j].first, points[j].second);
            }
        }
        if(!intersect) ans++;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    while(t--) solve();
    return 0;
}