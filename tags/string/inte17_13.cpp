/// author: CagedBird
/// date: 2020/07/09
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    // 递归暴力法
    int respaceHelper(const unordered_set<string>& dictSet , const string& sentence, int start)
    {
        int ans = sentence.size()-start;
        for (int i = start; i < sentence.size(); i++)
        {
            for (int j = i; j < sentence.size(); j++)
            {
                if(dictSet.find(sentence.substr(i, j- i+1))!=dictSet.end())
                {
                    // printf("start: %d, i: %d, j: %d\n", start, i, j);
                    ans = min(ans, i-start+respaceHelper(dictSet, sentence, j+1));
                }
            }
        }
        return ans;
    }
    // 递归记忆法
    int respaceHelper1(const unordered_set<string>& dictSet, const string& sentence, int start, unordered_map<int, int>& ansCache)
    {
        // 该步已在缓存中
        if(ansCache.find(start)!=ansCache.end())
            return ansCache[start];
        int ans = sentence.size()-start;
        for (int i = start; i < sentence.size()&&i-start<=ans; i++)
        {
            for (int j = i; j < sentence.size(); j++)
            {
                if(dictSet.find(sentence.substr(i, j- i+1))!=dictSet.end())
                {
                    printf("start: %d, i: %d, j: %d\n", start, i, j);
                    ans = min(ans, i-start+respaceHelper1(dictSet, sentence, j+1, ansCache));
                }
            }
        }
        ansCache[start] = ans; // 缓存
        return ans;
    }

    int respace1(vector<string>& dictionary, string sentence)
    {
        int length= sentence.size();
        vector<int> dp(length+1);
        dp[0] = 0;
        unordered_set<string> dictSet;
        for (auto &s: dictionary)
            dictSet.insert(s);
        for (int i = 1; i <= length; i++)
        {
            printf("i: %d, dp[i]: %d\n", i-1, dp[i-1]);
            dp[i]= dp[i-1]+1;
            for (int j = i-1; j >= 0; j--)
            {
                // 找到
                if(dictSet.find(sentence.substr(j, i-j))!=dictSet.end())
                    dp[i] = min(dp[i], dp[j]);
            }
        }
        return dp[length];
    }

    /// 面试题 17.13. 恢复空格
    int respace(vector<string>& dictionary, string sentence)
    {
        unordered_set<string> dictSet;
        for (auto &s: dictionary)
            dictSet.insert(s);
        unordered_map<int, int> cache;
        return respaceHelper1(dictSet, sentence, 0, cache);
    }
};

int main()
{
    Solution aSolution;
    vector<string> dicitonary{"looked","just","like","her","brother"};
    string sentence = "jesslookedjustliketimherbrother";
    cout<<aSolution.respace1(dicitonary, sentence);
}