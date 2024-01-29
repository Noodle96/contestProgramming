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
using vii = vector<int>;
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
int swaps;

int mergePairSort(vii &A, int left1, int right1, int left2, int right2){
	// cout << "in mergePair" << endl;
	// cout << "left:" << endl;
	// for(int e = left1; e <= right1; e++){
	// 	cout << A[e] << " ";
	// }cout << endl;
	// cout << "right:" << endl;
	// for(int e = left2 ; e <= right2; e++){
	// 	cout << A[e] << " ";
	// }cout << endl;
	if(A[left2] < A[right1]){ // cambiar bloque derecho al lado izquierdo
		//supongamos que lo hemos cambiado
		if(A[right2] < A[left1]){ // es correcto
			vector<int> left = vector<int>(A.begin()+left2, A.begin()+right2+1);
			// cout << "print copy to left" <<endl;
			// for(auto e: left)cout << e << " ";cout << endl;

			vector<int> right = vector<int>(A.begin()+left1, A.begin()+right1+1);
			// cout << "print copy to right" << endl;
			// for(auto e: right)cout << e << " ";cout << endl;


			for(int e = left1 , j = 0; e <= right1; e++,j++){
				A[e] = left[j];
			}
			for(int e = left2 ,j = 0; e <= right2; e++,j++){
				A[e] = right[j];
			}
			swaps++;
			// print from left1 to right2
			// cout << "print partial" << endl;

			// for(int e = left1; e <= right2; e++){
			// 	cout << e << ": " << A[e] << endl;
			// }cout << endl;
			return true;
		}else{// es imposible
			return false;
		}
	}else{
		// no hay que hacer nada esta ordenado
		return true;
	}
}

bool pairSort(vii &A, int left, int right){
	if((right-left) == 1){
		// cout << "if: " << left << " " << right << endl;
		if(A[left] > A[right]){
			// cout << left+1 << " " << right+1 << endl;
			swap(A[left], A[right]);
			swaps++;
		}
		return true;
	}else{
		// cout << "else: " << left << " " << right << endl;
		int mid = (left+right)/2;
		bool a = pairSort(A, left, mid);
		bool b = pairSort(A, mid+1, right);
		bool c = mergePairSort(A, left, mid, mid+1,right);
		return a && b && c;
	}
}

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int e = 0 ; e < n ; e++) cin>>a[e];
	if(n==1){cout << 0 << endl;return;}
	swaps = 0;
	bool ans = pairSort(a, 0, n-1);
	if(ans){
		cout << swaps << endl;
	}else cout << -1 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}