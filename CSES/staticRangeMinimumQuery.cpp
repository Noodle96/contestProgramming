#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL lookup[1000000][21];

void buildSparseTable(vector<LL> &arr, int n){
	for (int i = 0; i < n; i++) 
		lookup[i][0] = arr[i];

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
			if (lookup[i][j - 1] < lookup[i + (1 << (j - 1))][j - 1])
				lookup[i][j] = lookup[i][j - 1];
			else
				lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
		}
	}
}

int query(int L, int R){
	int j = (int)log2(R - L + 1);
	if (lookup[L][j] < lookup[R - (1 << j) + 1][j])
		return lookup[L][j];

	else
		return lookup[R - (1 << j) + 1][j];
}
int main(){
    // LL a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	// int n = sizeof(a) / sizeof(a[0]);

	// buildSparseTable(a, n);

	// cout << query(0, 4) << endl;
	// cout << query(4, 7) << endl;
	// cout << query(7, 8) << endl;

    vector<LL> vec;
    LL n,q,temp;
    LL a,b;
    cin>>n>>q;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }
    buildSparseTable(vec,vec.size());
    while(q--){
        cin>>a>>b;
        cout << query(a-1,b-1) << endl;
    }
    
    return 0;
}