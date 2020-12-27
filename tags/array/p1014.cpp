/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
using namespace std;
// ListNode Implemention


class Solution
{
    // interval: [begin, end)
    int maxScoreSightseeingPair2Helper(const vector<int>& A, int begin, int end)
    {
        if(end-begin<=2)
                return end-begin==2 ?  (A[begin]+A[begin+1]-1): 0;
        int mid = (begin+end)/2;
        int sideMax = maxScoreSightseeingPair2Helper(A, begin, mid);
        sideMax = max(sideMax, maxScoreSightseeingPair2Helper(A, mid, end));
        int li= mid-1, ri = mid;
        for(int i= li-1; i>=begin; i--)
            if(A[i]+i>A[li]+li)
                li = i;
        for (int i = mid+1; i < end; i++)
            if(A[i]-i>A[ri]-ri)
                ri = i;
        int crossMax = A[li]+A[ri]+li-ri;
        return max(sideMax, crossMax);
    }
public:
    // 线性方法，求解A：[i] + i + (A[j] - j)
    int maxScoreSightseeingPair3(vector<int>& A)
    {
        int im = A[0], ans = im+ A[1]-1;
        // 向后迭代访问j，同时更新A[i]+i(i in [0, j)))的最大值
        for(int j =2, t; j< A.size(); j++)
        {
            if((t=A[j-1]+j-1)>im)
                im = t;
            if((t=im+A[j]-j)>ans)
                ans = t;
        }
        return ans;
    }
    // 分治法
    int maxScoreSightseeingPair2(vector<int>& A)
    {
        return maxScoreSightseeingPair2Helper(A, 0, A.size());
    }
    // 暴力法
    int maxScoreSightseeingPair1(vector<int>& A)
    {
        int maxValue = 0;
        for (int i = 0, t= 0; i < A.size(); i++)
            for (int j = i+1; j < A.size(); j++)
                if((t=A[i]+A[j]+i-j)>maxValue)
                    maxValue = t;
        return maxValue;
    }
};

int main()
{
    Solution aSolution;
    vector<int> A{8, 1, 5, 2, 6};
    cout<<aSolution.maxScoreSightseeingPair3(A);
}













