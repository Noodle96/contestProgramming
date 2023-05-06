#include <bits/stdc++.h>
using namespace std;

int calculateBills(int n, vector<int> &vectorBills){
    vector<int> vector_dp(vectorBills.size());
    vector_dp[0] = n;
    for(int e = 0 ; e < vectorBills.size(); e++){
        vector_dp[e+1] = vector_dp[e] % vectorBills[e];
    }
    int count = 0;
    for(int e = 0 ;e < vector_dp.size() ; e++){
        count += (vector_dp[e] / vectorBills[e]);
        // cout << "cout: " << count << endl;
    }
    return count;
}


int main(){
    int bill[] = {100,20,10,5,1};
    vector<int> bills(bill, bill + sizeof(bill)/sizeof(int));

    int n; cin>>n;
    cout << calculateBills(n, bills) << endl;
    return 0;
}