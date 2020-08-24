#include <bits/stdc++.h>
using namespace std;

//O(nlogn) time and O(1) space
bool find_x_is_sum_of_any_two_array_ele(vector<int> arr, int x)
{
    sort(arr.begin(), arr.end());
    for(const int &i: arr)
    {
        int search_this = x - i;
        bool res = std::binary_search(arr.begin(), arr.end(), search_this);
        if (res)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -15};
    cout << find_x_is_sum_of_any_two_array_ele(arr, 7) << endl;
    cout << find_x_is_sum_of_any_two_array_ele(arr, 8) << endl;
    cout << find_x_is_sum_of_any_two_array_ele(arr, 9) << endl;
    cout << find_x_is_sum_of_any_two_array_ele(arr, -10) << endl;
    cout << find_x_is_sum_of_any_two_array_ele(arr, 70) << endl;
    return 0;
}
