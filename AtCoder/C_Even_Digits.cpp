#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll findNthEvenDigitNumber(ll n){
	if (n == 1) return 0;
	vector< ll> v;
	n = n - 1;
	while (n > 0){
		v.push_back(n % 5);
		n = n / 5;
	}
	ll result = 0;
	for (int i = v.size() - 1; i >= 0; i--){
		result = result * 10;
		result = result + v[i];
	}
	return 2*result;
}

// Driver Code
void solve(){
	ll n; cin>>n;
	cout << findNthEvenDigitNumber(n) << endl;
}
int main()
{
	solve();
	return 0;
}
