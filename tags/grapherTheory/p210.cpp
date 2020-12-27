/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites)
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
        for (const auto& vec: prerequisites)
        {
            indegrees[vec[0]]++;
            isPreRequire[vec[1]].push_back(vec[0]);
        }
        for (int i = 0; i < numCourses; i++)
            if(indegrees[i]==0)
                zeroIndegrees.push(i);
        vector<int> order;
        for (int i = 0; i < numCourses; i++)
        {
            if(zeroIndegrees.empty())
                return vector<int>();
            int v = zeroIndegrees.front();
            order.push_back(v);
            zeroIndegrees.pop();
            for(int i: isPreRequire[v])
            {
                indegrees[i]--;
                if(indegrees[i]==0)
                    zeroIndegrees.push(i);
            }
        }
        return order;
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > prerequisites {{1,0},{2,0},{3,1},{3,2}};
    for (auto i: aSolution.findOrder(4, prerequisites))
    {
        cout<<i<<" ";
    }

}