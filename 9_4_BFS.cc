#include <bits/stdc++.h>
using namespace std;

// 1197: Leetcode
// Modified with help from the article at : https://blog.csdn.net/aique3350/article/details/102000437

class Solution
{
public:
    int minKnightKingMoves(int x, int y)
    {
        x = abs(x);
        y = abs(y);
        int MAXN = 310, steps = 0;
        //just knight moves
        /*int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};*/
        //knight + king moves
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2, 1, 0, -1, 0, 1, 1};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1, 0, 1, 0, -1, 1, -1};
        queue<vector<int>> q;

        bool visited[MAXN][MAXN] = {false};
        q.emplace(vector<int>({0, 0}));
        visited[0][0] = true;

        while (q.size() > 0)
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();
                if (curr[0] == x && curr[1] == y)
                {
                    return steps;
                }
                for (int j = 0; j < 8; j++)
                {
                    int x1 = curr[0] + dx[j];
                    int y1 = curr[1] + dy[j];
                    if (x1 < 0 || y1 < 0 || x1 >= MAXN || y1 >= MAXN)
                    {
                        continue;
                    }
                    if (!visited[x1][y1])
                    {
                        visited[x1][y1] = true;
                        q.emplace(vector<int>({x1, y1}));
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution ob;
    cout << ob.minKnightKingMoves(144,144) << endl;
    return 0;
}
