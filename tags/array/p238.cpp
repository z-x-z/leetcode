/// author: CagedBird
/// date: 2020/06/25
/// place: JiangXi
/// description: A code template of leetcode's array solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /// 238. 除自身以外数组的乘积

    // 前缀与后缀乘积
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixProduct(n);
        vector<int> postfixProduct(n);
        prefixProduct[0] = postfixProduct[n-1] = 1;
        for (int i = 1; i < n; i++)
            prefixProduct[i] = (prefixProduct[i - 1] * nums[i - 1]);
        for (int i = n-2; i >=0 ; i--)
            postfixProduct[i] = (postfixProduct[i + 1] * nums[i+1]);
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(prefixProduct[i]*postfixProduct[i]);
        return ans;
    }
    vector<int> productExceptSelf1(vector<int> &nums)
    {
        int n = nums.size();
        int prefixProduct, postfixProduct;
        vector<int> ans(n, 1);
        prefixProduct = postfixProduct = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i]*=prefixProduct;
            ans[n-i-1]*=postfixProduct;
            prefixProduct*= nums[i];
            postfixProduct*= nums[n-i-1];
        }
        return ans;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums{1,2,3,4};
    for (auto i: aSolution.productExceptSelf1(nums))
        cout<<i<<" ";

}
