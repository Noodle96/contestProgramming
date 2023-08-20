#include <bits/stdc++.h>
using namespace std;

int SUM;
bool flag = false;
// pos -> [0, N-1]
void rec(int pos, int currSum, int N, const vector<int>& A, vector<int> sub) {
	// condicion de parada o termino
	// Hemos procesado todos los elementos del array A
	if (pos == N) {
		if (currSum == SUM) {
			// encontre un subconjunto cuya suma de elementos es igual a SUM
			// cout << "YES\n";
			flag = true;
			return;	
	
		}
		// cout << "SUbconjunto generado: ";
		// for (int elem : sub) {
		// 		cout << elem << " ";
		// }
		// cout << "\n";
		return;
	}

	// primera posibilidad: Tomo A[pos]
	vector<int> newSub = sub;
	newSub.push_back(A[pos]);
	rec(pos+1, currSum + A[pos], N, A, newSub);
	// segunda posibilidad: Ignoro A[pos]
	rec(pos+1, currSum         , N, A, sub);
}
void solve(){
	flag = false;
	cin>>SUM;
	int p; cin>>p;
	vector<int> A;
	vector<int> sub;
	for(int e = 0,temp ; e < p; e++){
		cin>>temp;
		A.push_back(temp);
	}
	rec(0,0,p,A,sub);
	if(flag) cout << "YES\n";
	else cout << "NO\n";
}
int main (){
	ios_base::sync_with_stdio(false);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	// SUM = 40;
	// int N = 3;
	// vector<int> A = {25, 5, 15};
	// vector<int> sub;
	// rec(0, 0, N, A, sub);
	return 0;	
}