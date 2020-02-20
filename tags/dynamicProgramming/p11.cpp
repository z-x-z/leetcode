/// 张雄振
/// 2019/12/18
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 张雄振
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size()-1;
        int res, area;
        res = 0;
        while(i!=j)
        {
            if( (area=min(height[i], height[j])*(j-i))>res)
            {
                res = area;
            }
            // 每一次存在两种移动可能性:
            // 1. 移动较长的一方
            // 2. 移动较短的一方
            // 而移动较长的一方将一定使当前面积减少，所以不需要考虑这种情况
            // 移动较短的一方可能会出现最大值，所以在搜索过程中只需要移动较小的一方
            if(height[i]>height[j])
            {
                j--;
            }
            else i++;
        }  
        return res; 
    }
};

int main()
{
    Solution aSolution;
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector可使用assign
    int result = aSolution.maxArea(height);
    cout << "Result: " << result;
}