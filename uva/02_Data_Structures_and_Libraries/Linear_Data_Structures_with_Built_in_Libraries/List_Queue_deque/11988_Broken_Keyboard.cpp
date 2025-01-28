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

std::string generarCadenaAleatoria(size_t tamano) {
    std::string resultado;
    resultado.reserve(tamano);

    const std::string caracteres = "abcdefghijklmnopqrstuvwxyz[]";
    size_t numCaracteres = caracteres.size();

    for (size_t i = 0; i < tamano; ++i) {
        resultado += caracteres[rand() % numCaracteres];
    }

    return resultado;
}

// deque<char> dq;
deque<char> ansDeque;
// void travel(string str, int index, int n){
//     if(index == n) return;
//     if(str[index] == '['){
//         index++;
//         // stack<char> st;
//         string temp;
//         while(index < n && (str[index] != '[' && str[index] != ']')){
//             // st.push(str[index++]);
//             temp += str[index++];
//         }
//         // while(!st.empty()){
//         //     dq.push_front(st.top());
//         //     st.pop();
//         // }
//         ans = temp + ans;
//         travel(str, index,n);
//     }else if(str[index] == ']'){
//         index++;
//         // queue<char> q;
//         string temp;
//         while(index < n && (str[index] != '[' && str[index] != ']')){
//             // q.push(str[index++]);
//             temp += str[index++];
//         }
//         // while(!q.empty()){
//         //     dq.push_back(q.front());
//         //     q.pop();
//         // }
//         ans += temp;
//         travel(str, index,n);
//     }else{
//         // str[index] is a alphabet
//         // dq.push_back(str[index]);
//         ans += str[index];
//         travel(str, index+1,n);
//     }
// }

void travelIterativo(const string& str) {
    ansDeque.clear();
    size_t n = str.size();
    size_t index = 0;

    while (index < n) {
        if (str[index] == '[') {
            index++;
            // string temp;
            stack<char> st;
            while (index < n && (str[index] != '[' && str[index] != ']')) {
                // temp += str[index++];
                st.push(str[index++]);
            }
            while(!st.empty()){
                ansDeque.push_front(st.top());
                st.pop();
            }
            // for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            //     ansDeque.push_front(*it);
            // }
        } else if (str[index] == ']') {
            index++;
            queue<char> q;
            while (index < n && (str[index] != '[' && str[index] != ']')) {
                // ansDeque.push_back(str[index++]);
                q.push(str[index++]);
            }
            while(!q.empty()){
                ansDeque.push_back(q.front());
                q.pop();
            }
        } else {
            ansDeque.push_back(str[index++]);
        }
    }
}
void solve(){
    string line;
    while(getline(cin, line)){
        // dq.clear();
        ansDeque.clear();
        travelIterativo(line);
        for(auto e: ansDeque) cout << e;
        cout << endl;
    }
}
// void solve2(){
//     for(int e = 0 ; e < 10; e++){
//         string a = generarCadenaAleatoria(100000);
//         startTime = clock();
//         travel(a, 0, a.size());
//         cout << ans << endl;
//         cout << getCurrentTime() << endl;
//     }
// }
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