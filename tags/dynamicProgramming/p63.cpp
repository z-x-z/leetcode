/// author: CagedBird
/// date: 2020/07/06
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    ///
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n && obstacleGrid[0][i] != 1; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = obstacleGrid[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution aSolution;
}