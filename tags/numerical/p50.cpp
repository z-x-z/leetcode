/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Solution {
public:
    double fastPowIterHelp(double x, int n)
    {
        double result = 1;
        double pow = x;
        const int lowBitMask = 0x00000001;
        while(n!=0)
        {
            // 通过低位掩码获取最低位
            if(n&lowBitMask) result*=pow; // 或者 if(n%2)
            // 由于n>0所以默认为逻辑右移动
            n >>= 1; // n/=2
            pow*=pow;//pow = pow^2
        }
        return result;
    }
    double fastPowHelper(double x, int n)
    {
        if(n==0)
            return 1;
        // 偶数 x^n = (x^2)(n/2)
        if(n%2==0)
            return fastPowHelper(x*x, n/2);
        // 奇数 x^n = (x^2)(n/2)*x
        else
            return fastPowHelper(x*x, n/2)*x;
    }
    double myPow(double x, int n)
    {
        // -INT_MIN = -(0x8000,0000) = 0x7fff,ffff+0x0000,0001
        // = 0x8000,0000 = INT_MIN
        if(n==INT_MIN)
            return (double)1/(fastPowIterHelp(x, INT_MAX)*x);
        if(n<0)
            return (double)1/fastPowIterHelp(x, -n);
        else
            return fastPowIterHelp(x, n);
    }
    
};

int main()
{
    Solution aSolution;
    cout<<aSolution.myPow(2, 5)<<endl;
    cout<<aSolution.myPow(2, 10)<<endl;
    cout<<aSolution.myPow(2, -10)<<endl;
    cout<<aSolution.myPow(2, -5)<<endl;
}