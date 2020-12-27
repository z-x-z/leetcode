#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 张雄振
    bool isNumber(char ch)
    {
        return ch - '0' >= 0 && ch - '0' <= 9;
    }
    int myAtoi(string str)
    {
        int len = str.size();
        int strip;
        for (strip = 0; strip < len && str[strip] == ' '; strip++)
            ;
        int i = strip;
        int flag = 1;
        if (str[i] == '+' || str[i] == '-')
            flag = str[i++] == '+' ? 1 : -1;
        const long maxValue = (long)INT32_MAX + (flag > 0 ? 0 : 1);
        long result = 0;
        for (int j = i; j < len && isNumber(str[j]); j++)
        {
            result *= 10;
            result += (str[j] - '0');
            if (result > maxValue)
                return flag > 0 ? INT32_MAX : INT32_MIN;
        }
        return flag * result;
    }
};

int main()
{
    Solution aSolution;
    string str = "-42";
    cout << (aSolution.myAtoi(str));
}