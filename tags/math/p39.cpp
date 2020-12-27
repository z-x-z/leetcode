/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  /// 39. 组合总和
  vector<vector<int> > combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<int> path;
    vector<vector<int> > res;
    combinationSum_dfs(candidates, target, 0, path, res);
    return res;
  }
  // candidates从下标start开始选择，目标为target
  // 其当前路径暂存于path中，最终结果保留在res中
  void combinationSum_dfs(const vector<int> &candidates, int target, int start,
                          vector<int> &path, vector<vector<int> > &res)
  {
    if (target == 0)
    {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
      if (candidates[i] <= target)
      {
        path.push_back(candidates[i]);
        combinationSum_dfs(candidates, target - candidates[i], i, path, res);
        path.pop_back();
      }
      else
        break;
    }
  }
};

int main()
{
  Solution aSolution;
  vector<int> candidates{2, 3, 5};
  int target = 8;
  for (auto &path : aSolution.combinationSum(candidates, target))
  {
    for (auto i : path)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}