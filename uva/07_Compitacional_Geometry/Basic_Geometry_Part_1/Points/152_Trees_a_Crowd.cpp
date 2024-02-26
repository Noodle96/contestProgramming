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
double a,b,c;
const double INF = 1e9;

struct Point3d{
	double x,y,z;
	Point3d(){x = y = z = 0;}
	Point3d(double x_, double y_, double z_ ){ x = x_; y = y_; z = z_;}
};

double distance(Point3d &p1, Point3d &p2){
	double a = (p1.x-p2.x)*(p1.x-p2.x);
	double b = (p1.y-p2.y)*(p1.y-p2.y);
	double c = (p1.z-p2.z)*(p1.z-p2.z);
	return sqrt(a+b+c);
}
int lenNumber(int n){
	string s = to_string(n);
	return (int)s.size();
}
string spaces(int n){
	string ans = "";
	for(int e = 0 ; e < n; e++){
		ans += " ";
	}
	return ans;
}
void solve(){
	vector<Point3d> P;
	while(cin>>a>>b>>c){
		if(a == 0 && b == 0 && c == 0) break;
		else{
			P.emplace_back(a,b,c);
		}
	}
	// for(int e = 0 ; e < (int)P.size() ; e++){
	// 	cout << P[e].x << " " << P[e].y <<  " " << P[e].z << endl;
	// }
	vector<double> closest_neighbours((int)P.size(), INF);
	for(int e = 0 ; e < (int)P.size() ; e++){
		for(int j = 0 ; j < (int)P.size(); j++){
			if(e !=j ){
				closest_neighbours[e] = min(closest_neighbours[e], distance(P[e],P[j]));
			}
		}
	}
	// print closest_neighbours
	// for(auto e :closest_neighbours){
	// 	cout << e << " ";
	// }cout << endl;

	vector<pair<int,int>> histograma(10);
	for(int e = 0 ; e < (int)closest_neighbours.size(); e++){
		for(int k = 0 ; k <= 9; k++){
			if( k <= closest_neighbours[e] && closest_neighbours[e] < (k+1)){
				histograma[k].first++;
				break;
			}
		}
	}
	for(int e = 0 ; e < 10; e++){
		histograma[e].second = lenNumber(histograma[e].first);
	}
	for(auto e : histograma)
		cout <<spaces(4-e.second) << e.first;
	cout << endl;
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