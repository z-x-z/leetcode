#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

int main()
{
    int maxLength = 20;
    int circle = 10;
    for (int i = 0; i < circle; i++)
    {
        for (int j = 1; j < maxLength; j++)
        {
            int t = maxLength/2*sin(M_PI/maxLength*j);
            cout<<string(maxLength/2,' ')+string(t, '*')<<endl;
        }
        for (int j = 1; j < maxLength; j++)
        {
            int t = -maxLength/2*sin(M_PI+M_PI/maxLength*j);
            cout<<string(maxLength/2-t,' ')+string(t, '*')<<endl;
        }
    }
}