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
double x,y;
vector<pair<double,double>> v(3);
vector<double> distances;
void solve(){
    for(int e = 0 ; e < 3; e++){
        cin>>x>>y;
        v[e] = mp(x,y);
    }
    for(int e = 0 ; e < 3; e++){
        for(int j = e+1; j < 3; j++){
            // cout << sqrt(pow(v[e].first-v[j].first,2)+pow(v[e].second-v[j].second,2)) << endl;
            distances.pb(sqrt(pow(v[e].first-v[j].first,2)+pow(v[e].second-v[j].second,2)));
        }
    }
    sort(all(distances));
    // for(auto e: distances)
    //     cout << e << " ";
    // cout << endl;

    if( abs((distances[2]*distances[2]) - (distances[0]*distances[0] + distances[1]* distances[1]) ) < 1e-9){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
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