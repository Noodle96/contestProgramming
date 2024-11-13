// Extracted of GeekForGeeks
// A Better (than Naive) Solution to find all divisors
// Time Complexity: O(sqrt(n)) 
// Auxiliary Space : O(1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void printDivisors(LL n){
    vector<LL> outFirst;
    vector<LL> outEnd;
	for (LL i=1; i<=sqrt(n); i++){
		if (n%i == 0){
			if (n/i == i) outFirst.push_back(i);
            // cout <<" "<< i;
			else{
                outFirst.push_back(i);
                outEnd.insert(outEnd.begin(),n/i);
            }
            // cout << " "<< i << " " << n/i;
		}
	}
    for(int e = 0 ; e < outFirst.size(); e++)cout << outFirst[e] << " ";
    for(int e = 0 ;e < outEnd.size() ; e++) cout << outEnd[e] << " ";
    cout << endl;
    outFirst.clear();
    outEnd.clear();
}

int main(){
    LL x;
    cin>>x;
	printDivisors(x);
	return 0;
}

// this code is contributed by shivanisinghss2110
