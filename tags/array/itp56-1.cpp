/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
#include<map>
using namespace std;

// ListNode Implemention


class Solution {
public:
    vector<int> singleNumbers1(vector<int>& nums)
    {
        int t = 0;
        for (int i: nums)
            t ^= i;
        int bits = 1;
        // 利用a^b来寻找a、b不同位中的最低位
        while (t&bits)
            bits = (bits<<1);
        int a= 0, b= 0;
        // 根据该位将原数组分为两组，且a、b分别在这两组中
        for (int i: nums)
        {
            if(i&bits)
                a^= i;
            else
                b^= i;
        }
        return vector<int>(){a, b};
    } 
    vector<int> singleNumbers(vector<int>& nums) 
    {
        unordered_map<int, int> aMap;
        for(int i=0;i<nums.size();i++)
        {
            if(aMap.find(nums[i])==aMap.end())
                aMap[nums[i]] = 0;
            aMap[nums[i]]++;
        }
        vector<int> result;
        for(auto i: aMap)
            if(i.second==1)
                result.push_back(i.first);
        return result;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums = {4,1,4,6};
    for (auto i: aSolution.singleNumbers(nums))
    {
        cout<<i<<" ";
    }
    
}













