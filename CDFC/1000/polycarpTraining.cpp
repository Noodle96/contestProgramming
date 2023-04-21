#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> contest(n);
    for(int e = 0 ; e < n; e++) cin>> contest[e];
    sort(contest.begin(), contest.end());
    int cont = 0;
    for(int dia = 1, e= 0 ; e < n; e++,dia++){
        if(contest[e] < dia){
            dia--;
        }
        else cont++;
    }
    cout << cont << endl;
    return 0;
}