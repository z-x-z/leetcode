/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
using namespace std;
// ListNode Implemention


class Solution {
public:
    //  单调栈
    vector<int> dailyTemperatures(vector<int>& T)
    {
        vector<int> ans(T.size(), 0);
        // 单调栈直接存储下标，温度可以通过访问数组得到
        stack<int> monoStack;
        for (int i = 0, nowTmp; i < T.size(); i++)
        {
            nowTmp = T[i];
            while (!monoStack.empty()&&nowTmp>T[monoStack.top()])
            {
                ans[monoStack.top()] = i- monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return ans;
    }
};

int main()
{
    Solution aSolution;

}













