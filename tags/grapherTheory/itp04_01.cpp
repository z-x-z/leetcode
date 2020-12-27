/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isFind;
    int aim;
    void dfs(int vertex, const vector<set<int>> &linkedGraph, vector<bool> &isVisited)
    {
        if (isFind || isVisited[vertex])
            return;
        isVisited[vertex] = true;
        if (vertex == aim)
        {
            isFind = true;
            return;
        }
        for (int v : linkedGraph[vertex])
            dfs(v, linkedGraph, isVisited);
    }
    bool bfs(vector<vector<int> >& linkedGraph, int start, int target)
    {
        int n = linkedGraph.size();
        vector<bool> isVisited(n);
        for (int i=0;i<n;i++)
            isVisited[i] = false;
        queue<int> bfsQueue;
        bfsQueue.push(start);
        while (!bfsQueue.empty())
        {
            int v= bfsQueue.front();
            bfsQueue.pop();
            if(isVisited[v])
                continue;
            isVisited[v] = true;
            if(v==target)
                return true;
            for (int u: linkedGraph[v])
                bfsQueue.push(u);
        }
        return false;
    }
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target)
    {
        // 使用set以去除平行边
        vector<unordered_set<int> > linkedGraph(n);
        for (const auto &iter : graph)
            linkedGraph[iter[0]].insert(iter[1]);
        vector<bool> isVisited(n);
        for (int i = 0; i < n; i++)
            isVisited[i] = false;
        aim = target;
        dfs(start, linkedGraph, isVisited);
        return isFind;
    }
};

int main()
{
    Solution aSolution;
    unordered_set<int> s;
}