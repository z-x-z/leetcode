/// author: CagedBird
/// date: 2020/04/27
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfsIsCircle(int vertex, const vector<vector<int> >& isPreRequisites, vector<int>& visitState)
    {
        // 若之前的dfs过程已经访问过该节点，则无须访问（说明目前为止没有圈）
        if(visitState[vertex]==-1)
            return false;
        // 若此次dfs过程访问过该节点，则说明存在圈
        if(visitState[vertex]==1)
            return true;
        visitState[vertex] = 1;
        for (auto i: isPreRequisites[vertex])
            if(dfsIsCircle(i, isPreRequisites, visitState))
                return true;
        // 结束该节点的访问时将该节点的访问状态置为之前已访问
        visitState[vertex] = -1;
        return false;
    }
    bool canFinishDFS(int numCourses, vector<vector<int> >& prerequisites)
    {
        vector<vector<int> > isPreRequisites;
        // 0-未访问、1-被当前dfs过程所访问、-1被之前的dfs过程所访问
        vector<int> visitState(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
            isPreRequisites.push_back(vector<int>());
            
        for (const auto& vec: prerequisites)
            isPreRequisites[vec[0]].push_back(vec[1]);
        
        for (int i=0;i<numCourses;i++)
        {
            if(dfsIsCircle(i, isPreRequisites, visitState))
                return false;
        }
        return true;
    }

    // BFS
    bool canFinishTopology(int numCourses, vector<vector<int> >& prerequisites) 
    {    
        queue<int> zeroIndegrees;
        int indegrees[numCourses];
        vector<vector<int> > isPreRequire(numCourses);
        vector<int> tmp;
        for (int i = 0; i < numCourses; i++)
        {
            indegrees[i] = 0;
            isPreRequire[i] = tmp;
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indegrees[prerequisites[i][1]]++;
            isPreRequire[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++)
            if(indegrees[i]==0)
                zeroIndegrees.push(i);

        for (int i = 0; i < numCourses; i++)
        {
            if(zeroIndegrees.empty())
                return false;
            int v = zeroIndegrees.front();
            zeroIndegrees.pop();
            for(int i: isPreRequire[v])
            {
                indegrees[i]--;
                if(indegrees[i]==0)
                    zeroIndegrees.push(i);
            }
        }
        return true;
    }
};

int main()
{
    Solution aSolution;
    
}