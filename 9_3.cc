//Assumption: Only Horizontal Roads would be blocked under repair work
//Same as 9_2, just diagonals are also allowed
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;

map<Point, Point> invalid_roads;

// bottom up approach using dynamic programming
int uniqueRoutesFrom0_0_ToX_Y_DP(const int x, const int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (x == 0 || y == 0)
        return 1;
    //create a 2d array of size x*y for performing memoization
    vector<vector<int>> arr(x + 1, vector<int>(y + 1, 0));
    for (int i = 0; i <= x; ++i)
        arr[i][0] = 1;

    for (int j = 1; j <= y; ++j)
        arr[0][j] = 1;

    for (int j = 1; j <= y; ++j)
    {
        for (int i = 1; i <= x; ++i)
        {
            Point current_point = make_pair(i, j);

            int total_ways_from_west = arr[i - 1][j];
            int total_ways_from_south = arr[i][j - 1];
            int total_ways_from_southwest = arr[i-1][j-1];

            Point from_west = make_pair(i - 1, j);

            //check map if current point was reachable by any of invalid roads
            auto west_road_iter = invalid_roads.find(from_west);
            if (west_road_iter != invalid_roads.end())
            {
                if (west_road_iter->second == current_point)
                {
                    //printf("we(%d,%d)", from_west.first, from_west.second);
                    total_ways_from_west = 0;
                }
            }

            Point from_south = make_pair(i, j - 1);

            auto south_road_iter = invalid_roads.find(from_south);
            if (south_road_iter != invalid_roads.end())
            {
                if (south_road_iter->second == current_point)
                {
                    //printf("(%d,%d)", from_south.first, from_south.second);
                    total_ways_from_south = 0;
                }
            }

            Point from_south_west = make_pair(i, j - 1);

            auto southwest_road_iter = invalid_roads.find(from_south_west);
            if (southwest_road_iter != invalid_roads.end())
            {
                if (southwest_road_iter->second == current_point)
                {
                    //printf("(%d,%d)", from_south.first, from_south.second);
                    total_ways_from_southwest = 0;
                }
            }

            arr[i][j] = total_ways_from_west + total_ways_from_south + total_ways_from_southwest;
            // -------*
            //        |
            //        |
            //add the total ways of road coming from west and road from south
        }
    }
    return arr[x][y];
}

int main(int argc, char const *argv[])
{
    /*invalid_roads = {
        {{1, 2}, {2, 2}},
        {{2, 1}, {3, 2}},
        {{3, 3}, {3, 4}},
        {{3, 6}, {3, 7}},
        {{8, 1}, {9, 1}},
    };*/
    invalid_roads = {
        {{0, 2}, {1, 2}},
        {{1, 1}, {2, 1}},
        {{1, 3}, {2, 3}},
        {{2, 4}, {3, 4}}};
    cout << "(1, 1) : " << uniqueRoutesFrom0_0_ToX_Y_DP(1, 1) << endl;
    cout << "(1, 2) : " << uniqueRoutesFrom0_0_ToX_Y_DP(1, 2) << endl;
    cout << "(1, 3) : " << uniqueRoutesFrom0_0_ToX_Y_DP(1, 3) << endl;
    cout << "(1, 4) : " << uniqueRoutesFrom0_0_ToX_Y_DP(1, 4) << endl;
    cout << "(1, 1) : " << uniqueRoutesFrom0_0_ToX_Y_DP(1, 1) << endl;
    cout << "(2, 1) : " << uniqueRoutesFrom0_0_ToX_Y_DP(2, 1) << endl;
    cout << "(2, 2) : " << uniqueRoutesFrom0_0_ToX_Y_DP(2, 2) << endl;
    cout << "(2, 3) : " << uniqueRoutesFrom0_0_ToX_Y_DP(2, 3) << endl;
    cout << "(2, 4) : " << uniqueRoutesFrom0_0_ToX_Y_DP(2, 4) << endl;
    cout << "(3, 1) : " << uniqueRoutesFrom0_0_ToX_Y_DP(3, 1) << endl;
    cout << "(3, 2) : " << uniqueRoutesFrom0_0_ToX_Y_DP(3, 2) << endl;
    cout << "(3, 3) : " << uniqueRoutesFrom0_0_ToX_Y_DP(3, 3) << endl;
    cout << "(3, 4) : " << uniqueRoutesFrom0_0_ToX_Y_DP(3, 4) << endl;

    for (int x = 0; x < 5; ++x)
    {
        int y = x;
        printf("{%d,%d} -> %5d\n",
               x,
               y,
               uniqueRoutesFrom0_0_ToX_Y_DP(x, y));
    }

    return 0;
}