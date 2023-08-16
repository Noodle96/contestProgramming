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
void solve(){
	int n; cin>>n;
	vector<int> candies(n);
	for(int e = 0 ; e < n; e++) cin>>candies[e];
	int left = -1;
	int right = n;
	bool turnoAlice = true;
	int contMov = 0;
	int Alice = 0, bob = 0;
	int maximo = INT_MIN;
	bool finalGame = false;
	while(1){
		if(turnoAlice){
			left++;
			// cout << "turno alice" <<endl;
			if(left < right){
				// cout << "alice_ left < right" <<endl;
				if(candies[left] > maximo){
					// cout <<"alice_ caso1" << endl;
					Alice += candies[left];
					maximo = candies[left];
					// left++;
					contMov++;
					// cout << "-----------------" << endl;
					// cout << left << " "<< contMov << " " << maximo << endl;
					// cout << "-----------------" << endl;
				}else{
					// cout << "alice_caso2" <<endl;
					int total = candies[left];
					Alice += candies[left];
					while(!(total > maximo)){
						left++;
						if(left < right){
							total +=candies[left];
							Alice += candies[left];
						}else{
							finalGame = true;
							break;
						}
					}
					maximo = total;
					// left++;
					contMov++;
					// cout << "-----------------" << endl;
					// cout << left << " "<< contMov << " " << maximo << endl;
					// cout << "-----------------" << endl;
				}
			}else{
				// cout << "break  alice" << endl;
				break;
			}
			if(finalGame){
				// cout << "break final game alice" << endl;
				break;	
			}
			turnoAlice = false;
		}else{
			right--;
			// cout << "turno bob" <<endl;
			if(right > left){
				// cout << "bob_ right > left" << endl;
				if(candies[right] > maximo){
					// cout << "bob_caso1" << endl;
					bob += candies[right];
					maximo = candies[right];
					// right--;
					contMov++;
					// cout << "-----------------" << endl;
					// cout << right << " "<< contMov << " " << maximo << endl;
					// cout << "-----------------" << endl;
				}else{
					// cout << "bob_caso2" << endl;
					int total = candies[right];
					bob += candies[right];
					while(!(total > maximo)){
						right--;
						if(right> left){
							total += candies[right];
							bob += candies[right];
						}else{
							finalGame = true;
							break;
						}
					}
					maximo = total;
					// right--;
					contMov++;
					// cout << "-----------------" << endl;
					// cout << right << " "<< contMov << " " << maximo << endl;
					// cout << "-----------------" << endl;
				}
			}else{
				// cout << "break  bob" << endl;
				break;
			}
			if(finalGame){
				// cout << "break final game bob" << endl;
				break;
			}
			turnoAlice = true;
		}
	}

	// cout << "cantidad mov: " << contMov << " " << Alice << " " << bob	 << endl;
	cout << contMov << " " << Alice << " " << bob << endl;

}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}