/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>

// ListNode Implemention


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        int len = nums.size();
        if(len==0) return 0;
        int j = 0;
        for(int i =0; i<len;i++)
        {
            if(nums[j]!=nums[i]) nums[++j] = nums[i];
        }
        // 长度实际上是j+1
        return j+1;
    }
};

int main()
{
    Solution aSolution;
    
}













