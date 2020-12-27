/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> valueStack;
        for (string& token: tokens)
        {
            if(token=="+"||token=="-"||token=="*"||token=="/")
            {
                char op = token[0];
                int op2 = valueStack.top(); valueStack.pop();
                int op1 = valueStack.top(); valueStack.pop();
                // switch相比if-else而言，当case数目多时具有一定的性能优势
                // 其中switch使用了哈希表进行优化
                switch(op)
                {
                    case '+': op1 = op1+op2; break;
                    case '-': op1 = op1-op2; break;
                    case '*': op1 = op1*op2; break;
                    default: op1 = op1/op2;
                }
                valueStack.push(op1);
            }
            else valueStack.push(atoi(token.c_str()));
        }
        return valueStack.top();
    }
};

int main()
{
    Solution aSolution;

}