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


void generateSequences(int N, int M, std::vector<int>& currentSequence, std::vector<std::vector<int>>& sequences) {
    if (currentSequence.size() == N) {
        sequences.push_back(currentSequence);
        return;
    }

    int start = (currentSequence.empty()) ? 1 : currentSequence.back() + 1;

    for (int num = start; num <= M; ++num) {
        currentSequence.push_back(num);
        generateSequences(N, M, currentSequence, sequences);
        currentSequence.pop_back();
    }
}

int main() {
    std::vector<int> currentSequence;
    std::vector<std::vector<int>> sequences;
	int N,M; cin>> N>>M;
    generateSequences(N, M, currentSequence, sequences);

    for (const std::vector<int>& seq : sequences) {
        for (int num : seq) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}