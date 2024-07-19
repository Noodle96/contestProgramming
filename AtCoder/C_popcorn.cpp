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

int n,m;
string str,temp;
vector< bitset<10> > vecBitset;

bool isPowerOfTwo(int x){
	return !(x & (x-1));
}

int makeUnion(vector<int> &idx){
    // cout << "idx: " << endl;
    // for(auto e: idx){
    //     cout << e << " ";
    // }cout << endl << endl;

    auto ans = 0;
    // cout << "initial ans: " << ans <<endl;
    for(auto e: idx){
        ans |= vecBitset[e].to_ulong();
        // cout << "partial ans: " << ans << endl;
    }
    return ans;
}

void solve(){
    cin>>n>>m;
    for(int e = 0 ; e < n; e++){
        cin>>str;
        temp = "";
        for(auto it = str.begin(); it != str.end(); it++){
            temp += (*it=='o'?'1':'0');
        }
        // cout << "temp: " << temp << endl;
        vecBitset.pb(bitset<10>(temp));
    }
    // cout << "print vecBitset" << endl;
    // for(auto e: vecBitset){
    //     cout << e << endl;
    // }
    auto minimoItems = INT_MAX;
    for(int i=0;i<(1<<n);i++){
        // cout<<"{ ";
        vector<int> idx;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                // cout<<j<<" ";
                idx.pb(j);
            }
        }
        if((int)idx.size() >  0){
            auto numPartial = makeUnion(idx);
            // cout << "numPartial: " << numPartial << endl;
            // for(auto e: idx){
            //         cout << e << " ";
            //     }
            // cout << endl;
            if(isPowerOfTwo(numPartial+1) && ( numPartial+1 & (1<<m) )==(1<<m) ){
                // cout << "\tnumPartial: " << numPartial+1 << endl;
                // cout << "\tnumPartial: " << numPartial << endl;
                minimoItems = min(minimoItems,(int)idx.size());
            }
        }
        // cout<<"}\n";
    }
    cout << minimoItems << endl;
}
void solve2(){
    cout << (31 & 31) << endl;
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