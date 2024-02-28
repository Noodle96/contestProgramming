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
using lii = tuple<ll,int,int>;
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

int N,k,M;
int u,v;
ll w;
string line;

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
bool flag = false;
void solve(){
	while(cin>>N){
		if(flag) cout << endl;
		else flag = true;
		for(int e = 0 ;e < N-1 ; e++){
			cin>>u>>v>>w;
		}
		cin>>k;
		vector<lii> K;
		for(int e = 0 ; e < k ;e++){
			cin>>u>>v>>w;
			u--,v--;
			K.pb({w,u,v});
		}
		cin>>M;
		vector<lii> E;
		for(int e = 0 ; e < M; e++){
			cin>>u>>v>>w;
			u--,v--;
			E.pb({w,u,v});
		}
		sort(all(E));
		ll mst_cost = 0;
		int num_taken = 0;
		UnionFind UF(N);
		for(auto &[w,u,v]:E){
			if(UF.isSameSet(u,v)) continue;
			mst_cost += w;
			UF.unionSet(u,v);
			num_taken++;
			if(num_taken == N-1) break;
		}
		for(auto &[w,u,v]:K){
			E.pb({w,u,v});
		}
		sort(all(E));
		UnionFind UF_k(N);
		ll mst_cost_k = 0;
		num_taken = 0;
		for(auto &[w,u,v]:E){
			if(UF_k.isSameSet(u,v)) continue;
			mst_cost_k += w;
			UF_k.unionSet(u,v);
			num_taken++;
			if(num_taken == N-1) break;
		}
		// cout << "mst_cost: " << mst_cost << endl;
		// cout << "mst_with k: " << mst_cost_k <<endl;
		cout << mst_cost << endl;
		cout << mst_cost_k << endl;
		cin.ignore();
		getline(cin,line);
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