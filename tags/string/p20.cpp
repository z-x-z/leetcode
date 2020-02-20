/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(string s) 
    {
        // a
        stack<char> brackets;
        for (int i = 0, len = s.size(); i < len; i++)
        {
            char ch = s[i];
            if(ch=='('||ch=='['||ch=='{') brackets.push(ch);
            else
            {
                if(brackets.empty()) return false;
                if(ch==')')
                {
                    if(brackets.top()=='(') brackets.pop();
                    else return false;
                }
                if(ch==']')
                {
                    if(brackets.top()=='[') brackets.pop();
                    else return false;
                }
                if(ch=='{')
                {
                    if(brackets.top()=='{') brackets.pop();
                    else return false;
                }
            }
        }
        return brackets.empty();
            
    }
    
};

int main()
{
    Solution aSolution;
    cout<<aSolution.isValid("()[]{}");
    int a;
}