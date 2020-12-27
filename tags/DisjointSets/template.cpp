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

    unionFindSet(int numSet)
    {
        disjSet = new setType[numSet+1];
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

    void UnionByHeight(setType r1, setType r2)
    {
        // r1比r2高度更高，r2插入到r1中，r1树高度不变
        if(disjSet[r1]<disjSet[r2]) disjSet[r2] = r1;
        // 其他情况一律r1插入到r2中
        else 
        {
            // 若两者高度一样，则此时r2树高度加1
            if(disjSet[r1] == disjSet[r2]) disjSet[r2] --;
            disjSet[r1] = r2;
        }
        
    }
};

class Solution {
public:
    
};

int main()
{
    Solution aSolution;
    
}













