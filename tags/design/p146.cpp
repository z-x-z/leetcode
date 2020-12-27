/// author: CagedBird
/// date: 2020/03/28
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
#include<list>
#include<unordered_map>
using namespace std;

// Least Recent Cache
class LRUCache
{
    struct DataNode
    {
        int key;
        int value;
        DataNode* last;
        DataNode* next;
        DataNode(int _key, int _value)
        : key(_key), value(_value), last(nullptr), next(nullptr) {}
        static void removeFromList(DataNode* node)
        {
            if(!node)
                return;
            DataNode* nn = node->next;
            DataNode* nl = node->last;
            nn->last = nl;
            nl->next = nn;
            node->next = node->last = nullptr;
        }
        static void insertNextTo(DataNode* node, DataNode* head)
        {
            DataNode* headNext = head->next;
            head->next = node;
            node->last = head;
            if(!headNext)
                headNext = head;
            node->next = headNext;
            headNext->last = node;
        }
    };
    DataNode* nodeHead;
    int currentSize;
    int _capacity;
    unordered_map<int, DataNode*> keyToNodeMap;
    // 缓存node所表示的数据
    int cacheData(DataNode* node)
    {
        // 将node节点
        DataNode::removeFromList(node);
        DataNode::insertNextTo(node, nodeHead);
        return node->value;
    }

public:
    LRUCache(int capacity) {
        nodeHead = new DataNode(-1, -1);
        currentSize = 0;
        _capacity = capacity;
    }

    int get(int key)
    {
        if(keyToNodeMap.find(key)!=keyToNodeMap.end())
            return cacheData(keyToNodeMap[key]);
        else
            return -1;
    }

    void put(int key, int value)
    {
        DataNode* node;
        if(keyToNodeMap.find(key)!=keyToNodeMap.end())
        {
            node = keyToNodeMap[key];
            DataNode::removeFromList(node);
            node->value = value;
        }
        else
        {
            node = new DataNode(key, value);
            currentSize++;
        }
        DataNode::insertNextTo(node, nodeHead);
        if(currentSize>_capacity)
        {
            DataNode* headLast = nodeHead->last;
            DataNode::removeFromList(headLast);
            keyToNodeMap.erase(headLast->key);
            delete headLast;
            currentSize--;
        }

        keyToNodeMap[key] = node;
    }
};

class LRUCache1
{
private:
    int currentSize;
    int capicity;
    typedef pair<int, int> Node;
    typedef list<Node>::iterator Position;
    list<Node> nodeList;
    // map: key所映射的是链表的迭代器
    unordered_map<int, Position> keyToNode;

public:
    LRUCache1(int _capacity)
    {
        this->capicity = _capacity;
    }

    int get(int key)
    {
        if(keyToNode.find(key)!=keyToNode.end())
        {
            Position p = keyToNode[key];
            nodeList.erase(p);
            nodeList.push_front(*p);
            keyToNode[key] = nodeList.begin();
            return p->second;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        Node node;
        // 如果key已经在缓存中，则替换其value
        if(keyToNode.find(key)!=keyToNode.end())
        {
            Position p = keyToNode[key];
            nodeList.erase(p);
            p->second = value;
            node = *p;
        }
        else
        {
            node = make_pair(key, value);
            currentSize++;
        }
        nodeList.push_front(node);
        if(currentSize>capicity)
        {
            // 从map中删除其key
            keyToNode.erase(nodeList.back().first);
            // 从list中删除末尾的节点
            nodeList.pop_back();
            currentSize--;
        }

        keyToNode[key] = nodeList.begin();
    }
};
// 获取指向链表最后一个元素的迭代器：(nums.end()-1)
   // 指向第一个元素的迭代器：(nums.begin())
int main()
{
    auto cache = new LRUCache1(2);
    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(2, 2);
    cache->put(2, 4);
    printf("%d\n", cache->get(1));
    printf("%d\n", cache->get(2));





}