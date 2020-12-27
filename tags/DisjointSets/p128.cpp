/// author: CagedBird
/// date: 2020/03/12
/// place: JiangXi
/// description: A code template of leetcode's Disjoint Sets solution

#include<bits/stdc++.h>
using namespace std;

typedef int setType;
typedef int elementType;

struct unionFindSet
{
    setType* disjSet;
    int _numSets;

    unionFindSet(int numSet)
    {
        disjSet = new setType[numSet+1];
        _numSets = numSet;
        for (int i = 1; i <= numSet; i++)
        {
            disjSet[i] = -1;
        }
    }

    setType Find(elementType x)
    {
        if(disjSet[x]<=0) return x;
        // 路径压缩
        else return disjSet[x] = Find(disjSet[x]);
    }

    void UnionBySize(setType r1, setType r2)
    {
        // r1集合个数大于r2
        if(disjSet[r1]<disjSet[r2])
        {
            int tmp = r1;
            r1 = r2;
            r2 = tmp;
        }
        //把r1插入到r2中，并更新r2的个数为r1、若r2个数之和
        disjSet[r2] += disjSet[r1];
        disjSet[r1] = r2;
    }

    int getMaxSetSize()
    {
        int maxSize = 0;
        for (int i = 1; i <= _numSets; i++)
            if(-disjSet[i] > maxSize) 
                maxSize = -disjSet[i];
        return maxSize;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, unsigned int> numMap;
        unionFindSet myUFSet(nums.size());
        for (int i = 1, len = nums.size(); i <= len; i++)
        {
            int x = nums[i-1];
            // 以第一次的数为标准
            if(numMap.find(x) != numMap.end()) continue;
            numMap[x] = i;
            if(numMap.find(x-1) != numMap.end()) myUFSet.UnionBySize(myUFSet.Find(i), myUFSet.Find(numMap[x-1]));
            if(numMap.find(x+1) != numMap.end()) myUFSet.UnionBySize(myUFSet.Find(i), myUFSet.Find(numMap[x+1]));
        }
        return myUFSet.getMaxSetSize();
    }
};

int main()
{
    Solution aSolution;
    vector<int> nums {1, 2, 0, 1};
    cout<<aSolution.longestConsecutive(nums);
}













