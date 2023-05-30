#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using V = vector<LL>;
void preCompute(V &arr, int n, V &pre)
{
	pre[0] = arr[0];
	for (int i = 1; i < n; i++){
        pre[i] = arr[i] + pre[i - 1];   
    }
}
LL query(LL i, LL j, V &pre)
{
	if (i == 0)
		return pre[j];
	return pre[j] - pre[i - 1];
}

void printVector(vector<LL> &v){
    //print only for test
    for(int e = 0 ;e < 10 ; e++){
        cout << v[e] << " ";
    }
    cout << endl;
}
int main()
{
    vector<LL> vec;
    LL n,q,temp;
    LL a,b;
    cin>>n>>q;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }
    vector<LL> pre(2e5,0);
    preCompute(vec, vec.size(), pre);
    while(q--){
        cin>>a>>b;
        cout << query(a-1,b-1,pre) << endl;
    }
	return 0;
}
