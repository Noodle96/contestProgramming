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
void toLowerCase(string &s){
    for(auto &c:s){
        c = tolower(c);
    }
}
void onlyAlpha(string s, set<string> &d){
    string res = "";
    for(auto &c:s){
        if(isalpha(c)){
            res += c;
        }else{
            if(res.size()>0){
                d.insert(res);
                res = "";
            }
        }
    }
    if(res.size()>0){
        d.insert(res);
    }
}
void solve(){
    string line;
    set<string> dict;
    while(getline(cin,line)){
        // cout << "The line is: " << line << endl;
        toLowerCase(line);
        stringstream ss;
        ss << line;
        string word;
        while(ss>>word){
            // cout << "The word is: " << word << endl;
            onlyAlpha(word,dict);
            // cout << "word: " << word << endl;
            // if(word.size()>0){
            //     dict.insert(word);
            // }
        }
    }
    for(auto c: dict) cout << c << endl;
}
void solve2(){
    string a = "Left.\"abc";
    for(auto &c:a){
        // if(isalpha(c)){
        //     c = tolower(c);
        // }else{
        //     c = ' ';
        // }
        c = tolower(c);
    }
    cout << a << endl;
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