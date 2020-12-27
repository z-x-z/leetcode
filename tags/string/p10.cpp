/// 张雄振
/// 2019/12/18
#include <bits/stdc++.h>
using namespace std;
/* Problem Request:
给你一个字符串 s 和一个字符规律 p
'.' 匹配任意单个字符
'*' 匹配零个或多个"前面"的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
*/

class Solution
{
public:
    inline bool charMath(char chs, char chp)
    {
        if(chp=='.')
            return true;
        else
            return chs==chp;
    }
    bool isMatch(string s, string p)
    {
        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1));
        dp[0][0] = true;
        // 对i=0做单独考虑
        for (int j = 1; j <= p.size(); j++)
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-2];

        // 实际考虑的字符下标为(i-1, j-1)
        for (int i = 1; i <= s.size(); i++)
        {
            char chs = s[i-1];
            for (int j = 1; j <= p.size(); j++)
            {
                char chp = p[j-1];
                if(chp=='*')
                {
                    if(!charMath(chs, p[j-2]))
                        dp[i][j] = dp[i][j-2]; // * 匹配0次
                    else
                        dp[i][j] = dp[i-1][j]||dp[i][j-2]; //匹配多次或者0次
                }
                else if(charMath(chs, chp))
                        dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[s.size()][p.size()];
    }

};

int main()
{
    Solution aSolution;
    string str = "aa";
    string pattern = "a";
    cout << aSolution.isMatch(str, pattern);
}