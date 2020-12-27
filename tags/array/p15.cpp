/// 张雄振
/// 2019/12/18
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum1(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // i为三元组中最右边的下标
        int i= 0;
        while (i < nums.size()-2&&nums[i]<=0)
        {
            // 去除第二及其之后的重复
            // 如 1 1 1 2 3 -> 在访问下标0所对应的1后，其后下标1、2的1直接跳过
            if(i>1)
                while(i<nums.size()-2&&nums[i-1]==nums[i])
                    i++;
            int l = i+1, r = nums.size()-1;
            int sum;
            while(l<r)
            {
                if((sum = nums[i]+nums[l]+nums[r])==0)
                {
                    result.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    // 跳过重复的元素
                    while(l<r&&nums[r-1]==nums[r])
                        r--;
                    while (l<r&&nums[l+1]==nums[l])
                        l++;
                    r--;
                    l++;
                }
                // sum>0，说明nums[r]过大
                else if(sum>0)
                    r--;
                else
                    l++;
            }
            while (i+1<nums.size()-2&&nums[i+1]==nums[i])
                i++;
            i++;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n - 1; i++)
        {
            if(nums[i]==0)
            {
                int j;
                for (j = i+1; j<n&&nums[j]==0; j++);
                if(j!=n&&j-i>2)
                {
                    vector<int> tmp {0, 0, 0};
                    result.push_back(tmp);
                }
            }
            if (nums[i] <= 0) // 相同的负数取最右边的一个
            {
                int j;
                for (j = i + 1; j < n - 1 && nums[i] == nums[j]; j++)
                    ;
                i = j - 1;
            }
            int l = 0, r = n - 1; // 左右手
            while (l != i && r != i)
            {
                int sum;
                sum = nums[l] + nums[i] + nums[r];
                // 优化搜索
                if (sum == 0)
                {
                    vector<int> tmp{nums[l], nums[i], nums[r]};
                    result.push_back(tmp);
                }
                if (sum >= 0)
                    for (r= r-1; r > i && nums[r+1] == nums[r]; r--)
                        ;
                else if (sum < 0)
                    for (l= l+1; l < i && nums[l-1] == nums[l]; l++)
                        ;
            }
            if (nums[i] > 0)
            {
                int j;
                for (j = i + 1; j < n - 1 && nums[i] == nums[j]; j++)
                    ;
                i = j - 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{0, 0, 0, 0, 0, 0};
    // -4 -1 -1 0 1 2
    for (auto vec : aSolution.threeSum1(nums))
    {
        for (auto i : vec)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}