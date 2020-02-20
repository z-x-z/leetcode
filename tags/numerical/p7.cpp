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
};

int main()
{
    Solution solution;
    int x;
    cin>>x;
    int a = solution.reverse(x);
    cout << a << endl;
}