/// author: CagedBird
/// date: 2020/02/27
/// place: JiangXi, ShangRao
/// description: A code template of leetcode's dynamic programing solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int max(int a, int b) {return a > b ? a : b;}
    int min(int a, int b) {return a < b ? a : b;}
    // K: eggs, N: buildings
    int superEggDrop(int K, int N) 
    {
        int M[K+1][N+1];
        // 0, 1层楼
        for (int i = 1; i <= K; i++) 
        {
            M[i][0] = 0;
            M[i][1] = 1;
        }
        // 1个鸡蛋
        for (int i = 1; i <= N; i++) 
        {
            M[0][1] = 0;
            M[1][i] = i;
        }
        for (int k = 2; k <= K; k++)
        {
            for(int n = 2; n <= N; n++)
            {
                // min ( max(M[k-1][i-1]递增, M[k][n-i])递减)
                // 使用二分法查找 i 
                int l = 1, r = n;
                do
                {
                    int m = (l+r)/2;
                    if(M[k-1][m-1]<M[k][n-m]) l = m;
                    else r = m;
                }while (l+1<r);
                M[k][n] = 1 + min(max(M[k-1][l-1], M[k][n-l]), max(M[k-1][r-1], M[k][n-r]));
            }
        }
        return M[K][N];
    }
};

int main()
{
    Solution aSolution;
    int k, n;
    printf("Input K, N\n:");
    while (scanf("%d %d", &k, &n))
    {
        printf("superEggDrop(%d, %d) is %d\n", k, n, aSolution.superEggDrop(k, n));
        printf("Input K, N\n:");
    }
    
    
    
}