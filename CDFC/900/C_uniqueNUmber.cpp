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

int x;
int numbers[]={1,2,3,4,5,6,7,8,9};
vector<int> ans;
string rpta;
int sumaVector(vector<int> vec){
	int cont = 0;
	for(int e = 0 ;e < vec.size() ;e++){
		cont  += vec[e];
	}
	return cont;
}
void r(vector<int> temp, int i){
	
	// if(i>=3){
	// 	cout << "print vector" << endl;
	// 	for(int e = 0 ;e < temp.size() ; e++){
	// 		cout << temp[e] << " ";
	// 	}cout << endl;
	// 	return;
	// }
	if(sumaVector(temp) == x){
		// cout << "print vector" << endl;
		for(int e = 0 ;e < temp.size() ; e++){
			//cout << temp[e] << " ";
			rpta += to_string(temp[e]);
		}
		ans.pb(stoi(rpta));
		rpta =  "";
		//cout << endl;
		return;
	}
	if(i>= 9) return;
	r(temp,i+1);
	temp.pb(numbers[i]);
	r(temp,i+1);
}
void solve(){
	cin>>x;
	vector<int> temp;
	ans.clear();
	r(temp,0);
	sort(all(ans));
	// for(int e = 0 ; e < ans.size(); e++){
	// 	cout << ans[e] << " ";
	// }cout <<endl;
	if(!ans.empty()) cout << ans[0] << endl;
	else cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}