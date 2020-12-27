/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
using namespace std;
// ListNode Implemention


class Solution {
private:
    inline int getBestFix(int target, int n)
    {
        int fix = target/n;
        return abs(target - fix*n) <= abs(target -(fix+1)*n) ? fix : fix+1;
    }
public:
    int findBestValue(vector<int>& arr, int target)
    {
        const int n = arr.size();
        sort(arr.begin(), arr.end());
        // 前缀和不包括i本身在内的前面的元素之和
        vector<long long> prefixSum(n+1);
        prefixSum[0]= 0;
        for (int i = 1; i <= n; i++)
            prefixSum[i] = prefixSum[i-1]+arr[i-1];
        int  l= 0, r= n, m;
        long diff1, diff2;
        // 二分法搜索极大值
        while(l<r)
        {
            m = (l+r)/2;
            diff1 = prefixSum[m]+(n-m)*arr[m]-target;
            diff2 = prefixSum[m+1]+(n-(m+1))*arr[m+1]-target;
            printf("l: %d, r: %d, m: %d\n", l, r, m);
            printf("diff1: %ld, diff2: %ld\n", diff1, diff2);
            // diff1 < diff2
            // find a case that diff1<0 && diff2>0
            if(diff2<0)
                l= m+1;
            else if(diff1>0)
                r = m-1;
            else
                return getBestFix(target-prefixSum[m+1], n-m-1);

        }
        if(l==n)
            return arr[n-1];
        else
            return getBestFix(target-prefixSum[l], n-l);


    }
};

int main()
{
    Solution aSolution;
    vector<int> arr {};
    int target = 0;
    cout<<aSolution.findBestValue(arr, target);
}













