/// 张雄振
/// 2019/12/18
#include <bits/stdc++.h>
using namespace std;
/* Problem Request:
给你一个字符串 s 和一个字符规律 p
'.' 匹配任意单个字符
'*' 匹配零个或多个"前面"的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
*/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sn = s.size(), pn = p.size();
        int i, j;
        string rp;
        for ( i = 0; i < pn; i++)
        {
            if(i+1<pn&&p[i+1]=='*')
            {
                if(p[i]=='.') rp+= 24;
                else rp+= p[i]-'a';
            }
            else rp += p[i];
        }
        pn = rp.size();
        i = 0, j = 0;
        while(i!=sn||j!=pn)
        {
            if(rp[j]==24)
            {
                i++; j++;
            }
            else
            {
                if(rp[j]>24)
                {
                    if(s[i]==rp[j]) 
                    {
                        j++;
                        i++;
                    }
                }
                else
                {
                    if(s[i]-'a'==rp[j])
                    {
                        
                    }
                    else return false;
                }
            }
        }
        
    }
    
};

int main()
{
    Solution aSolution;
    string str = "aab";
    string pattern = "c*a*b";
    cout << aSolution.isMatch(str, pattern);
}