#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        char digital[20];
        int y = x;
        int i;
        for (i = 0; y!=0; i++)
        {
            digital[i] = y%10;
            y/=10;
        }
        // i为x的10进制长度
        int half = (i+1)/2;
        for (int j = 0; j <half; j++)
        {
            if(digital[j]!=digital[i-j-1]) return false;
        }
        return true;    
    }
};
int main()
{
    int x;
    cin>>x;
    cout<<Solution().isPalindrome(x);
}