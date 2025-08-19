/*
==========================================================
|  Archivo       : main.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-16 20:51
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Basic Geometry Objects with Libraries
|  - 7.2.2 Lines in 2D space
==========================================================
*/

/*
    x >= y : x > y - EPS
    x >  y : x > y + EPS

    x <= y : x < y + EPS
    x <  y : x < y - EPS

    x == y : fabs(x - y) < EPS 
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
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


struct Line{
    double a,b,c; // ax + by + c = 0
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    // Constructor from two points
    Line(Point p1, Point p2){
        if (fabs(p1.x - p2.x) < EPS) { // vertical line
            a = 1.0; b = 0.0; c = -p1.x;
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(double)(a * p1.x) - p1.y;
        }
    }
    // Constructor from slope and point
    Line(Point p, double m) {
        a = -m; // slope
        b = 1.0; // y-intercept
        c = -(a * p.x + p.y); // line equation
    }

};

bool areParallel(const Line &l1, const Line &l2){
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b- l2.b) < EPS);
}
bool areSame(const Line &l1, const Line &l2){
    return areParallel(l1,l2) && (fabs(l1.c -l2.c) < EPS);
}
bool areIntersect(Line l1, Line l2, Point &intersection){
    if(areParallel(l1, l2)) return false; // Lines are parallel, no intersection)
    // solve system of 2 linear algebraic equations with 2 variables
    intersection.x = (-l1.b*l2.c + l2.b*l1.c) / (l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b) > EPS)
        intersection.y = -l1.c - l1.a * intersection.x;
    else
        intersection.y = -l2.c -l2.a * intersection.x;
    return true; // Lines intersect at point 'intersection'
}

struct vec {
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const Point &a, const Point &b) { // convert 2 points
    return vec(b.x-a.x, b.y-a.y);           // to vector a->b
}


vec scale(const vec &v, double s) { // s = [<1..1..>1]
    return vec(v.x*s, v.y*s);       // shorter/eq/longer
}                                   // return a new vec



Point translate(const Point &p, const vec &v) { // translate p
    return Point(p.x+v.x, p.y+v.y);             // according to v
}                                               // return a new poin


double angle(const Point &a, const Point &o, const Point &b){
    vec oa = toVec(o, a); // vector o->a  a != O & b != O
    vec ob = toVec(o,b); // vecto o->b
    double dot_oa_ob = oa.x * ob.x + oa.y * ob.y; // dot product
    double norm_oa = sqrt(oa.x * oa.x + oa.y * oa.y); // norm of vector oa
    double norm_ob = sqrt(ob.x * ob.x + ob.y * ob.y); // norm of vector ob
    if (norm_oa < EPS || norm_ob < EPS) return 0.0; // avoid division by zero
    return acos( dot_oa_ob / (norm_oa * norm_ob) ); // angle in radians
}

double cross(vec a, vec b){return a.x*b.y - a.y*b.x;} // cross product of vectors a and b
bool ccw(Point p, Point q, Point r){
    return cross(toVec(p, q), toVec(p, r)) > EPS; // true if p->q->r is counter-clockwise
}

// returns true if point r is on the same line as the line pq
bool collinear(Point p, Point q, Point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// Lo dividimos por 2 ya que el (0,0,z) el "z" es el area del paralelogramo
// y el area del triangulo es la mitad de esa area
double area(Point p, Point q, Point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) / 2.0; // area of triangle pqr
}

void solve(){
    Point p1(0, 0), p2(1, 1), p3(0,2), p4(2,4);
    Line l1(p1,p2), l2(p1,p2);
    cout << areParallel(l1, l2) << endl; // 1 (true)
    cout << areSame(l1, l2) << endl; // 1 (true

    Line l3(p3, p4);
    cout << areParallel(l1, l3) << endl; // 1 (true)
    cout << areSame(l1, l3) << endl; // 0 (false

    cout << "angle" << endl;
    Point a(0, 5), o(0,0), b(50, 0);
    cout << angle(a, o, b) << endl; // 1.5708 (90 degrees in radians)
    cout << PI/2<< endl; // 1.5708 (90 degrees in radians)

    cout << "russel test" << endl;
    cout << (-1 < EPS) << endl;
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