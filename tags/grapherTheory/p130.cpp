/// author: CagedBird
/// date: 2020/08/11
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<char>> toCharGraph(vector<string> &board)
    {
        vector<vector<char>> charGraph(board.size());
        for (int i = 0; i < charGraph.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                charGraph[i].push_back(board[i][j]);
            }
        }
        return charGraph;
    }
    void printGraph(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    /// 130. 被围绕的区域
    void dfs(int x, int y, vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O')
            return;
        printf("x: %d, y: %d.\n", x, y);
        board[x][y] -= 'X' - 'O';
        dfs(x + 1, y, board);
        dfs(x - 1, y, board);
        dfs(x, y + 1, board);
        dfs(x, y - 1, board);
    }
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        // 访问上下边界
        for (int i = 0; i < cols; i++)
        {
            if (board[0][i] == 'O') // 上边界
                dfs(0, i, board);
            if (board[rows - 1][i] == 'O')
                dfs(rows - 1, i, board);
        }
        // 访问左右边界
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O') // 访问左边界
                dfs(i, 0, board);
            if (board[i][cols - 1] == 'O') // 访问右边界
                dfs(i, cols - 1, board);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] != 'X')
                    board[i][j] += 'X' - 'O';
            }
        }
    }
};

int main()
{
    Solution aSolution;
    vector<vector<char>> board{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    aSolution.solve(board);
    aSolution.printGraph(board);
}