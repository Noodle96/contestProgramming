/*
==========================================================
|  Archivo       : main.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-16 19:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Basic Geometry Objects with Libraries
|  - 7.2.1 Points in 2D space
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

// GEOMETRY OBJECTS
// Point in 2D space
// Note: Use EPS to compare floating-point numbers to avoid precision issues
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

struct Point_i{
    int x,y;
    Point_i() {x = y = 0;}
    Point_i(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (Point_i other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (Point_i other) const {
        return x == other.x && y == other.y;
    }
};

// Euclidean distance between two points
double dist(const Point &a, const Point &b) {
    // return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return hypot(a.x - b.x, a.y - b.y); // alternative return double
}

/*
    180 degrees = PI radians
    d degrees   = X radians

    solving X:
        X = d * PI / 180
*/
double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

/*
    180 degrees = PI radians
    X degrees   = r radians

    solving X:
        X = r * 180 / PI
*/
double RAD_to_DEG(double r) {
    return r * 180.0 / PI;
}

// rotate p by theta degrees CounterClockWise around the origin (0,0)
Point rotate(const Point &p, double theta){ // theta in degrees
    double rad = DEG_to_RAD(theta); // convert degrees to radians
    double cosTheta = cos(rad);
    double sinTheta = sin(rad);
    return Point(p.x * cosTheta - p.y * sinTheta,
                p.x * sinTheta + p.y * cosTheta);
}




// SUPORT FUNCTIONS
void failSorting(){
    // correct answer: 
    //     (0, 2)
    //     (1e-09, 0)
    //     (2e-09, 0)
    // however with EPS = 1e-9:
    // wrong answer: 
    //     (1e-09, 0)
    //     (0, 2)
    //     (2e-09, 0)
    vector<Point> P;
    P.emplace_back(2e-9,0);
    P.emplace_back(0,2);
    P.emplace_back(1e-9,0);
    sort(all(P));
    for (auto &p : P) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}
void equalPoints(){                      //13*1e-10
    Point p1(1e-9, 13), p2(0, 2), p3(1e-9, 13.0000000001);
    cout << (p1 == p2) << endl; // false
    cout << (p1 == p3) << endl; // true
    cout << (13.0000000001) << endl;
    cout << (13 + 1e-10) << endl;
}
void distanceBetweenPoints(){
    Point p1(0,0), p2(3,4), p3(1,1);
    cout << "Distance between p1 and p2: " << dist(p1, p2) << endl; // 5
}

void rotatePoint(){
    cout << PI << endl; // 3.14159...
    double theta = 90.0;
    cout << DEG_to_RAD(theta) << endl; // 1.57079...

    double twoPi = 2 * PI;
    cout << RAD_to_DEG(twoPi) << endl; // 360

    const Point p(10,1);
    double d = 180;
    Point rotatedPoint = rotate(p, d);
    cout << "Rotated Point: (" << rotatedPoint.x << ", " << rotatedPoint.y << ")\n"; // (-10, -1)
}


void solve(){
    // failSorting();
    // equalPoints();
    // distanceBetweenPoints();
    rotatePoint();
    
    
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