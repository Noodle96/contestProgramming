/*
==========================================================
|  Archivo       : 10263_Railway.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-19 15:12
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Compiutational Geometry
|  - Lines and segments:  minimum distance
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
    return vec(p2.x - p1.x, p2.y - p1.y); // vector from p1->p2
}

vec scale(const vec &v, double s) {
    return vec(v.x * s, v.y * s); // scale vector v by s
}
Point translate(const Point &p, const vec &v) {
    return Point(p.x + v.x, p.y + v.y); // translate point p by vector v
}

double dot(const vec &a, const vec &b) {
    return a.x * b.x + a.y * b.y; // dot product of vectors a and b
}
double norm_sq(const vec &v) {
    return v.x * v.x + v.y * v.y; // square of the norm of vector v
}
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); // Euclidean distance
}
double distToLine(Point p, Point a, Point b, Point &c){
    vec ap = toVec(a,p);
    vec ab = toVec(a,b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // closest point on line
    return dist(p, c); // distance from point p to line ab
}
double distToLineSegment(Point p, Point a, Point b, Point &c) {
    vec ap = toVec(a, p);
    vec ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { // closest point is a
        c = a;
        return dist(p, a); // distance from p to a
    } else if (u > 1.0) { // closest point is b
        c = b;
        return dist(p, b); // distance from p to b
    }
    return distToLine(p, a, b, c); // closest point is between a and b
}
void solve(){
    double xm,ym;
    while(cin >> xm >> ym){
        Point M(xm, ym);
        int n;
        cin >> n;
        vector<Point> points(n+1);
        for(int e = 0 ; e < n+1; e++){
            cin >> points[e].x >> points[e].y;
        }
        Point c, ans_point_station;
        double ans = INF;
        for(int e = 0 ; e < n ; e++){
            double d = distToLineSegment(M, points[e], points[e+1], c);
            if( d < ans){
                ans = d;
                ans_point_station = c; // closest point on the segment
            }
        }
        cout << fixed << setprecision(4);
        cout << ans_point_station.x << "\n" << ans_point_station.y << "\n";
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