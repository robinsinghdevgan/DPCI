// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n-simple-implementation/
// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

/* Dynamic Programming C++ implementation 
of LIS problem */
#include <bits/stdc++.h>
using namespace std;

/* lis() returns the length of the longest 
increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in 
	bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

// Using Set
// Return length of LIS in arr[] of size N
int lis2(int arr[], int N)
{
    int i;
    set<int> s;
    set<int>::iterator k;
    for (i = 0; i < N; i++)
    {
        // Check if the element was actually inserted
        // An element in set is not inserted if it is
        // already present. Please see
        // https://www.geeksforgeeks.org/set-insert-function-in-c-stl/
        if (s.insert(arr[i]).second)
        {
            // Find the position of inserted element in iterator k
            k = s.find(arr[i]);

            k++; // Find the next greater element in set

            // If the new element is not inserted at the end, then
            // remove the greater element next to it (This is tricky)
            if (k != s.end())
                s.erase(k);
        }
    }

    // Note that set s may not contain actual LIS, but its size gives
    // us the length of LIS
    return s.size();
}

/* Driver program to test above function */
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));

    printf("Length of lis using lis2(arr,n) is %d\n", lis2(arr, n));

    return 0;
}
