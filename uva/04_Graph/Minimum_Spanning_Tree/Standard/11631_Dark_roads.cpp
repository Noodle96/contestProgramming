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
using lii =tuple<ll,int,int>;
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
int m,n;
void solve(){
	while(cin>>m>>n){
		if(m == 0 && n == 0 ) break;
		else{
			vector<lii> E;
			ll totalCosto = 0;
			for(int e = 0; e < n; e++){
				int u,v; ll w;
				cin >> u >> v >> w;
				totalCosto += w;
				E.emplace_back(w,u,v);
			}
			sort(all(E));
			UnionFind UF(m);
			ll mst_cost = 0;
			int num_taken = 0;
			for(int i = 0; i < n; i++){
				auto [w,u,v] = E[i];
				if(UF.isSameSet(u,v)) continue;
				mst_cost += w;
				UF.unionSet(u,v);
				num_taken++;
				if(num_taken == m-1) break;
			}
			cout << totalCosto - mst_cost << endl;
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