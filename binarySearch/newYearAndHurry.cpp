// C++ program to implement iterative Binary Search
#include <bits/stdc++.h>
using namespace std;

#define RESTTIME 240

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present

    
	return -1;
}

int binarySearchRecursivoModificado(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchRecursivoModificado(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearchRecursivoModificado(arr, mid + 1, r, x);
    }
    // We reach here when element is not
    // present in array
    return r ;
}




int main(void)
{
    unsigned short n,k;
    cin>>n>>k;
    int timeCOmplexity[n];
    timeCOmplexity[0] = 5;
    for (size_t i = 1; i < n; i++)
    {
        timeCOmplexity[i] = 5*(i+1) + timeCOmplexity[i-1];
    }
    /*for (size_t i = 0; i < n; i++)
    {
        cout << timeCOmplexity[i] << " ";
    }cout << endl; */

    int result = binarySearchRecursivoModificado(timeCOmplexity,0,n-1,RESTTIME-k);
    cout << result + 1<< endl;
    
	return 0;
}
