/// author: CagedBird
/// date: 2020/04/27
/// place: JiangXi
/// description: A code template of leetcode's list graph theory solution

#include<bits/stdc++.h>
using namespace std;

#define INFINITE INT_MAX
class Solution
{
public:
    vector<vector<string> > bfsHelper(const vector<vector<int> >& pvs, const vector<string>& wordList,
    const int startVertex, const int vertex)
    {
        vector<vector<string> > result;
        if(vertex==startVertex)
        {
            result.push_back(vector<string>{wordList[vertex]});
        }
        else
        {
            for (auto pv: pvs[vertex])
            {
                auto arrs = bfsHelper(pvs, wordList,startVertex, pv);
                for (auto& arr: arrs)
                {
                    arr.push_back(wordList[vertex]);
                    result.push_back(arr);
                }
            }
        }
        return result;
    }
    // 获取最短的从startVertex到endVertex的路径
    void bfs(const vector<vector<int> > &graph, const vector<string>& wordList ,
    const int startVertex, const int endVertex, vector<vector<string> >& ans)
    {
        queue<int> vertexQueue;
        vector<vector<int> > pvs(graph.size());
        // vector<vector<int> > nvs(graph.size());
        vertexQueue.push(startVertex);
        vector<int> visitedLevel(graph.size(), INT_MAX);
        int level = 1;
        visitedLevel[startVertex] = level;
        while (!vertexQueue.empty())
        {
            int queueSize = vertexQueue.size();
            for (int i = 0; i < queueSize; i++)
            {
                int vertex = vertexQueue.front();
                vertexQueue.pop();
                if(vertex!=endVertex)
                {
                    for (auto v: graph[vertex])
                    {
                        // 只有visitedLevel小于等于当前level的节点才能访问
                        if(visitedLevel[v]>level)
                        {
                            if(visitedLevel[v]!=level+1)
                                vertexQueue.push(v);
                            visitedLevel[v] = level+1;
                            pvs[v].push_back(vertex);
                            // nvs[vertex].push_back(vertex);
                        }
                    }
                }
            }
            level++;
        }
        ans = bfsHelper(pvs, wordList, startVertex, endVertex);
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        int length = wordList.size();
        int beginVertex= length;
        int endVertex= -1;
        // 其中beginWord与endWord可能是wordList中的一员也可能都不是。
        for (int i=0; i<length; i++)
        {
            const string& wordI = wordList[i];
            if(wordI == beginWord)
                beginVertex = i;
            else if(wordI == endWord)
                endVertex = i;
        }
        // 其中endWord必须是wordList其中的一员，否则直接返回空集合。
        if(endVertex==-1)
            return vector<vector<string> >();
        if(beginVertex == length)
        {
            wordList.push_back(beginWord);
        }
        // 真实的vertexNum
        length = wordList.size();
        // 构建单词与其之间联系所构成的图
        vector<vector<int> > wordGraph(length);
        for (int i=0; i< length; i++)
        {
            const string& wordI = wordList[i];
            for (int j = i+1; j < length; j++)
            {
                const string& wordJ = wordList[j];
                if(wordI.size()!=wordJ.size())
                    continue;
                int diffCount = 0;
                for (int k = 0; k < wordI.size(); k++)
                {
                    if(wordI[k]!=wordJ[k])
                        diffCount++;
                    if(diffCount>1)
                        break;
                }
                if(diffCount==1)
                {
                    // 无向图
                    wordGraph[i].push_back(j);
                    wordGraph[j].push_back(i);
                }
            }
        }
        // 单源无权无向最短路径 BFS方法
        vector<vector<string> > ans;
        bfs(wordGraph, wordList, beginVertex, endVertex, ans);
        return ans;
    }
};

int main()
{
    Solution aSolution;
    /*
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]
     */
    string beginWord = "red";
    string endWord = "tax";
    vector<string> wordList {"ted","tex","red","tax","tad","den","rex","pee"};
    auto ladders = aSolution.findLadders(beginWord, endWord, wordList);
    for (auto& ladder: ladders)
    {
        for (string& word: ladder)
        {
            cout<<word<<" ";
        }
        cout<<endl;
    }

}

/*

 */
