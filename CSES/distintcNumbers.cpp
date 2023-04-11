#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void prinVector(vector<LL> &V){
    for (auto& elem : V)
        cout << elem << " ";
    cout << endl;
}
int main(){
    int n; cin>>n;
    vector<LL> vectorNumbers;
    LL temp;
    while(n--){
        cin>>temp;
        vectorNumbers.push_back(temp);
    }
    // sort(vectorNumbers.begin(), vectorNumbers.end(), greater<LL>());
    sort(vectorNumbers.begin(), vectorNumbers.end());
    // prinVector(vectorNumbers);
    auto previous = vectorNumbers.begin();
    auto current = ++vectorNumbers.begin();
    auto repeat = 1;
    for(; current != vectorNumbers.end(); current++){
        if(*previous != *current){
            repeat++;
        }
        previous = current;
    }
    cout << repeat << endl;
    return 0;
}