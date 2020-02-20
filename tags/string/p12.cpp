/// 张雄振
/// 2019/12/18
#include<bits/stdc++.h>
using namespace std;
// I， V， X， L，C，D 和 M。
// 1   5  10 50  100 500 1000
class Solution {
public:
    string intToRoman(int num) 
    {
        const int base = 13;
        int romanBaseInt[base] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string romanChar[base] =  {"I", "IV", "V", "IX", "X", "XL",
                                    "L","XC", "C", "CD", "D", "CM", "M"};
        int i = base-1;
        string romanStr = "";
        while(num>0)
        {
            // 尽量使用大面值的罗马数字
            for (; i >=0&&romanBaseInt[i]>num; i--) {}
            num-= romanBaseInt[i];
            romanStr+=romanChar[i];
        }
        return romanStr;
    }
    
};

int main()
{
    Solution aSolution;
    int num = 1994;
    cin>>num;
    cout<<num;
    cout<<aSolution.intToRoman(num);
}