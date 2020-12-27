#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int> > matrix;
    int m, n;
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        matrix.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            matrix[i].push_back(x);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if(i!=0)
            cout<<endl;
        int maxValue = matrix[i][0];
        for (int j = 1; j < n; j++)
        {
            if(matrix[i][j]>maxValue)
                maxValue = matrix[i][j];
        }
        cout<<maxValue;
    }



}