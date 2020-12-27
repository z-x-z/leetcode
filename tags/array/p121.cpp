#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // 二分法 O(n*logn)
    int maxProfitHelper(const vector<int> prices, int left, int right)
    {
        if(right-left<=1)
        {
            if(right-left==0)
                return 0;
            else // 2
            {
                if(prices[left]<prices[right])
                    return prices[right]- prices[left];
                else
                    return 0;
            }
        }
        int mid = (left+right)/2;
        int leftMaxP = maxProfitHelper(prices, left, mid);
        int rightMaxP = maxProfitHelper(prices, mid+1, right);
        leftMaxP = leftMaxP > rightMaxP ? leftMaxP : rightMaxP;
        int leftMin= prices[left], rightMax= prices[right];
        for (int i = left+1; i <= mid; i++)
            if(prices[i]<leftMin)
                leftMin = prices[i];
        for (int i = right-1; i > mid; i--)
            if(prices[i]>rightMax)
                rightMax = prices[i];
        if(rightMax-leftMin>leftMaxP)
            leftMaxP = rightMax - leftMin;
        return leftMaxP;
    }
    int maxProfitEnum(vector<int>& prices)
    {
        int maxP = 0;
        for (int l = 0; l < prices.size(); l++)
        {
            for (int r = prices.size()-1; r >l ; r--)
            {
                if(prices[r]-prices[l]>maxP)
                    maxP = prices[r] - prices[l];
            }
        }
        return maxP;
    }
    int maxProfitDP(vector<int>& prices)
    {
        int historyMinPrice = INT_MAX; // 历史的最低值（[0, i]区间）
        int presentMaxProfit = 0; // 当前的最大利润
        for (int i = 0; i < prices.size(); i++)
        {
            if(prices[i]<historyMinPrice)
                historyMinPrice = prices[i];
            else if(prices[i]-historyMinPrice<presentMaxProfit)
                presentMaxProfit= prices[i] - historyMinPrice;
        }
        return presentMaxProfit;
    }
};

int main()
{
    vector<int> arr {7,1,5,3,6,4};
    Solution aSolution;
    cout<<aSolution.maxProfit(arr);

}