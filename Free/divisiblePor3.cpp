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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> vec(n);
    for(int e = 0 ; e < n; e++){
        vec[e] = s[e] - '0';
    }
   
    //  for(int e = 0 ; e <n; e++){
    //     cout << vec[e]<< " ";
    // }cout << endl;

    // prefix sum
    for(int e = 1 ; e <n; e++){
        vec[e] = vec[e-1]+ vec[e];
    }

    //  for(int e = 0 ; e <n; e++){
    //     cout << vec[e]<< " ";
    // }cout << endl;
    vector<int> modulo3(n);
    for(int e = 0 ;e < n ; e++){
        modulo3[e] = vec[e]%3;
    }
    vector<int> ceros(n),unos(n),dos(n);
    //ceros
    if(modulo3[0] == 0) ceros[0] = 1;
    else ceros[0] = 0;
    for(int e = 1 ; e < n; e++){
        if(modulo3[e] == 0){
            ceros[e] = ceros[e-1] +1;
        }else{
            ceros[e] = ceros[e-1] + 0;
        }
    }
    //unos
    if(modulo3[0] == 1) unos[0] = 1;
    else unos[0] = 0;
    for(int e = 1 ; e < n; e++){
        if(modulo3[e] == 1){
            unos[e] = unos[e-1] +1;
        }else{
            unos[e] = unos[e-1] + 0;
        }
    }
    //dos
    if(modulo3[0] == 2) dos[0] = 1;
    else dos[0] = 0;
    for(int e = 1 ; e < n; e++){
        if(modulo3[e] == 2){
            dos[e] = dos[e-1] +1;
        }else{
            dos[e] = dos[e-1] + 0;
        }
    }
    // cout << "prints:" << endl;
    // for(int e = 0 ; e < n; e++){
    //     cout << ceros[e] << " ";
    // }cout << endl;
    // for(int e = 0 ; e < n; e++){
    //     cout << unos[e] << " ";
    // }cout << endl;

    // for(int e = 0 ; e < n; e++){
    //     cout << dos[e] << " ";
    // }cout << endl;

    int cont = 0;
    for(int e = 1 ;e < n ; e++){
        if(vec[e]%3 ==  0){
            cont += ceros[e-1];
        }else if(vec[e]%3==1){
            cont += unos[e-1];
        }else{
            // vec[e]%3==2
            cont += dos[e-1];
        }
    }
    for(int e = 0;e < n ; e++){
        if(vec[e]%3==0) cont++;
    }
    cout <<   cont << endl;


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t; cin>>t;
    while(t--)solve();
	return 0;
}