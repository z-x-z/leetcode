/// author: CagedBird
/// date: 2020/06/24
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /// 剑指 Offer 29. 顺时针打印矩阵
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int up = 0, down = matrix.size() - 1;
        if (down == -1)
            return ans;
        int left = 0, right = matrix[0].size() - 1;
        int i = -1, j = -1;
        while (down >= up && right >= left)
        {
            // 右方向 ->
            for (++i, ++j; j <= right; j++)
                ans.push_back(matrix[i][j]);
            up++;
            if (down < up)
                break;
            // 下方向
            for (--j, ++i; i <= down; i++)
                ans.push_back(matrix[i][j]);
            right--;
            if (right < left)
                break;
            // 左方向 <-
            for (--i, --j; j >= left; j--)
                ans.push_back(matrix[i][j]);
            down--;
            // 上方向
            for (++j, --i; down >= up && i >= up; i--)
                ans.push_back(matrix[i][j]);
            left++;
        }
        return ans;
    }
};

int main()
{
    Solution aSolution;
    vector<vector<int>> matrix{{1,2,3},{4,5,6}};
    for (auto i : aSolution.spiralOrder(matrix))
        cout << i << " ";
}