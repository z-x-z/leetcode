/// author: CagedBird
/// date: 2020/07/02
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 378. 有序矩阵中第K小的元素 O(n*n + k*log(n*n)) = o(n^2)
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        vector<int> matrixLinearElements;
        matrix.reserve(n * n); // 预留n*n容量
        for (int i = 0; i < n; i++)
            matrixLinearElements.insert(matrixLinearElements.end(), matrix[i].begin(), matrix[i].end());
        // Kth small -> (n*n-k+1) big
        if (k <= (n * n + 1) / 2)
        {
            // 小顶堆
            auto pQueue = priority_queue<int, vector<int>, greater<int>>(greater<int>(), matrixLinearElements);
            for (int i = 0; i < k - 1; i++)
                pQueue.pop();
            return pQueue.top();
        }
        else
        {
            k = n * n - k + 1;
            // 默认是大顶堆
            priority_queue<int> pQueue = priority_queue<int>(less<int>(), matrixLinearElements);
            for (int i = 0; i < k - 1; i++)
                pQueue.pop();
            return pQueue.top();
        }
    }

    int kthSmallest1(vector<vector<int>> &matrix, int k)
    {
        // 使用堆来实现多个队列有序
        struct MatrixNode
        {
            int val, x, y;
            MatrixNode(int _val, int _x, int _y) : val(_val), x(_x), y(_y)
            {}

            bool operator<(const MatrixNode &node) const
            {return val > node.val; } // 维护一个小顶堆
        };
        int n = matrix.size();
        priority_queue<MatrixNode> nodeQueue;
        for (int i = 0; i < n; i++)
            nodeQueue.emplace(matrix[i][0], i, 0);
        for (int i = 0; i < k-1; i++)
        {
            auto node = nodeQueue.top();
            nodeQueue.pop();
            if(node.y<=n-2)
                nodeQueue.emplace(matrix[node.x][node.y+1], node.x, node.y+1);
        }
        return nodeQueue.top().val;
    }
};

int main()
{
    Solution aSolution;
    vector<vector<int>> matrix1{{1, 2}, {3, 4}};
    int k = 3;
    cout << aSolution.kthSmallest1(matrix1, k);
    // cout<<aSolution.kthSmallest(matrix, k);
}