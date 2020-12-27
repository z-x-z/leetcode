/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct VertexNode;
    typedef VertexNode* VertexList;
    struct VertexNode
    {
        int id;
        string inAirpot;
        string outAirport;
        VertexNode* next;
        VertexNode()
        {}
        VertexNode(int _id, string _inAirpot, string _outAirport)
        :id(_id), inAirpot(_inAirpot), outAirport(_outAirport),next(nullptr){}
        VertexNode(int _id, string _outAirport)
        :id(_id), outAirport(_outAirport),next(nullptr){}
        void insert(int _id, string _outAirport)
        {
            VertexNode* node = this;
            // 按其字典序插入
            while (node->next!= nullptr&&node->next->outAirport<_outAirport)
                node = node->next;
            VertexNode* tmp = node->next;
            node->next = new VertexNode(_id, _outAirport);
            node->next->next = tmp;
        }
    };
    int vertexNum;
    bool* isVisited;
    vector<string> result;
    bool bfsHelper(VertexList* vertexLists, int vertex, int index)
    {
        isVisited[vertex] = true;
        result[index] = vertexLists[vertex]->outAirport;
        if(index==vertexNum)
            return true;
        VertexNode* node = vertexLists[vertex]->next;
        while (node)
        {
            if(!isVisited[node->id]&&bfsHelper(vertexLists, node->id, index+1))
                return true;
            node = node->next;
        }
        isVisited[vertex] = false;
        return false;
    }

    typedef pair<string, int> myPair;
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        int length = tickets.size();
        VertexList VertexLists[length];
        int id = 0;
        priority_queue<myPair, vector<myPair>, greater<myPair> > priQueue;
        for (int i = 0; i < length; i++)
        {
            string inAirport = tickets[i][0];
            string outAirport = tickets[i][1];
            if(inAirport=="JFK")
                priQueue.push(myPair{outAirport, i});
            VertexLists[i] = new VertexNode(i, inAirport, outAirport);
        }
        for (int i = 0; i < length; i++)
        {
            string& outAirport = VertexLists[i]->outAirport;
            for (int j = 0; j < length; j++)
                if(VertexLists[j]->inAirpot==outAirport)
                    VertexLists[i]->insert(j, VertexLists[j]->outAirport);
        }
        vertexNum = length;
        result = vector<string>(vertexNum+1);
        isVisited = new bool[vertexNum];
        memset(isVisited, 0, vertexNum);
        // BFS
        while(!priQueue.empty())
        {
            int i = priQueue.top().second;
            priQueue.pop();
            result[0] = VertexLists[i]->inAirpot;
            if(bfsHelper(VertexLists, i, 1))
                break;
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
    // 优先队列默认为大顶堆，转入greater后可改变其为小顶堆
    // priority_queue<pair<string, int>, vector<pair<string, int> >, greater<pair<string, int> > > myQueue;
    return 0;   
}