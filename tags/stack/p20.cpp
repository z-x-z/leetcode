/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> bracketStack;
        for(int i=0, len= s.size(); i <len; i++)
        {
            char ch = s[i];
            if(ch=='{'||ch=='['||ch=='(') bracketStack.push(ch);
            else if(ch=='}'||ch==']'||ch==')')
            {
                char leftBracket = ch == ')' ? ch-1 : ch-2;
                if(bracketStack.empty()||bracketStack.top()!=leftBracket) return false;
                bracketStack.pop();
            }
        }
        return bracketStack.empty();
    }
};

int main()
{
    Solution aSolution;

}