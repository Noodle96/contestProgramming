/*
==========================================================
|  Archivo       : ISBN.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-07 14:51
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
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
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}



// Verifica si el string tiene guiones bien colocados
bool isValidHyphenPlacement(const string& s) {
    // invalid si tiene guiones al principio o al final
    if (s.front() == '-' || s.back() == '-') return false;

    // invalid si tiene guiones consecutivos
    for (size_t i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == '-' && s[i + 1] == '-') return false;
    }

    // contar guiones
    int hyphenCount = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '-') hyphenCount++;
    }

    if (hyphenCount == 3) {
        // el último guion debe estar antes del último dígito (checksum)
        // es decir, debe haber un guion justo antes del último carácter (sin contar guiones)
        int nonHyphenCount = 0;
        int lastHyphenBefore = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '-') {
                nonHyphenCount++;
            } else {
                lastHyphenBefore = i;
            }
        }
        // último dígito real está en la última posición no guion
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '-') count++;
            if (count == 9) {
                return (lastHyphenBefore == i || lastHyphenBefore == i + 1);
            }
        }
    }
    return true;
}

// Calcula si el ISBN-10 tiene checksum válido
bool isValidISBN10Checksum(const string& raw) {
    if (raw.size() != 10) return false;

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        char c = raw[i];
        int val;
        if (i == 9 && c == 'X') val = 10;
        else if (isdigit(c)) val = c - '0';
        else return false;
        sum += (10 - i) * val;
    }

    return sum % 11 == 0;
}

// Convierte ISBN-10 (sin guiones) a ISBN-13 (sin guiones)
string convertToISBN13Raw(const string& raw10) {
    string base = "978" + raw10.substr(0, 9);  // quitar checksum
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        int d = base[i] - '0';
        sum += (i % 2 == 0 ? d : 3 * d);
    }
    int check = (10 - (sum % 10)) % 10;
    return base + char('0' + check);
}

// Reconstruye los guiones para ISBN-13
string reinsertHyphens(const string& isbn13raw, const string& isbn10) {
    string result;
    vector<int> hyphenPos;
    for (int i = 0; i < isbn10.size(); ++i) {
        if (isbn10[i] == '-') {
            hyphenPos.push_back(i);
        }
    }

    // El ISBN-13 tiene 3 dígitos adicionales + 1 guion nuevo tras "978"
    result += "978";
    result += '-';

    int idx = 0;  // índice de los dígitos en isbn13raw (sin contar "978")
    for (int i = 0; i < isbn10.size(); ++i) {
        if (isbn10[i] == '-') continue;
        result += isbn13raw[3 + idx]; // empezamos desde después del "978"
        idx++;
        // insertamos guion si la próxima posición original lo tenía
        if (!hyphenPos.empty() && i + 1 == hyphenPos.front()) {
            result += '-';
            hyphenPos.erase(hyphenPos.begin());
        }
    }

    return result;
}


void solve(){
    string line;
    getline(cin, line);
    if (!isValidHyphenPlacement(line)) {
        cout << "invalid" << endl;
        return;
    }

    // quitar guiones
    string raw10;
    for (char c : line) {
        if (c != '-') raw10 += c;
    }

    if (!isValidISBN10Checksum(raw10)) {
        cout << "invalid" << endl;
        return;
    }

    string isbn13raw = convertToISBN13Raw(raw10);
    string isbn13final = reinsertHyphens(isbn13raw, line);
    cout << isbn13final << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    cin.ignore(); // Ignorar el salto de línea después del número de casos
    while(t--) solve();
    return 0;
}