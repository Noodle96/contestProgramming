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

bool isDisjoint(vector<ll> &a, vector<ll> &b){
    for(auto a_i:a){
        auto it = find(all(b),a_i);
        if(it != b.end()){
            //found
            return false;
        }
    }
    return true;
}

void solve(){
    string A;
    while(getline(cin,A)){
        string B;
        getline(cin,B);
        // cout << "A: " << A << endl;
        // cout << "B: " << B << endl;
        stringstream ssA(A);
        stringstream ssB(B);
        vector<ll> a;
        vector<ll> b;
        ll x;
        while(ssA >> x){
            a.push_back(x);
        }
        sort(all(a));
        while(ssB >> x){
            b.push_back(x);
        }
        sort(all(b));
        if(a == b){
            cout << "A equals B" << endl;
        }else{
            if(isDisjoint(a,b)){
                cout << "A and B are disjoint" << endl;
            }else{
                if(a.size() <= b.size()){
                    bool flag = true;
                    for(auto a_i: a){
                        auto it = find(all(b),a_i);
                        if(it != b.end()){
                            //found
                           ;
                        }else{
                            cout << "I'm confused!" << endl;
                            flag = false;
                            break;
                        }
                    }
                    if(flag) cout << "A is a proper subset of B" << endl;
                }else{
                    bool flag = true;
                    for(auto b_i: b){
                        auto it = find(all(a),b_i);
                        if(it != a.end()){
                            //found
                            ;
                        }else{
                            cout << "I'm confused!" << endl;
                            flag = false;
                            break;
                        }
                    }
                    if(flag)cout << "B is a proper subset of A" << endl;
                }
            }
        }
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
    return 0;
}