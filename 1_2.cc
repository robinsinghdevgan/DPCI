#include <iostream> 
#include <vector> 
#include <cassert> 
using namespace std; 
void fill_array_nth_sum_helper(vector<int> &arr, int index) 
{ 
    if (index <= 0) //value at index 0 need not to be changed. Values less than 0 is out of bounds of the array 
        return; 
    if (index > 1) //keep calling the function till we reach index == 1 
    { 
        fill_array_nth_sum_helper(arr, index - 1); 
    } 
    arr[index] += arr[index - 1]; //fill the array, with value at each index as sum of itself and the value at previous index 
} 
void fill_array_nth_sum(vector<int> &arr) 
{ 
    int index = arr.size() - 1; 
    fill_array_nth_sum_helper(arr, index); 
} 
int main(int argc, char const *argv[]) 
{ 
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; 
    vector<int> expected_arr = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136}; 
    fill_array_nth_sum(arr); 
    for (const int &i : arr) 
        cout << i << " "; 
    assert(arr == expected_arr); 
    return 0; 
} 