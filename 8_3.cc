#include <bits/stdc++.h>
using namespace std;

//(10,3) == (3,10)
int waysToScore1(int n, const vector<int> &points)
{
    int arr[n + 1] = {0};
    arr[0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j<points.size(); ++j)
        {
            if (i - points[j] >= 0)
                arr[i] += arr[i - points[j]];
        }
    }
    return arr[n];
}

int waysToScore1_Recursive(int n, const vector<int> &points)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    int res = 0;
    for(int j = 0; j<points.size(); ++j)
    {
        res += waysToScore1_Recursive(n-points[j], points);
    }
    return res;
}

//(10,3) != (3,10)
int waysToScore2(int n, const vector<int> &points)
{
    int arr[n + 1] = {0};
    arr[0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        int local_max = 0;
        for(int j = 0; j<points.size(); ++j)
        {
            local_max = std::max(local_max, (i - points[j] >= 0) ? arr[i - points[j]] : 0);
        }
        arr[i] += local_max;
    }
    return arr[n];
}

int waysToScore2_Recursive(int n, const vector<int> &points)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    int local_max = 0;
    for(int j = 0; j<points.size(); ++j)
    {
        local_max = std::max(local_max, waysToScore2_Recursive(n-points[j], points));
    }
    return local_max;
}

int main(int argc, char const *argv[])
{
    int n = 20;
    vector<int> points = {3,5,10};
    for (int i = 0; i <= n; ++i)
        printf("%3d -> %3d || %3d || %3d || %3d\n", i, waysToScore1(i, points), waysToScore1_Recursive(i, points), waysToScore2(i,points), waysToScore2_Recursive(i,points));
    
    n = 20;
    points = {2,4,5};
    for (int i = 0; i <= n; ++i)
        printf("%3d -> %3d || %3d || %3d || %3d\n", i, waysToScore1(i, points), waysToScore1_Recursive(i, points), waysToScore2(i,points), waysToScore2_Recursive(i,points));
    return 0;
}
