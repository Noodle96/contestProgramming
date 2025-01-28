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
void onlyAlpha(string s, vector<string> &d){
    string res = "";
    for(auto &c:s){
        if(isalpha(c) || c == '-'){
            res += c;
        }else{
            if(res.size()>0){
                d.pb(res);
                res = "";
            }
        }
    }
    if(res.size()>0){
        d.pb(res);
    }
}
string temp = "";
void solve(){
    string line;
    set<string> dict;
    bool lastWord = false;
    while(getline(cin,line)){
        // cout << "The line is: " << line << endl;
        toLowerCase(line);
        stringstream ss;
        ss << line;
        string word;
        vector<string> words;
        while(ss>>word){
            // cout << "The word is: " << word << endl;
            // cout << word.size() << endl;
            // words.pb(word);
            onlyAlpha(word,words);
            // cout << "word: " << word << endl;
            // if(word.size()>0){
            //     dict.insert(word);
            // }
        }
        // cout << "\t\twords: " << words.size() << endl;
        // for(auto c: words) cout << c << endl;   

        if(lastWord){
            if(words.size() >  0){
                auto c = words[0];
                c = temp + c;
                // cout << "c: " << c << endl;
                words[0] = c;
                temp = "";
                lastWord = false;
            }
        }


        if(words.size() > 0){
            size_t len = words.size();
            size_t len_last = words[len-1].size();
            if( words[len-1][len_last-1] == '-'){
                temp += words[len-1];
                // cout << "temp: " << temp << endl;
                temp.pop_back();
                // words[len-1] = temp;
                words.pop_back();
                lastWord = true;
            }else{
                ;
            }
        }
        
        for(auto c: words){
            if(c.size()>0){
                // cout << "palabra insertada: " << c << endl;
                dict.insert(c);
            }
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

// Adv-
// ent-
// ures
// in
// Dis-
// ney-
// land

// Two blondes were go-
// ing to Disney-land
// when they came to a
// fork in the road.
// The sign read: "Dis-
// neyland Left."

// So they went home.