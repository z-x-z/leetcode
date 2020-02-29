/// author: CagedBird
/// date: 2020/02/27
/// place: JiangXi, ShangRao
/// description: A code template of leetcode's dynamic programing solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArrayDC(vector<int>& nums)
    {
        return maxSubArrayDC_helper(nums, 0, nums.size());
    }
    int maxSubArrayDC_helper(vector<int>& nums, int begin, int end)
    {
        if(end-begin==1) return nums[begin];
        int mid = (begin + end) / 2;
        int leftSum = maxSubArrayDC_helper(nums, begin, mid);
        int rightSum = maxSubArrayDC_helper(nums, mid, end);
        int crossSum = maxSubArrayDC_crossSum(nums, begin, mid, end);
        if(rightSum > leftSum) leftSum = rightSum;
        return leftSum > crossSum ? leftSum : crossSum;
    }
    int maxSubArrayDC_crossSum(vector<int>& nums, int begin, int mid, int end)
    {
        int curSum = 0;
        int rightSum = INT_MIN;
        for(int i = mid ; i < end; i++)
        {
            curSum+= nums[i];
            rightSum = rightSum > curSum ? rightSum : curSum;
        }
        curSum = 0;
        int leftSum = INT_MIN;
        for(int i = mid-1 ; i >= begin;i--)
        {
            curSum+= nums[i];
            leftSum = leftSum > curSum ? leftSum : curSum;
        }
        return rightSum + leftSum;
    }
    int maxSubArray1(vector<int>& nums)
    {
        //减少maxSubArray算法中不必要的空间浪费：即不需要保留整个历史而只需要记住前一个
        int maxSum = INT_MIN;
        int sum = 0;
        for (int num: nums)
        {
            sum += num;
            maxSum = maxSum > sum ? maxSum : sum;
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
    int maxSubArray(vector<int>& nums) 
    {
        const int N = nums.size();
        if(N==0) return 0;
        int maxToi[N];
        int fromMaxSum = maxToi[0] = nums[0];
        for(int i=1;i<N;i++)
        {
            fromMaxSum += nums[i];
            // Find maximum in (fromMaxSum, nums[i], MaxToi[i-1]).
            // If maximum is nums[i], then update the fromMaxSum
            if(nums[i]>fromMaxSum&&nums[i]>maxToi[i-1]) maxToi[i] = fromMaxSum = nums[i];
            //Find maximum in (fromMaxSum + nums[i], maxToi[i-1])
            else maxToi[i] = fromMaxSum >= maxToi[i-1] ? fromMaxSum : maxToi[i-1];
            if(fromMaxSum<0) fromMaxSum = 0;
            printf("subSequenceSum of %d is %d\n", i, maxToi[i]);
        }
        return maxToi[N-1];
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{-2, -1, 0};
    cout<<aSolution.maxSubArrayDC(nums);
}