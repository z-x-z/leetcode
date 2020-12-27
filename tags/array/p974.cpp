/// author: CagedBird
/// date: 2019/12/18
/// place: BeiJing
/// description: A code template of leetcode's array solution

#include<bits/stdc++.h>
using namespace std;
// ListNode Implemention


class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K)
    {
        int length = A.size();
        int sum = 0;
        vector<int> modCount(K, 0);
        modCount[0] = 1;
        int resultCount = 0;
        for (int i = 0, t; i < length; i++)
        {
            sum = sum+A[i-1]; // (sum % K + K) % K;
            t = (sum%K+K)%K;
            resultCount+= modCount[t];
            modCount[t]++;
        }
        return resultCount;
    }
};
// |小| % |大| = |小| 符号同前    -2 % 5 = -2, 2 % -5 = 2
// |大| % |小| = |余| 符号同前
int main()
{
    int t = -2%5;
    cout<<t<<endl;
    Solution aSolution;
    vector<int> A{-2};
    //{4,5,0,-2,-3,1};
    int K = 6;
    cout<<aSolution.subarraysDivByK(A, K);
}













