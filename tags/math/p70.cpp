/// author: CagedBird
/// date: 2020/06/13
/// place: JiangXi
/// description: A code template of leetcode's general tags solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef vector<vector<int> > Matrix;
    void printMatrix(const Matrix& m)
    {
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[0].size(); j++)
            {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }
    Matrix matrixMutipl(const Matrix& m1, const Matrix& m2)
    {
        int rows = m1.size(), cols = m2[0].size();
        Matrix m(rows, vector<int>(cols) ); // 多维向量初始化
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int res= 0;
                for (int k = 0; k < m2.size(); k++)
                    res+= m1[i][k] * m2[k][j];
                m[i][j] = res;
            }
        }
        return m;
    }
    inline Matrix matrixPow2(const Matrix& m)
    {
        return matrixMutipl(m, m);
    }
    Matrix matrixFastPow(const Matrix& matrix, unsigned int pow)
    {
        if(pow==1)
            return matrix;
        else
        {
            if(pow%2==0)
                return matrixPow2(matrixFastPow(matrix, pow/2));
            else
                return matrixMutipl(matrixPow2(matrixFastPow(matrix, pow/2)), matrix);
        }
    }
public:
    int climbStairs(int n)
    {
        if(n==0)
            return 1;
        Matrix M {{1, 1}, {1, 0}};
        // Matrix v{{1}, {0}};
        Matrix Mn = matrixFastPow(M, n);
        printMatrix(Mn);
        return Mn[1][0]+Mn[1][1];
    }
};

int main()
{
    Solution aSolution;
    int n = 1;
    printf("climbStairs(%d): %d", n, aSolution.climbStairs(n));
}