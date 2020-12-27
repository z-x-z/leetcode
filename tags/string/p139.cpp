/// author: CagedBird
/// date: 2020/06/25
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    /// 139. 单词拆分
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int m = s.size(), n = wordDict.size();
        unordered_set<string> wordSet;
        for (int i = 0; i < n; i++)
            wordSet.insert(wordDict[i]);
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
        return dp[m];
    }

    bool check(int start, const string& s, const unordered_set<string>& wordSet, vector<int>& status)
    {
        cout<<start<<endl;
        if(status[start]!=0)
            return status[start]==1;
        for (int i = start+1; i <= s.size(); i++)
            if(wordSet.count(s.substr(start, i-start))&&check(i, s, wordSet, status))
            {
                status[start] = 1;
                return true;
            }
        status[start] = -1;
        return false;
    }
    bool wordBreak2(string s, vector<string> &wordDict)
    {
        int m = s.size(), n = wordDict.size();
        unordered_set<string> wordSet;
        for (int i = 0; i < n; i++)
            wordSet.insert(wordDict[i]);
        vector<int> status(m+1, 0);
        status[m] = 1;
        return check(0, s, wordSet, status);
    }
};

int main()
{
    Solution aSolution;
    string s = "applepenapple";
    vector<string> wordDict{"apple", "pen"};
    cout<<aSolution.wordBreak2(s, wordDict)<<endl;
    return 0;
}