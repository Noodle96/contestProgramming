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

int suma(int curr, int r, int n){
    if( (curr+r)%n == 0) return n;
    return (curr+r)%n;
}
int resta(int curr, int c, int n){
    if((curr-c)%n==0) return n;
    // cout << "curr-c: " << curr-c << endl;
    if(curr-c < 0) curr+=n;
    return (curr-c)%n;
}

int n,r,c;
set<int> s,ans;
bool first = true;
void solve(){
    cin>>n>>r>>c;
    for(int e = 1 ; e <= n ; e++) s.insert(e);
    // for(auto e : s){
    //     cout << e << " ";
    // }cout << endl;
    int curr1 = 1, curr2 = n; // Current positions of supervisors s1 and s2
    while(s.size() > 2){
        // int steps1 = (r * gcd(r, n)) % n; // Calculate actual steps for s1 (avoid overflow)
        // cout << "steps1: " << steps1 << endl;
        // int steps2 = (c * gcd(c, n)) % n; // Calculate actual steps for s2 (avoid overflow)
        // cout << "steps2: " << steps2 << endl;
        if(first){
            // curr1 = (curr1 + steps1 - 1) % n; // Move s1 clockwise
            curr1 = suma(curr1,r,n);
            curr1--;
            cout << "curr1: " << curr1 << endl;
            // curr2 = (curr2 - steps2 + n +1 ) % n; // Move s2 counter-clockwise (adjust for modulo)
            curr2 = resta(curr2,c,n);
            curr2++;
            cout << "curr2: " << curr2 << endl;
            if (curr1 == curr2) {
                cout << "curr1 == curr2" << endl;
                // Both supervisors reach the same candidate: hire and remove
                auto find_curr = s.find(curr1);
                s.erase(*find_curr);
                ans.insert(*find_curr);
                n--; // Decrement remaining candidates
            } else {
                // Supervisors reach different candidates: remove both
                // s.erase(max(curr1, curr2));
                // s.erase(min(curr1, curr2));
                auto find_curr1 = s.find(curr1);
                auto find_curr2 = s.find(curr2);
                s.erase(*find_curr1);
                s.erase(*find_curr2);
                n -= 2; // Decrement remaining candidates by 2
            }
            first = false;
        }else{
            cout << "status" << endl;
            for(auto e:s){
                cout << e << " ";
            }cout << endl;
            cout << "else" <<endl;
            // int steps1 = (r * gcd(r, n)) % n; // Calculate actual steps for s1 (avoid overflow)
            // int steps2 = (c * gcd(c, n)) % n; // Calculate actual steps for s2 (avoid overflow)
            // curr1 = (curr1 + r) % n; // Move s1 clockwise
            // curr2 = (curr2 - c + n) % n; // Move s2 counter-clockwise (adjust for modulo)
            curr1 = suma(curr1,r,n);
            cout << "curr1: " << curr1 << endl;
            curr2 = resta(curr2,c,n);
            cout << "curr2: " << curr2 << endl;
            if (curr1 == curr2) {
                cout << "curr1 == curr2" << endl;
                // Both supervisors reach the same candidate: hire and remove
                // cout << *s.find(curr1) << " ";
                auto find_curr = s.find(curr1);
                s.erase(*find_curr);
                ans.insert(*find_curr);
                n--; // Decrement remaining candidates
            } else {
                // Supervisors reach different candidates: remove both
                // s.erase(max(curr1, curr2));
                // s.erase(min(curr1, curr2));
                auto find_curr1 = s.find(curr1);
                auto find_curr2 = s.find(curr2);
                s.erase(*find_curr1);
                s.erase(*find_curr2);
                n -= 2; // Decrement remaining candidates by 2
            }
        }
    }
    cout << "print ans" << endl;
    for(auto e : ans){
        cout << e << " ";
    }cout << endl;
}
void test(){
    int n = 5;
    int r = 2;
    int c = 3;
    for(int e = 1 ; e <= 2*n; e++){
        cout << resta(e,c,n) << " ";
    }
    cout << endl;
}
//  1 2 3 4 5
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    // test();
    // cout << -2%5 << endl;
    return 0;
}