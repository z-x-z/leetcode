/// author: CagedBird
/// date: 2020/07/12
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 174. 地下城游戏
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > health(m, vector<int>(n, 0));
        vector<vector<int> > dp(m, vector<int>(n, 0));
        // 边缘条件
        dp[0][0] = dungeon[0][0] >0 ? 1: 1-dungeon[0][0];
        health[0][0] = dungeon[0][0] > 0 ? 1+dungeon[0][0] : 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==0&&j==0)
                    continue;
                int fromUp= INT_MAX, fromLeft= INT_MAX, t;
                if(i-1>=0)
                    fromUp = dp[i - 1][j] + (health[i - 1][j] + dungeon[i][j] > 0 ? 0 : +1 - (health[i - 1][j] + dungeon[i][j]));
                if(j-1>=0)
                    fromLeft = dp[i][j-1] + (health[i][j-1] + dungeon[i][j]> 0 ? 0 : +1 - (health[i][j-1] + dungeon[i][j]));
                if (fromUp < fromLeft || (fromUp == fromLeft && health[i - 1][j] > health[i][j - 1])) // chose from up
                {
                    dp[i][j] = fromUp;
                    if ((health[i][j] = health[i - 1][j] + dungeon[i][j]) <= 0)
                        health[i][j] = 1;
                }
                else
                {
                    dp[i][j] = fromLeft;
                    if ((health[i][j] = health[i][j - 1] + dungeon[i][j]) <= 0)
                        health[i][j] = 1;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution aSolution;
    vector<vector<int> > dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout<<aSolution.calculateMinimumHP(dungeon);
}