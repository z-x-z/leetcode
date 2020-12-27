/// author: CagedBird
/// date: 2020/07/05
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 44. 通配符匹配
    // 类似于p10的简单正则表达式实现
    bool isMatch(string s, string p)
    {
        auto charMatch = [](char cp, char cs) { return cp == '?' ? true : cp == cs; };
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m&&p[j-1]=='*'; j++)
            dp[0][j] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // 匹配多次
                else if (charMatch(p[j - 1], s[i - 1]))
                    dp[i][j] = dp[i - 1][j - 1];
            }
        return dp[n][m];
    }
};

int main()
{
    Solution aSolution;
    string s = "aaa";
    string p = "*";
    cout << aSolution.isMatch(s, p);
    return 0;
}