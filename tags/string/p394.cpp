/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s)
    {
        stack<pair<int, string> > aStack;
        aStack.push(make_pair(1, string()));
        int i=0;
        while (i<s.size())
        {
            char ch = s[i];
            if(ch<='9')
            {
                int j;
                for (j = i+1; j < s.size()&&s[j]<='9'; j++);
                int times = 0;
                for (int k = j-1, t=1; k >= i; k--)
                {
                    times+= t*(s[k]-'0');
                    t*=10;
                }
                aStack.push(make_pair(times, string()));
                // 数字之后必然是'['，直接跳过
                i= j;
            }
            else if(ch==']')
            {
                int times = aStack.top().first;
                string tmp = aStack.top().second;
                aStack.pop();
                for (int i = 0; i < times; i++)
                    aStack.top().second.append(tmp);
            }
            // 若是字母，直接将其添加到栈顶的字符串
            else
                aStack.top().second.push_back(ch);
            i++;
        }
        return aStack.top().second;
    }

};

int main()
{
    Solution aSolution;
    string s{"2[abc]3[cd]ef"};
    cout<<aSolution.decodeString(s);
}