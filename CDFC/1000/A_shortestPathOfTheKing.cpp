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
void solve(){
	pair<char,int> p1,p2;
	cin>> p1.first >> p1.second;
	cin>>p2.first>>p2.second;
	vector<string> ans;
	int shortestPath = 0;
	while(1){
		if(p1.first == p2.first || p1.second == p2.second) break;
		else{
			string temp;
			if(p1.first < p2.first){
				//cout << "R";
				temp += "R";
				if(p1.second > p2.second){
					//cout << "D\n";
					temp += "D";
					p1 = {++p1.first, --p1.second};
				}else{
					//cout << "U\n";
					temp += "U";
					p1 = {++p1.first,++p1.second};
				}
				ans.pb(temp);
				shortestPath += 1;
			}else{
				temp += "L";
				//cout << "L";
				if(p1.second > p2.second){
					//cout << "D\n";
					temp+="D";
					p1 = {--p1.first, --p1.second};
				}else{
					//cout << "U\n";
					temp += "U";
					p1 = {--p1.first, ++p1.second};
				}
				ans.pb(temp);
				shortestPath += 1;
			}
		}
	}
	// row or columns
	if(p1.first == p2.first && p1.second == p2.second){
		cout << shortestPath << endl;
		for(int e = 0 ; e < ans.size(); e++){
			cout << ans[e] << endl;
		}cout <<endl;
		return;
	}else{
		if(p1.first == p2.first){ // same column
			int distance = abs(p1.second-p2.second);
			if(p1.second > p2.second){
				for(int e = 0 ; e < distance; e++){
					ans.pb("D");
				}
				shortestPath += distance;
			}else{
				for(int e = 0 ;e < distance ; e++){
					ans.pb("U");
				}
				shortestPath += distance;
			}
		}else{
			//same row
			int distance = abs(p1.first-p2.first);
			if(p1.first < p2.first){
				for(int e = 0 ;e < distance ; e++){
					ans.pb("R");
				}
				shortestPath += distance;
			}else{
				for(int e = 0 ;e < distance ; e++){
					ans.pb("L");
				}
				shortestPath += distance;
			}
		}
	}
	cout << shortestPath << endl;
	for(int e = 0 ;e < ans.size() ; e++){
		cout << ans[e] << endl;
	}cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}