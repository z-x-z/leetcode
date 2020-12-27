/// author: CagedBird
/// date: 2020/07/01
/// place: JiangXi
/// description: A code template of leetcode's array solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 718.最长的重复子数组
    int findLength(vector<int> &A, vector<int> &B)
    {
        vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));
        // dp[i][j] = A[i]==B[j] ? dp[i+1][j+1] + 1 : 0
        int ans= 0;
        for (int i = A.size()-1; i >=0 ; i--)
            for (int j = B.size()-1; j >=0; j--)
            {
                dp[i][j] = A[i]==B[j] ? dp[i+1][j+1] + 1 : 0;
                if(dp[i][j]>ans)
                    ans = dp[i][j];
            }

        return ans;
    }
};

int main()
{
    Solution aSolution;
    vector<int> A{0, 0, 0, 0, 1};
    vector<int> B{0, 0, 1, 0, 0, 0, 1};
    cout << aSolution.findLength(A, B);
}
