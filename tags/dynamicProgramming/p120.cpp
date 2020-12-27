/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    /// 120. 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        if(n==0)
            return 0;
        vector<int> lastRowMinTotal(n, triangle[0][0]);
        vector<int> curRowMinTotal(n, 0);
        for (int i = 1; i < n; i++) // 从第二行开始
        {
            curRowMinTotal[0] = triangle[i][0] + lastRowMinTotal[0];
            for (int j = 1; j < i; j++)
            {
                curRowMinTotal[j] = triangle[i][j] + min(lastRowMinTotal[j-1], lastRowMinTotal[j]);
            }
            curRowMinTotal[i] = triangle[i][i] + lastRowMinTotal[i-1];
            curRowMinTotal.swap(lastRowMinTotal);
        }
        int minTotal = INT_MAX;
        for (auto total: lastRowMinTotal)
            if(total<minTotal)
                minTotal = total;
        return minTotal;
    }
    
};

int main()
{
    Solution aSolution;
    vector<vector<int> > triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<aSolution.minimumTotal(triangle);
}