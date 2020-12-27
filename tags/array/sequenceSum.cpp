#include<iostream>
using namespace std;
bool findTheMinSequence(long long N, int L)
{
    bool b = (L%2==1&&N%L==0)||(L%2==0&&N%L==(L/2));
    if(b)
    {
        int firstNum = N/L - L/2;
        if(L%2==0) firstNum++;
        cout<<firstNum;
        for(int i = 1;i< L; i++)
        {
            cout<<" "<<(firstNum+i);
        }
    }
    return b;
}
int main()
{
    long long N;
    int L;
    while (true)
    {
        cin>>N>>L;
        while(!findTheMinSequence(N, L++)) ;
    }
    
    
}