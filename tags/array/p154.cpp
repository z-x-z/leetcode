/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 154. 寻找旋转排序数组中的最小值 II
    int findMin(vector<int> &nums)
    {
        // 最小的元素要么是左端点所对应的元素，要么其左右元素都大于它
        // 采用二分查找
        int left = 0, right = nums.size() - 1, mid;
        while (left < right)
        {
            mid = (left+right)/2;
            printf("left: %d, right: %d.\n", left, right);
            if(nums[mid]>nums[right])
                left = mid+1;
            else if(nums[mid]<nums[right])
                right = mid;
            else // 此时只能舍弃右端点
                right--;
        }
        return nums[left];
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{2,2,2,0,1};
    cout << aSolution.findMin(nums);
}