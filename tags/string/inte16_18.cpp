/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool patterMatchingHelper(const string &pattern, const string &value, const int firstCount,
                              const int anotherCount, const int firstPatternSize, const int firstSuccessionCharSize)
    {
        string anotherPatternValue;
        if (anotherCount == 0)
        {
            if (value.size() % firstCount != 0)
                return false;
            anotherPatternValue = "";
        }
        else
        {
            if ((value.size() - firstCount * firstPatternSize) % anotherCount != 0)
                return false;
            anotherPatternValue = value.substr(firstSuccessionCharSize * firstPatternSize, (value.size() - firstCount * firstPatternSize) / anotherCount);
        }
        string firstPatternValue = value.substr(0, firstPatternSize);
        string patternValue = "";
        for (int i = 0; i < pattern.size(); i++)
        {
            if (pattern[i] == pattern[0])
                patternValue += firstPatternValue;
            else
                patternValue += anotherPatternValue;
        }
        return patternValue == value;
    }
    bool patternMatching(string pattern, string value)
    {
        int m = pattern.size(), n = value.size();
        if(m==0)
            return n==0;
        int firstCount = 0, anotherCount, firstSuccessionCharSize = m;
        for (int i = 0; i < m; i++)
            if (pattern[i] != pattern[0])
            {
                firstSuccessionCharSize = i;
                break;
            }
        for (int i = 0; i < m; i++)
            if (pattern[i] == pattern[0])
                firstCount++;
        anotherCount = m - firstCount;
        if(firstCount==1||anotherCount==1)
        {
            return 
        }
        int firstPatterMaxSize = n / firstCount;
        if (anotherCount == 0)
            return patterMatchingHelper(pattern, value, firstCount, anotherCount,
                                        firstPatterMaxSize, firstSuccessionCharSize);
        char firstPatternLastChar = pattern[0] == pattern[m - 1] ? value[n - 1] : 0;

        for (int i = 0; i < firstPatterMaxSize; i++)
        {
            if ((firstPatternLastChar == 0 || value[i] == firstPatternLastChar) &&
                patterMatchingHelper(pattern, value, firstCount, anotherCount, i + 1, firstSuccessionCharSize))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution aSolution;
    string pattern = "aaaaab";
    string value = "xahnxdxyaahnxdxyaahnxdxyaahnxdxyaauxuhuo";
    cout<<aSolution.patternMatching(pattern, value);
}