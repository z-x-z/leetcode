/// author: CagedBird
/// date: 2020/06/27
/// place: JiangXi
/// description: A code template of leetcode's array solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 41. 缺失的第一个正数
    int firstMissingPositive(vector<int> &nums)
    {
        // 原地哈希：将nums[i]（nums[i]<=nums.length）放到相应的nums下标为nums[i]-1的位置去
        auto swapArrayNum = [&nums] (int i, int j)
        {
            int tmp= nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        };
        int length = nums.size();
        for (int i = 0; i < length; i++)
            while (nums[i]>0&&nums[i]<=length&&nums[nums[i]-1]!=nums[i])
                // 直到nums[i]放在正确的位置（下标为nums[i]-1，即nums[nums[i]-1]==nums[i]）上才停止。
                swapArrayNum(i, nums[i]-1);
        int i;
        for (i = 0; i < length; i++)
            if(i!=nums[i]-1)
                break;
        return i+1;
    }

};

int main()
{
    Solution aSolution;
    vector<int> nums{1, 1};
    cout << aSolution.firstMissingPositive(nums);
}
