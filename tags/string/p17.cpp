/// author: CagedBird
/// date: 2020/08/26
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 17. 电话号码的字母组合
    void letterCombinationsHelper(vector<string> &ans, int digtal, const vector<string> &digitalToChars)
    {
        for (int i = 0, len = ans.size(); i < len; i++)
        {
            const string& chars = digitalToChars[digtal-2];
            string oldStr = ans[i];
            ans[i]+= chars[0];
            for (int j=1;j<chars.size();j++)
            {
                ans.push_back(oldStr+chars[j]);
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return vector<string>();
        // 2 ~ 9
        const vector<string> digitalToChars{"abc", "def", "ghi", "jkl", "mon", "pqrs", "tuv", "wxyz"};
        vector<string> ans{""};
        for (int i = 0; i < digits.size(); i++)
        {
            int digtal = stoi(digits.substr(i, 1));
            letterCombinationsHelper(ans, digtal, digitalToChars);
        }
        return ans;
    }
};

int main()
{
    Solution aSolution;
    string digitals = "2345";
    auto strs = aSolution.letterCombinations(digitals);
    for (auto &str : strs)
    {
        cout << str << endl;
    }
}