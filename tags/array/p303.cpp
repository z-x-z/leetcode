#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int>& array;
    // 缓存
    // 表示从array[0]~array[i]的和
    // 所以array[i]~array[j]可以使用使用firstToSum[j]-firstToSum[i-1]表示

    vector<int> firstToSum;

    NumArray(vector<int>& nums)
    : array(nums)
    {
        // 可能存在nums的长度为0
        // 所以置一个虚拟的0位于firstToSum[0],其他位置向后移动1位
        firstToSum = vector<int>(nums.size()+1);
        firstToSum[0] = 0;
        for (int i = 0; i < nums.size(); i++)
            firstToSum[i+1]= firstToSum[i]+array[i];
    }


    int sumRange(int i, int j) {
        // firstToSum[j]-firstToSum[i-1]
        // 但其中firstToSum[i-1]可能存在越界（i=0）
        return firstToSum[j+1]- firstToSum[i];
    }
};

int main()
{

}