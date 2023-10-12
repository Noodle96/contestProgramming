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
    vector<int> ans;
    int x,y,z,n;
    cin>>x>>y>>z>>n;
    int needed = x*y*3;
    if(needed % 5 == 0) needed /= 5;
    else needed = needed/5 +1; 

    int lograrMaximo = (x-z)*y;
    if(n+lograrMaximo >= needed){
        cout << "Yes" << endl;
        if(n >= needed){
            for(int e = 0 ; e < (x-z); e++){
                cout << 0 << " ";
            }cout << endl;
        }else{
            int meta = needed - n;
            while(meta >= y){
                ans.pb(y);
                meta -=y;
            }
            if(meta != 0) ans.pb(meta);
            sort(all(ans));
            if(ans.size()>=(x-z)){
                for(int e = 0; e < (x-z); e++){
                    cout << ans[e] << " ";
                }cout << endl;
            }else{
                int restante = (x-z)-ans.size();
                for(int e = 0 ; e < restante; e++){
                    cout << 0 << " ";
                }
                for(int e = 0 ;e < ans.size() ; e++){
                    cout << ans[e] << " ";
                }cout << endl;
            }
            
        }
    }else{
        cout << "No" << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    solve();
	return 0;
}