#include<iostream>
using namespace std;
int n;
int* wellCost;
int** pipeCost;
void initParameter()
{
    scanf("%d", &n);
    wellCost = new int[n];
    for (int i = 0; i < n; i++) scanf("%d", &wellCost[i]);
    pipeCost = new int*[n];
    for (int i = 0; i < n; i++)
    {
        pipeCost[i] = new int[n];
        for (int j = 0; j < n; j++) scanf("%d", & pipeCost[i][j]);
    }
}

int main()
{    
    initParameter();
    
}