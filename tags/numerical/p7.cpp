#include <iostream>
#include<cmath>
#include<stack>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long y = 0;
        while(x!=0)
        {
            y*=10;
            y += x%10;
            x/=10;
        }
        if(y>INT_MAX||y<INT_MIN) return 0;
        else return y;
    }
    double fastPowIterHelp(double x, unsigned int n)
    {
        double result = 1;
        double pow = x;
        const unsigned int lowBitMask = 0x00000001;
        while(n!=0)
        {
            // 通过低位掩码获取最低位
            if(n&lowBitMask)
                result*=pow;
            // 由于n>0所以默认为逻辑右移动
            n >>= 1;// n = (n>>1);
            pow*=pow;//pow = pow^2
        }
        return result;
    }
    double myPow(double x, int n)
    {
        return n>=0? fastPowIterHelp(x, n) : (double)1/fastPowIterHelp(x, -n);
    }
};

int main()
{
    Solution solution;
    cout<<solution.myPow(1, INT_MIN);
    return 0;
}