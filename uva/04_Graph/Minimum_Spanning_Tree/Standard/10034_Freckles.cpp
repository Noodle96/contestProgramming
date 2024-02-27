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
using dii = tuple<double, int, int>;

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
string line;
int n;

double distancia(pair<double,double> &a,pair<double,double> &b){
	return hypot(a.first-b.first, a.second-b.second);
}

class UnionFind {                            // OOP style
private:
	vector<int> p, rank, setSize;                           // vi p is the key part
	int numSets;
public:
	UnionFind(int N) {
		p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
		rank.assign(N, 0);                           // optional speedup
		setSize.assign(N, 1);                        // optional feature
		numSets = N;                                 // optional feature
	}

	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	int numDisjointSets() { return numSets; }      // optional
	int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

	void unionSet(int i, int j) {
		if (isSameSet(i, j)) return;                 // i and j are in same set
		int x = findSet(i), y = findSet(j);          // find both rep items
		if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
		p[x] = y;                                    // set x under y
		if (rank[x] == rank[y]) ++rank[y];           // optional speedup
		setSize[y] += setSize[x];                    // combine set sizes at y
		--numSets;                                   // a union reduces numSets
	}
};

void solve(){
	cin>>n;
	vector< pair<double, double> > P(n);
	for(int e  = 0 ; e < n; e++){
		cin>>P[e].first>>P[e].second;
	}
	// cout << "print points" << endl;
	// for(auto p:P){
	// 	cout << p.first << " " << p.second << endl;
	// }
	vector<dii> distances;
	for(int e = 0 ; e < n; e++){
		for(int j = e+1; j < n; j++){
			double distance = distancia(P[e], P[j]);
			distances.emplace_back(distance, e,j);
		}
	}
	sort(all(distances));
	// print distancias
	// for(auto &[w,u,v]: distances){
	// 		cout << w << " " << u << " " << v << endl; 
	// }
	UnionFind dsu(n);
	int num_taken = 0;
	double mst = 0.0;
	for(int e  = 0 ;e < (int)distances.size() ;e++){
		auto [w,u,v] = distances[e];
		if(dsu.isSameSet(u,v)) continue;
		mst += w;
		dsu.unionSet(u,v);
		num_taken++;
		if(num_taken == n-1) break;
	}
	cout << fixed << setprecision(2) <<  mst << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	cin.ignore();
	while(t--){
		solve();
		if(t != 0) cout << endl;
	}
	
	return 0;
}