/// author: CagedBird
/// date: 2020/08/16
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /// 733. 图像渲染
    void floorFillHelper(vector<vector<int>> &image, int r, int c, int oldColor, int newColor)
    {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c]!=oldColor)
            return;
        image[r][c] = newColor;
        floorFillHelper(image, r + 1, c, oldColor, newColor);
        floorFillHelper(image, r - 1, c, oldColor, newColor);
        floorFillHelper(image, r, c + 1, oldColor, newColor);
        floorFillHelper(image, r, c - 1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        floorFillHelper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main()
{
    Solution aSolution;
}