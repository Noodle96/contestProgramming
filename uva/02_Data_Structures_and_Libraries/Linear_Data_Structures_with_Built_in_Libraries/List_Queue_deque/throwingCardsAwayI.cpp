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
    int n;
    while(cin>>n){
        if(n!=0){
            deque<int> deque;
            for(int i=1;i<=n;i++) deque.push_back(i);
            vector<int> discarded;
            while(deque.size()>1){
                discarded.push_back(deque.front());
                deque.pop_front();
                deque.push_back(deque.front());
                deque.pop_front();
            }
            cout << "Discarded cards:";
            for(int i=0;i<discarded.size();i++){
                cout << " " << discarded[i];
                if(i<discarded.size()-1) cout << ",";
            }
            cout << endl;
            cout << "Remaining card: " << deque.front() << endl;
        }   
    }
}
void solve2(){
    for(int e = 0 ; e < -1; e++){
        cout << e << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    // solve2();
    return 0;
}