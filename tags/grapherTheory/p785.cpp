/// author: CagedBird
/// date: 2020/04/27
/// place: JiangXi
/// description: A code template of leetcode's list graph theory solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void isBipartiteHelper(vector<vector<int>>& graph, vector<int>& visit, bool& isOddCircle, int curVertex, int lastVertx)
    {
        visit[curVertex] = lastVertx<0? -1: visit[lastVertx]-1; // 标记当前深度搜索中访问过
        for (int u: graph[curVertex])
        {
            if(u==lastVertx)  // curVertex -> u, u !-> curVertex
                continue;
            if(isOddCircle)
                return;
            if(visit[u]==0)
                isBipartiteHelper(graph, visit, isOddCircle, u, curVertex);
            else if(visit[u]<0&&(visit[u]-visit[curVertex]+1)%2==1) // 当前环所含有节点的个数为奇数，则isOddCircle置为true
            isOddCircle= true;
        }
        visit[curVertex] = 1; // 标记为之前深度搜索中访问过
    }
    bool isBipartite(vector<vector<int> >& graph)
    {
        vector<int> visit(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++)
        {
            bool isOddCircle = false;
            if(visit[i]==0)
                isBipartiteHelper(graph, visit, isOddCircle, i,-1);
            if(isOddCircle)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution aSolution;
    vector<vector<int> > graph{{3,4,6},{3,6},{3,6},{0,1,2,5},{0,7,8},{3},{0,1,2,7},{4,6},{4},{}};
    cout<<aSolution.isBipartite(graph);
}



