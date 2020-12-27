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

    vector<string> inorderToBackorder(string& s)
    {
        vector<string> backOrderExpression;
        stack<char> opStack;
        for (int i = 0, len = s.size(); i < len; i++)
        {
            char ch = s[i];
            if(ch==' ') continue;
            if(ch==')')
            {
                while ((ch = opStack.top()) !='(')
                {
                    string str;
                    str.push_back(ch);
                    backOrderExpression.push_back(str);
                    opStack.pop();
                }
                opStack.pop();
            } 
            else if(ch=='(') 
                opStack.push('(');
            else if(ch<'0'||ch>'9')
            {
                short order = opOrder(ch);
                // 此时的符号等级要大于栈顶的符号等级
                char top;
                while(!opStack.empty()&&((top=opStack.top())!='(')&&opOrder(top)>=order)
                {
                    string str;
                    str.push_back(top);
                    backOrderExpression.push_back(str);
                    opStack.pop();
                }
                opStack.push(ch);
            }
            else 
            {
                int j = i+1;
                char num;
                for (j = i+1, num = s[j]; num<='9'&&num>='0'&&j < len; j++, num=s[j]);
                // push_back(start, len)
                backOrderExpression.push_back(s.substr(i, j-i));
                i = j-1;
            }
        }
        while(!opStack.empty()) 
        {
            string str;
            str.push_back(opStack.top());
            backOrderExpression.push_back(str);
            opStack.pop();
        }
        return backOrderExpression;
    }

    // 实现一个基本的计算器(+, -, (, ))来计算一个简单的字符串表达式的值

    // 实现一个较为齐全的计算器(+, -, *, /, (, ))来计算一个简单的字符串表达式的值
    short opOrder(char ch)
    {
        switch (ch)
        {
        case '(':
            return 3;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            return 1;
            break;
        }
    }

    int calculate2(string s) {
        vector<string> backorder = inorderToBackorder(s);
        return evalRPN(backorder);
    } 
};

int main()
{
    Solution aSolution;
    string s = "2+(2+2*3)+4/2-1";
    printf("%s == %d", s.c_str(), aSolution.calculate2(s));
}