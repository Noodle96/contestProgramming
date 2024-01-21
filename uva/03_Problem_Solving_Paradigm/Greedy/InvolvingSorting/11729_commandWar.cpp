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

bool sortbyfirst(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first >b.first);
}
void solve(int n, int caso){
	vector<pii> vecpairs;
	for(int e = 0,B,J ;e < n ; e++){
		cin>>B>>J;
		vecpairs.pb(mp(J,B));
	}
	// printvec
	// cout <<"print vector" << endl;
	// for(auto it = vecpairs.begin() ; it!= vecpairs.end(); it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	// cout <<"print vector2" << endl;
	sort(all(vecpairs), sortbyfirst);
	// for(auto it = vecpairs.begin() ; it!= vecpairs.end(); it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	int total = vecpairs[0].second;
	int maximo = vecpairs[0].first;
	for(int e = 1 ;e < n ; e++){
		total += vecpairs[e].second;
		maximo  = max(vecpairs[e].first, maximo-vecpairs[e].second);	
	}
	total += maximo;
	cout <<"Case " << caso << ": "<< total << endl;

}
int main(){
	int n;
	int caso = 1;
	while(cin>>n){
		if(n==0)break;
		else{
			solve(n,caso++);
		}

	}
	return 0;
}