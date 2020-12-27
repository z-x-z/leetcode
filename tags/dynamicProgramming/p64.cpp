/// author: CagedBird
/// date: 2020/07/23
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 64. 最小路径和
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m+1, vector<int> (n+1, INT_MAX));
        int isFinsh = 1;
        for (int i = m-1; i >= 0; i--)
        {
            for (int j = n-1; j >=0; j--)
            {
                if(isFinsh)
                {
                    dp[i][j] = grid[i][j];
                    isFinsh = 0;
                }
                else
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution aSolution;
    vector<vector<int> > grid{{1,3,1},{1,5,1},{4,2,1}};
    cout<<aSolution.minPathSum(grid);
    return 0;
}