#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 张雄振
    string convert(string s, int numRows) 
    {
        int n = s.size();
        string result = "";
        // 处理极端情况
        if(numRows<=2)
        {
            if(numRows==1) return s;
            else
            {
                for(int i=0;i<n;i+=2) result+=s[i];
                for(int i=1;i<n;i+=2) result+=s[i];
                return result;
            }
        }
        int i, j;
        int m = 2*numRows-2;

        /*
        m = 2 * numRows - 2 = 2*4-2= 6
        ************
        0     6         ->  间隔为m(6)
        1   5  7        -> 两个元素对之和分别为m的倍数(6, 12 ,18)
        2 4      8      -> 两个元素对之和分别为m的倍数(6, 12 ,18)
        3          9    ->  间隔为m(6)
        ************
        */

        // 首尾两行的间距为m(2*numRows-2)
        j = 0;
        while(j<n)
        {
            result += s[j];
            j+= m;
        }
        // 对于中间行，相邻的两个元素的和等于m的整数倍(i*m i为当前元素对为第几对)
        for ( j = 1; j < numRows-1; j++)
        {
            int k = j;
            i = 1;
            result+=s[k];
            while((k=(i*m-k))<n)
            {
                result += s[k];
                i++;
            }
        }
        // 尾行
        j = numRows-1;
        while(j<n)
        {
            result += s[j];
            j+=m;
        }
        return result;
    }
};

int main()
{
    Solution aSolution;
    string s = "LEETCODEISHIRING";
    // LCIRETOESIIGEDHN
    cout<<(aSolution.convert(s, 2));
}