/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef priority_queue<string, vector<string>, greater<string> > stringPriQueue;
    // 解决欧拉回路问题的Hierholzer算法
    // 从某一给定的起始点出发
    // 访问该点所有的邻接点，并同时删除这条边
    // 以dfs的方式依次访问该图的所有点
    // 当某点访问结束后，将其逆序放入结果集中（利用栈）
    void dfs(map<string, stringPriQueue>& graph, string vertex,stack<string>& s)
    {
        while (!graph[vertex].empty())
        {
            string linkedVertex = graph[vertex].top();
            graph[vertex].pop();
            dfs(graph, linkedVertex, s);
        }
        s.push(vertex);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        map<string,  stringPriQueue> graph;
        // map.insert(pair<>)
        int length = tickets.size();
        for(int i=0; i< length; i++)
        {
            string s1 = tickets[i][0];
            string s2 = tickets[i][1];
            if(graph.find(s1)==graph.end())
            {
                stringPriQueue priQueue;
                priQueue.push(s2);
                graph.insert(pair<string, stringPriQueue>(s1, priQueue));
            }
            else
            {
                graph[s1].push(s2);
            }
        }
        stack<string> s;
        dfs(graph, "JFK", s);
        vector<string> result;
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

int main()
{
    Solution aSolution;
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    auto result = aSolution.findItinerary(tickets);
    for (auto s: result)
    {
        cout<<s<<" ";
    }
    return 0;   
}