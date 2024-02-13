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
int r;

class SegmentTree{
	public:
		int m_n;
		vector<int> m_nodes;
		SegmentTree(vector<int> & VEC, int n){
			this->m_n = n;
			// this->m_nodes.resize(4*n);
			this->m_nodes.assign(4*n, 0);
			build(VEC, 0,0,n-1);
		}
		void build(vector<int> &VEC, int index, int start, int end){
			if(start == end){
				m_nodes[index] = VEC[start];
			} else{
				int mid = (start + end) / 2;
				build(VEC, 2*index+1, start, mid);
				build(VEC, 2*index+2, mid+1, end);
				m_nodes[index] = m_nodes[2*index+1] + m_nodes[2*index+2];
			}
		}
		void printTree(int node, int start, int end) {
			// Si el nodo representa una hoja, imprime su valor
			if (start == end) {
				cout << m_nodes[node] << " "; 
				return;
			}
			// Si no es una hoja, visita los hijos
			int mid = (start + end) / 2;
			printTree(2 * node + 1, start, mid); // Visitamos hijo izquierdo
			printTree( 2 * node + 2, mid + 1, end); // Visitamos hijo derecho
		}
		void printAllTree(){
			for(int e = 0 ; e < 4*m_n; e++){
				cout << m_nodes[e] << " ";
			}
			cout << endl;
		}
};

void solve(){
	cin>>r;
	int n = pow(2, r); // Número de equipos
	vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	SegmentTree ST(s,n);
	ST.printTree(0,0,n-1);
	cout << endl;
	ST.printAllTree();


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