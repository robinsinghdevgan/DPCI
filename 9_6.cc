#include <bits/stdc++.h>
using namespace std;

//Given that chars in string 'a' are not there in string 'b'
// O(m+n) time and O(1) space
bool check_Interleave_Unique_Characters(string a, string b, string c)
{
    int sz_a = a.size(), sz_b = b.size(), sz_c = c.size();

    if (sz_a + sz_b != sz_c)
        return false;
    if (sz_a == 0)
        if (b == c)
            return true;
    if (sz_b == 0)
        if (a == c)
            return true;

    int idx_a = 0, idx_b = 0, idx_c = 0;

    for (char x : c)
    {
        if (idx_a < sz_a and idx_b < sz_b)
        {
            if (x == a[idx_a])
                ++idx_a;
            else if (x == b[idx_b])
                ++idx_b;
            else
                return false; // char in c mismatches pointed chars of a and b
        }
        else if (idx_a < sz_a)
        {
            if (x == a[idx_a])
                ++idx_a;
            else
                return false; // char in c mismatches pointed char of a
        }
        else
        {
            if (x == b[idx_b])
                ++idx_b;
            else
                return false; // char in c mismatches pointed char of b
        }
    }
    return (idx_a == sz_a and idx_b == sz_b) ? true : false;
}

int main(int argc, char const *argv[])
{
    //order of chars of a and b should be preserved in c
    string a = "ABCD", b = "WXYZ", c;
    c = "ABCDWXYZ";
    cout << check_Interleave_Unique_Characters(a, b, c) << endl;
    c = "AWBXCYDZ";
    cout << check_Interleave_Unique_Characters(a, b, c) << endl;
    c = "";
    cout << check_Interleave_Unique_Characters(a, b, c) << endl;
    c = "AWZ";
    cout << check_Interleave_Unique_Characters(a, b, c) << endl;
    c = "AWBXDYCZ"; //order not preserved
    cout << check_Interleave_Unique_Characters(a, b, c) << endl;
    return 0;
}
