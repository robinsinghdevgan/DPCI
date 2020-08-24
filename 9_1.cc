#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> count_overlapping_subproblems;
void print_map()
{
    for (auto p : count_overlapping_subproblems)
    {
        cout << p.first << " : " << p.second << endl;
    }
}

int func_call1 = 0, func_call2 = 0, func_call3 = 0;

//Return total number of unique routes from (0,0) to (x,y)
//x and y are positive integers
//Routes are roads, vertically and horizontanlly, 1km apart from each adjacent or opposite

//top down approach using recursion
int uniqueRoutesFrom0_0_ToX_Y(const int x, const int y)
{
    ++func_call1;
    if (x < 0 || y < 0)
        return 0; //going to negative direction is not allowed
    if (x == 0 || y == 0)
        return 1; //found the origin through this path
    //++count_overlapping_subproblems[to_string(x) + "," + to_string(y)];
    //return uniqueRoutesFrom0_0_ToX_Y(x - 1, y) + uniqueRoutesFrom0_0_ToX_Y(x, y - 1);
    return uniqueRoutesFrom0_0_ToX_Y(x-1, y) + uniqueRoutesFrom0_0_ToX_Y(x, y-1);
}

//top down -> bottom up approach using recursion and memoization
int memoization_helper(vector<vector<int>> &arr, const int x, const int y)
{
    ++func_call2;
    if (x < 0 || y < 0)
        return 0; //going to negative direction is not allowed
    if (arr[x][y] != 0)
        return arr[x][y];
    ++count_overlapping_subproblems[to_string(x) + "," + to_string(y)];
    arr[x][y] = memoization_helper(arr, x - 1, y) + memoization_helper(arr, x, y - 1);
    return arr[x][y];
}
int uniqueRoutesFrom0_0_ToX_Y_Memo(const int x, const int y)
{
    ++func_call2;
    //create a 2d array of size x*y for performing memoization
    vector<vector<int>> arr(x + 1, vector<int>(y + 1, 0));
    arr[0][0] = 1;
    return memoization_helper(arr, x, y);
}

// bottom up approach using dynamic programming
int uniqueRoutesFrom0_0_ToX_Y_DP(const int x, const int y)
{
    ++func_call3;
    if(x < 0 || y < 0)
        return 0;
    if(x==0 || y==0)
        return 1;
    //create a 2d array of size x*y for performing memoization
    vector<vector<int>> arr(x + 1, vector<int>(y + 1, 0));
    for(int i=0; i<=x; ++i) 
        arr[i][0] = 1;
    
    for(int j = 1; j <= y; ++j)
        arr[0][j] = 1;

    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    return arr[x][y];
}

int main(int argc, char const *argv[])
{
    
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            printf("(%d,%d) -> %5d || %5d || %5d\n",
                   x,
                   y,
                   uniqueRoutesFrom0_0_ToX_Y(x, y),
                   uniqueRoutesFrom0_0_ToX_Y_Memo(x, y),
                   uniqueRoutesFrom0_0_ToX_Y_DP(x, y));
        }
    }
    //test just the diagonal
    /*for (int x = 0; x < 10; ++x)
    {
        int y = x;
        printf("(%d,%d) -> %5d || %5d || %5d\n",
                   x,
                   y,
                   uniqueRoutesFrom0_0_ToX_Y(x, y),
                   uniqueRoutesFrom0_0_ToX_Y_Memo(x, y),
                   uniqueRoutesFrom0_0_ToX_Y_DP(x, y));
    }*/
    printf("f1: %d , f2: %d, f3: %d", func_call1, func_call2, func_call3);
    //print_map();
    return 0;
}
