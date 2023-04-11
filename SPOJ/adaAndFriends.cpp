#include <bits/stdc++.h>
using namespace std;
struct comp {
    template <typename T>
 
    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};
int main(){
    // map<char, long long> friends;
    // string cadena = "ddddcccbba";
    // for(int e = 0 ; e < cadena.size(); e++){
    //     ++friends[cadena[e]];
    // }
    // for(auto it = friends.begin(); it != friends.end() ; it++){
    //     cout << it->first << " - " << it->second << endl;
    // }
    int Q,K; cin>>Q>>K;
    string s;
    long long E;
    map<string, long long> friends;
    while(Q--){
        cin>>s>>E;
        friends[s] += E;
    }
    // for(auto it = friends.begin(); it != friends.end() ; it++){
    //     cout << it->first << " - " << it->second << endl;
    // }
    set<pair<string, long long>, comp> S(friends.begin(), friends.end());
    // for(auto it = S.begin(); it != S.end() ; it++){
    //     cout << it->first << " - " << it->second << endl;
    // }
    long long maximunMoney = 0;
    for(auto crit = S.crbegin() ; crit != S.crend() && K--; crit++ ){
        // cout << crit->first << " : " << crit->second << endl;
        maximunMoney += crit->second;
    }
    cout << maximunMoney << endl;
    return 0;
}