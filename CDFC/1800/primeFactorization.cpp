#include <bits/stdc++.h>
using namespace std;
void primeFactors(int n){
	vector<int> vec;
	while (n % 2 == 0){
		// cout << 2 << " ";
		vec.push_back(2);
		n = n/2;
	}
	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			// cout << i << " ";
			vec.push_back(i);
			n = n/i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2) vec.push_back(n);
		// cout << n << " ";

	//print vector
	for(auto e = 0 ; e < vec.size()-1; e++) cout << vec[e] << "*";
	cout << vec[vec.size()-1] << endl;
}

/* Driver code */
int main()
{
	int n; cin>>n;
	primeFactors(n);
	return 0;
}

// This is code is contributed by rathbhupendra
