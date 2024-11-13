#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int n;
ll a,b;
struct Point2d{
	ll x,y;
	Point2d(ll x_ = 0, ll y_ = 0){
		x= x_; y = y_;
	}
	bool operator < (Point2d &other){
		if(x == other.x)
			return y < other.y;
		return 	x < other.x;
	}
};

void solve(){
	while(cin>>n){
		if(n == 0 ) break;
		else{
			vector<Point2d> P;
			Point2d interseccion;
			for(int e = 0 ; e < n ; e++){
				cin>>a>>b;
				if(e == (n/2) ){	
					interseccion.x = a;
					interseccion.y = b;
				}else{
					P.emplace_back(a,b);
				}
			}
			// print points
			// msg("Print points","");
			// for(int e = 0  ; e < (int)P.size(); e++){
			// 	cout << P[e].x << " " << P[e].y << endl; 
			// }
			sort(all(P));
			int ollie = 0;
			int stan= 0;
			for(int e = 0 ; e <(int)P.size(); e++){
				if(P[e].x < interseccion.x && P[e].y > interseccion.y) ollie++;
			}
			for(int e = 0 ; e <(int)P.size(); e++){
				if(P[e].x > interseccion.x && P[e].y < interseccion.y) ollie++;
			}
			for(int e = 0 ; e <(int)P.size(); e++){
				if(P[e].x < interseccion.x && P[e].y < interseccion.y) stan++;
			}
			for(int e = 0 ; e <(int)P.size(); e++){
				if(P[e].x > interseccion.x && P[e].y > interseccion.y) stan++;
			}
			cout << stan << " " << ollie << endl;
		}
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