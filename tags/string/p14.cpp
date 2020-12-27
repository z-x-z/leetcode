/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string longestCommonPrefixHorizontalHelper(string& s1, string& s2)
    {
        int minSize = s1.size() < s2.size() ? s1.size() : s2.size(), i;
        for (i = 0; i < minSize; i++)
            if(s1[i]!=s2[i])
                break;
        return s1.substr(0, i);
    }
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int arrSize = strs.size();
        if(arrSize<=0)
            return "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            char charAt = strs[0][i];
            for (int j = 1; j < arrSize; j++)
                if(i>=strs[j].size()||strs[j][i]!=charAt)
                    return strs[0].substr(0, i);
        }
        return strs[0];
    }
    // Horizontal
    string longestCommonPrefixHorizontal(vector<string>& strs)
    {
        string res;
        int arrSize = strs.size();
        if(arrSize!=0)
        {
            res = strs[0];
            for (int i = 1; i < arrSize; i++)
                res = longestCommonPrefixHorizontalHelper(res, strs[i]);
        }
        return res;
    }
};

int main()
{
    Solution aSolution;
    vector<string> strs{"abadon","abstract","absent"};
    cout<<aSolution.longestCommonPrefix(strs);
}