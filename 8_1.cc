#include <bits/stdc++.h>
using namespace std;

void print_vector_of_vector(const vector<vector<int>> &arr)
{
    for (auto v : arr)
    {
        for (int i : v)
            cout << setw(3) << i << " ";
        cout << endl;
    }
}

//Find minimum Cost to travel from (0,0) to (m-1, n-1)
//diagonal values are allowed
//Bottom Up DP approach
int minCostIJ(int m, int n, const vector<vector<int>> &costs)
{
    // m is rows, n is columns
    vector<vector<int>> minCostDP(m, vector<int>(n, 0));
    
    minCostDP[0][0] = costs[0][0]; //fill the first cell

    //fill the first row with cumulative costs
    for(int j=1; j<n; j++)
        minCostDP[0][j] = costs[0][j] + minCostDP[0][j-1];
    
    //fill the first column with cumulative costs
    for(int i=1; i<m; i++)
        minCostDP[i][0] = costs[i][0] + minCostDP[i-1][0];
    
    //fill the rest of the minCost matrix
    for(int i=1; i<m; ++i)
    {
        for(int j=1; j<n; ++j)
        {
            int north = minCostDP[i-1][j];
            int north_west = minCostDP[i-1][j-1];
            int west = minCostDP[i][j-1];
            minCostDP[i][j] = costs[i][j] + std::min(north_west, std::min(west, north));
            cout << minCostDP[i][j] << "->";
        }
    }
    cout << "[]\n";
    print_vector_of_vector(minCostDP);
    return minCostDP[m-1][n-1]; //here we have the minimum cost to reach at (m-1, n-1)
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setw(2) << "\n";

    vector<vector<int>>
        cost_arr = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        };
    
    cout << minCostIJ(cost_arr.size(), cost_arr[0].size(), cost_arr) << "\n\n";

    vector<vector<int>>
        cost_arr2 = {
            {1,2,3,4},
            {5,1,7,8},
            {9,10,1,12},
            {13,14,15,1}
        };

    cout << minCostIJ(cost_arr2.size(), cost_arr2[0].size(), cost_arr2) << "\n";

    return 0;
}
