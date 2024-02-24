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

int n,m,numLanguages;

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
	cin>>n>>m;
	vector<vector<int>> languages(n);
	for(int e = 0 ; e < n; e++){
		cin>>numLanguages;
		languages[e].assign(numLanguages,0);
		for(int j = 0 ; j < numLanguages; j++){
			cin >> languages[e][j];
		}
	}
	bool flag = true;
	for(int e = 0 ; e < n;e++){
		if(languages[e].size() > 0) flag = false;
	}
	if(flag){
		cout << n << endl;
		return;
	}
	// print languages
	// cout << "lan:" << endl;
	// for(int e = 0  ; e < n; e++){
	// 	for(auto j: languages[e]){
	// 		cout << j << " ";
	// 	}cout << endl;
	// }cout << endl;
	UnionFind dsu(n);
	for(int e  = 0 ; e < n; e++){
		for(int j = e+1 ; j < n; j++){
			for(auto k: languages[e]){
				auto it = find(languages[j].begin(), languages[j].end(),k);
				if(it != languages[j].end()){
					dsu.unionSet(e,j);
					break;
				}
			}
		}
	}
	cout << dsu.numDisjointSets() - 1 << endl;

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