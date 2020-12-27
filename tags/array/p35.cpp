 /// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    /// 35. 搜索插入位置
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1, mid;
        while (left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]>target)
                right = mid-1;
            else if(nums[mid]<target)
                left = mid+1;
            else
                return mid;
        }
        return left==right? left+1: left;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{1,3,5,6,7};
    int target = 2;
    cout<<aSolution.searchInsert(nums, target);
}













