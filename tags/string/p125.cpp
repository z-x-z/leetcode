/// author: CagedBird
/// date: 2020/06/19
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline char convertChar(char ch)
    {
        if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z'))
            return ch;
        // 大写转化为小写
        else if(ch>='A'&&ch<='Z')
            return ch-'A'+'a';
        else
            return 0;
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size()-1;
        char left, right= ' ';
        while (i<=j)
        {
            while ((i<=j)&&((left=convertChar(s[i++]))==0)) ;
            while ((i-1<=j)&&((right=convertChar(s[j--]))==0)) ;
            cout<<left<<" "<<right<<endl;
            if(left!=right)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution aSolution;
    string s = "  ,./";
    cout<<aSolution.isPalindrome(s);
}