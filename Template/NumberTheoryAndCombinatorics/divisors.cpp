// Extracted of GeekForGeeks
// A Better (than Naive) Solution to find all divisors
// Time Complexity: O(sqrt(n)) 
// Auxiliary Space : O(1)
#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;


/*
	Numero total de divisores con la 
	descomposicion canonica
*/
ll totalDivisores(ll num){
	ll total = 1;
	for(int i = 2; (ll)i*i <= num; i++){
		if(num % i == 0 ){
			int e = 0;
			while(num % i == 0){
				e++;
				num /= i;
			}
			total *= (e+1);
		}
	}
	if(num > 1){
		total*= 2;
	}
	return total;
}
/*
	Suma de divisores
*/
ll sumaDivisores(ll num){
	ll total = 1;
	for(int i = 2; (ll)i*i <= num; i++){
		if(num % i == 0){
			int e = 0 ;
			while(num % i == 0){
				e++;
				num /= i;
			}
			ll sum = 0; ll pow =1;
			for(int k = 0; k <=e; k++){
				sum += pow;
				pow *=i;
			}
			total *= sum;
		}
	}
	if(num > 1){
 		total *= (1+num);
	}
	return total;
}




// Function to print the divisors
void printDivisors(ll n)
{
	// Note that this loop runs till square root
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				cout <<" "<< i;

			else // Otherwise print both
				cout << " "<< i << " " << n/i;
		}
	}
}

/* Driver program to test above function */
int main()
{
	//cout <<"The divisors of 100 are: \n";
	ll e;
	while(1){
		cin>>e;
		printDivisors(e);
		// cout << totalDivisores(e) << endl;
		// cout << sumaDivisores(e) << endl;
	}
	return 0;
}

// this code is contributed by shivanisinghss2110
