/// author: CagedBird
/// date: 2020/09/08
/// place: BeiJing
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  /// 77. 组合
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> res;
    vector<int> path_stack;
    combine_dfs(n, k, 1, path_stack, res);
    return res;
  }
  // 从数字start开始到数字n中选择k个数字，将所有不同的组合放入res中
  void combine_dfs(const int n, const int k, int start, vector<int> &path_stack, vector<vector<int>> &res)
  {
    if (path_stack.size() == k)
    {
      res.push_back(path_stack);
      return;
    }
    // 枝减：若start>n或接下剩余数字全部被选择也不能满足长度k，则直接枝减
    if(start>n||(n-start)+path_stack.size()+1<k)
      return;
    // 选择start号数字
    path_stack.push_back(start);
    combine_dfs(n, k, start + 1, path_stack, res);
    // 不选择start号数字
    path_stack.pop_back();
    combine_dfs(n, k, start + 1, path_stack, res);
  }
  vector<vector<int>> combine_enum(int n, int k)
  {
    vector<vector<int>> res;
    if (k <= 1)
    {
      for (int i = 1; i <= n; i++)
      {
        vector<int> tmp(k, i);
        res.push_back(tmp);
      }
    }
    else
    {
      vector<vector<int>> tmp_res = combine(n, k - 1);
      for (auto &combination : tmp_res)
      {
        int last_num = combination[k - 2];
        combination.push_back(0);
        for (int i = last_num + 1; i <= n; i++)
        {
          combination[k - 1] = i;
          res.push_back(combination);
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution aSolution;
  int n = 4, k = 2;
  auto combinations = aSolution.combine1(n, k);
  for (auto &combination : combinations)
  {
    for (auto i : combination)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}