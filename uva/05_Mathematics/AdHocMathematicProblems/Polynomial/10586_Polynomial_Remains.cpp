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
using grado = int;
using coeficiente = int;

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

struct CompareByFirst {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

bool isAllZero(set<pair<grado,coeficiente>, CompareByFirst> &s){
    bool ans = true;
    for(auto e: s){
        if(e.second != 0){
            ans = false;
            break;
        }
    }
    return ans;
}


int n,k;
void solve(){
    while(cin>>n>>k){
        if(n == -1 && k == -1){
            break;
        }else{
            set<pair<grado, coeficiente>, CompareByFirst> set_grado_coeficiente;
            vector<pair<grado, coeficiente>> divisor;
            divisor.pb({0,1});
            divisor.pb({k,1});
            for(int e = 0 ; e < n+1;  e++){
                coeficiente temp;
                cin>>temp;
                set_grado_coeficiente.insert(mp(e,temp));
            }
            if(k == 0){
                cout << 0 << endl;
                continue;
            }
            // cout << "print set" <<endl;
            // for(auto e: set_grado_coeficiente){
            //     cout << e.first << " " << e.second << endl;
            // }
            // auto fin = set_grado_coeficiente.rbegin();
            // cout << fin->first << " " << fin->second<< endl;

            // logica
            while(1){
                auto fin = set_grado_coeficiente.rbegin();
                // cout << "fin: " << fin->first << " " << fin->second << endl;
                if(fin->first < divisor[1].first){
                    break;
                }else{
                    grado grado_actual = fin->first - divisor[1].first;
                    // cout << "grado actual: " << grado_actual << endl;
                    coeficiente coeficiente_actual = fin->second / divisor[1].second;
                    // cout << "coe actual: " << coeficiente_actual << endl;
                    set_grado_coeficiente.erase(*fin);
                    // cout << "print set" <<endl;
                    // for(auto e: set_grado_coeficiente){
                    //     cout << e.first << " " << e.second << endl;
                    // }

                    auto it = set_grado_coeficiente.find({grado_actual, 0});
                    if(it != set_grado_coeficiente.end()){
                        //found
                        // coeficiente_actual -= it->second;
                        auto temp = it->second;
                        set_grado_coeficiente.erase(*it);
                        set_grado_coeficiente.insert({grado_actual, temp-coeficiente_actual});
                    }
                    else{
                        //not found
                        set_grado_coeficiente.insert({grado_actual,-coeficiente_actual});
                    }
                    // for(auto e: divisor){
                    //     set_grado_coeficiente.insert(mp(grado_actual + e.first, coeficiente_actual * e.second));
                    // }
                }
            }
            if(isAllZero(set_grado_coeficiente)){
                cout << 0 << endl;
            }else{
                int e = 0;
                auto it = set_grado_coeficiente.begin();
                for(; e < set_grado_coeficiente.size()-1; e++, it++){
                    // cout << e.first << " " << e.second << endl;
                    // if(it->second != 0){
                        cout << it->second << " ";
                    // }
                }
                // if(it->second != 0){
                    cout << it->second << endl;
                // }
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