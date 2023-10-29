/*
	Category: Shortest Path
	Algorithm: Floyd Warshall
	Complejidad: O(n^3)
*/
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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const ll INF = INT_MAX;

void printMatrix(vector<vector<ll>> &A){
	for(int e = 0 ; e< 3; e++){
		for(int j = 0 ; j < 3; j++){
			if(A[e][j] == INF) cout << "INF";
			else cout << A[e][j];
			cout << " ";
		}cout << endl;
	}cout << endl;
}

void floydWarshall(vector<vector<ll>> M){
	int n = M.size();
	// printMatrix(M);
	for(int k = 0; k < n ; k++){
		for(int i = 0 ;i < n ; i++){
			for(int j = 0 ;j < n ; j++){
				M[i][j] = min(M[i][j],M[i][k]+M[k][j]);
			}
		}
		printMatrix(M);
	}
	cout << "matrix final: " << endl;
	printMatrix(M);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<ll>> A{{0,1,5},{1,0,8},{5,8,0}};
	floydWarshall(A);
	return 0;
}