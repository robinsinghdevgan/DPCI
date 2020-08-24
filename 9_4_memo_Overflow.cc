#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<pair<int, int>, int> dp;
    //all knight directions
    const vector<pair<int, int>> knight_directions = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    const vector<pair<int, int>> quadrant_1_directions = {{1, 2}, {2, 1}, {1, 0}, {0, 1}, {1, 1}};
    const vector<pair<int, int>> quadrant_2_directions = {{-2, 1}, {-1, 2}, {-1, 0}, {0, 1}, {-1, 1}};
    const vector<pair<int, int>> quadrant_3_directions = {{-1, -2}, {-2, -1}, {-1, 0}, {0, -1}, {-1, -1}};
    const vector<pair<int, int>> quadrant_4_directions = {{2, -1}, {1, -2}, {1, 0}, {0, -1}, {1, -1}};
    int solve(int x, int y)
    {
        if (x + y == 0)
            return 0;
        if (x + y == 2)
            return 2;
        pair<int, int> temp({x, y});
        if (dp.count(temp))
            return dp[temp];
        return dp[temp] = min(solve(abs(x - 1), abs(y - 2)), solve(abs(x - 2), abs(y - 1))) + 1;
    }

    int minKnightMoves(int x, int y, const int &tx, const int &ty)
    {
        if (x == tx && y == ty)
            return 0; // found the way

        pair<int, int> temp({x, y});
        if (dp.count(temp))
            return dp[temp];

            
        bool positive_dir_x = (tx - x) >= 0 ? true : false;
        bool positive_dir_y = (ty - y) >= 0 ? true : false;
        

        vector<int> possible_answers;

        pair<bool, bool> quadrant_selection = {positive_dir_x, positive_dir_y};

        if (quadrant_selection == make_pair(true, true))
        {
            //q1
            for (const auto &dir : quadrant_1_directions)
            {
                possible_answers.emplace_back(minKnightMoves(dir.first + x, dir.second + y, tx, ty));
            }
        }
        else if (quadrant_selection == make_pair(false, true))
        {
            //q2
            for (const auto &dir : quadrant_2_directions)
            {
                possible_answers.emplace_back(minKnightMoves(dir.first + x, dir.second + y, tx, ty));
            }
        }
        else if (quadrant_selection == make_pair(false, false))
        {
            //q3
            for (const auto &dir : quadrant_3_directions)
            {
                possible_answers.emplace_back(minKnightMoves(dir.first + x, dir.second + y, tx, ty));
            }
        }
        else if (quadrant_selection == make_pair(true, false))
        {
            //q4
            for (const auto &dir : quadrant_4_directions)
            {
                possible_answers.emplace_back(minKnightMoves(dir.first + x, dir.second + y, tx, ty));
            }
        }

        return dp[temp] = *(std::min_element(possible_answers.begin(), possible_answers.end())) + 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution ob;
    cout << (ob.minKnightMoves(4, 4, 5, 5)) << endl;
    return 0;
}
