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
    /// 215. 数组中的第K个最大元素
    int findKthLargest(vector<int>& nums, int k)
    {
        vector<int> tmpArray(nums.begin(), nums.begin()+k);
        sort(tmpArray.begin(), tmpArray.end(), greater<int>());
        for (int i = k; i < nums.size(); i++)
        {
            auto it = lower_bound(tmpArray.begin(), tmpArray.end(), greater<int>());
            
        }


        return 0;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    cout<<aSolution.findKthLargest(nums, k);
}













