/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>

// ListNode Implemention


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        auto start = nums.begin();
        int count = 0;
        for(int i =0, len = nums.size(); i<len;i++)
        {
            if(nums[count]==val)
            {
                // stl vector 删除元素就是快!
                nums.erase(start+count);
                if(count==0) start = nums.begin();
            }
            else count++;
        }
        return count;
    }   
};

int main()
{
    Solution aSolution;
    
}













