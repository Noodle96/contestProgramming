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

void solve2(int N){
	bool flag = false;
	for (int fghij = 1234; fghij <= 98765/N; ++fghij) {
		int abcde = fghij*N;
		// as discussed above
		int tmp, used = (fghij < 10000);
		// flag if f = 0
		tmp = abcde; while (tmp) { used |= 1<<(tmp%10); tmp /= 10; }
		tmp = fghij; while (tmp) { used |= 1<<(tmp%10); tmp /= 10; }
		if (used == (1<<10)-1){
			flag = true;
			// all 10 digits are used
			printf("%05d / %05d = %d\n", abcde, fghij, N);
		}
	}
	if(!flag){
		cout << "There are no solutions for " << N << "." << endl;
	}
}

void solve(int N){
	bool flag = false;
	int n = 10;
	int digits[10] = {0,1,2,3,4,5,6,7,8,9};
	do{
		// for(int e = 0 ; e < n; e++){
		// 	cout << digits[e] << " ";
		// }cout << endl;
		int e = 0;
		int numerador= 0, denominador = 0;
		int pot = 4;
		for( ;e < n/2 ; e++){
			numerador += ( digits[e] * pow(10,pot--));
		}
		pot = 4;
		for(; e < n; e++){
			denominador += (digits[e] * pow(10,pot--));
		}
		
		if(numerador%denominador == 0){
			if(numerador/denominador == N){
				flag = true;
				if(digits[0] == 0){
					cout << 0;
				}
				cout << numerador << " / ";
				if(digits[5] == 0){
					cout << 0;
				}
				cout << denominador <<" = " << N <<  endl;
			}
		}
	}while(next_permutation(digits, digits + n));
	if(!flag){
		cout << "There are no solutions for " << N << "." << endl;
	}
}
int main(){
	int N; cin>>N;
	if(N!=0)solve2(N);
	else return 0 ;
	while(cin>>N){
		// for(int e =1 ; e < 80; e++){
		// 	startTime = clock();
		if(N != 0){
			cout << endl;
			solve2(N);
		}else{
			break;
		}
		// cout << endl;
		// 	cout <<  getCurrentTime() << endl;
		// }
		
	}
	return 0;
}