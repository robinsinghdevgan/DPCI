// https://www.geeksforgeeks.org/printing-longest-bitonic-subsequence/
/* Dynamic Programming solution to print Longest 
Bitonic Subsequence */
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to print Longest Bitonic 
// Subsequence 
void print(vector<int>& arr, int size) 
{ 
	for(int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

// Function to construct and print Longest 
// Bitonic Subsequence 
void printLBS(int arr[], int n) 
{ 
	// LIS[i] stores the length of the longest 
	// increasing subsequence ending with arr[i] 
	vector<vector<int>> LIS(n); 

	// initialize LIS[0] to arr[0] 
	LIS[0].push_back(arr[0]); 

	// Compute LIS values from left to right 
	for (int i = 1; i < n; i++) 
	{ 
		// for every j less than i 
		for (int j = 0; j < i; j++) 
		{ 
			if ((arr[j] < arr[i]) && 
				(LIS[j].size() > LIS[i].size())) 
				LIS[i] = LIS[j]; 
		} 
		LIS[i].push_back(arr[i]); 
	} 

	/* LIS[i] now stores Maximum Increasing 
	Subsequence of arr[0..i] that ends with 
	arr[i] */

	// LDS[i] stores the length of the longest 
	// decreasing subsequence starting with arr[i] 
	vector<vector<int>> LDS(n); 

	// initialize LDS[n-1] to arr[n-1] 
	LDS[n - 1].push_back(arr[n - 1]); 

	// Compute LDS values from right to left 
	for (int i = n - 2; i >= 0; i--) 
	{ 
		// for every j greater than i 
		for (int j = n - 1; j > i; j--) 
		{ 
			if ((arr[j] < arr[i]) && 
				(LDS[j].size() > LDS[i].size())) 
				LDS[i] = LDS[j]; 
		} 
		LDS[i].push_back(arr[i]); 
	} 

	// reverse as vector as we're inserting at end 
	for (int i = 0; i < n; i++) 
		reverse(LDS[i].begin(), LDS[i].end()); 

	/* LDS[i] now stores Maximum Decreasing Subsequence 
	of arr[i..n] that starts with arr[i] */

	int max = 0; 
	int maxIndex = -1; 

	for (int i = 0; i < n; i++) 
	{ 
		// Find maximum value of size of LIS[i] + size 
		// of LDS[i] - 1 
		if (LIS[i].size() + LDS[i].size() - 1 > max) 
		{ 
			max = LIS[i].size() + LDS[i].size() - 1; 
			maxIndex = i; 
		} 
	} 

	// print all but last element of LIS[maxIndex] vector 
	print(LIS[maxIndex], LIS[maxIndex].size() - 1); 

	// print all elements of LDS[maxIndex] vector 
	print(LDS[maxIndex], LDS[maxIndex].size()); 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	printLBS(arr, n); 
	return 0; 
} 
