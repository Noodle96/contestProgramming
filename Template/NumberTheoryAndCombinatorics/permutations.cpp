// next_permutation example
// Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

int main () {
    int array[] = {3,2,1};
    vector<int> myints(array, array +3);

    //first ordered
    sort(myints.begin(), myints.end());
    //std::sort (myints,myints+3);

    std::cout << "The 3! possible permutations with 3 elements:\n";
    do {
        std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
    } while ( std::next_permutation(myints.begin(),myints.end()) );

    std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

    return 0;
}