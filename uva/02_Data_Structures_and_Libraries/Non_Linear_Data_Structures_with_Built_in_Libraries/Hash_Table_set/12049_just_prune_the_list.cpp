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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n,m; cin>>n>>m;
    multiset<int> list1,list2;
    for(int e = 0 ;e < n ; e++){
        int a; cin>>a;
        list1.insert(a);
    }
    for(int e = 0 ;e < m ; e++){
        int a; cin>>a;
        list2.insert(a);
    }

    vector<int> deleted;
    for(auto it = list1.begin();it != list1.end() ; it++){
        auto f = list2.find(*it);
        if(f != list2.end()){
            deleted.pb(*f);
            list2.erase(f);
        }
    }
    // cout << "deleted: " << endl;
    // for(auto item: deleted){
    //     cout << item <<" ";
    // }cout << endl;

    for(auto item : deleted)list1.erase(list1.find(item));

    // cout << "print" << endl;
    // for(auto it = list1.begin();it != list1.end() ; it++){
    //     cout << *it << " ";
    // }cout << endl;

    // for(auto it = list2.begin();it != list2.end() ; it++){
    //     cout << *it << " ";
    // }cout << endl;
    cout << list1.size() + list2.size() << endl;

}

void solve2(){
    multiset<int> m = {1,2,3,1};
    m.erase(m.find(1));
    for(auto item: m){
        cout << item << " ";
    } cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t; while(t--)solve();
    // solve2();
    return 0;
}