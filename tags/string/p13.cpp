/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/

class Solution {
public:
    int romanToInt(string s) 
    {
        int result = 0;
        int n = s.size();
        string romanChar = "IXCVLDM";
        string specialRoman = "VXLCDM";
        int romanCharInt[] = {1, 10, 100, 5, 50, 500, 1000};
        int specialInt[] = {4, 9, 40, 90, 400, 900};
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int j;
            if((j = romanChar.find(ch))>=3||i==n-1)
            {
                result += romanCharInt[j];
            }
            else
            {
                char nextChar = s[i+1];
                if(nextChar==specialRoman[2*j])
                {
                    result+= specialInt[2*j];
                    i++;
                }
                else if(nextChar==specialRoman[2*j+1])
                {
                    result+= specialInt[2*j+1];
                    i++;
                }
                else result+=romanCharInt[j];
            }
        }
            return result;
    }
    
};

int main()
{
    Solution aSolution;
    string roman = "MCMXCIV";
    int i = aSolution.romanToInt(roman);
    cout<<i<<endl;
}