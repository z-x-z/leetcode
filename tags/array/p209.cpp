/// author: CagedBird
/// date: 2020/06/28
/// place: JiangXi
/// description: A code template of leetcode's array solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 209. 长度最小的子数组
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int length = nums.size();
        vector<int> prefixSum(length + 1);
        prefixSum[0] = 0;
        for (int i = 1; i <= length; i++)
            prefixSum[i] = nums[i - 1] + prefixSum[i - 1];
        int minDis = INT_MAX;
        // find the match i, j which make prefixSum[j] - prefixSum[i] >= s
        for (int i = 0; i < length; i++)
        {
            int left = i + 1, right = length;
            int mid, diff, target = prefixSum[i] + s;
            // binary find the best match of prefixSum[j] >= prefixSum[i] + s
            while (left < right)
            {
                mid = (left + right) / 2;
                diff = prefixSum[mid] - (target);
                if (diff < 0)
                    left = mid + 1;
                else if (diff > 0)
                    right = mid - 1;
                else
                    break;
            }
            if (prefixSum[mid = (left + right) / 2] >= target || (++mid <= length && prefixSum[mid] >= target))
                if (mid - i < minDis)
                    minDis = mid - i;
        }
        return minDis != INT_MAX ? minDis : 0;
    }

    int minSubArrayLen1(int s, vector<int> &nums)
    {
        int length = nums.size();
        int start = 0, end = 0;
        int sum = 0, ans = INT_MAX;
        while (end < length)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return ans != INT_MAX ? ans : 0;
    }
};

int main()
{
    Solution aSolution;
    int s = 11;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << aSolution.minSubArrayLen(s, nums);
}
