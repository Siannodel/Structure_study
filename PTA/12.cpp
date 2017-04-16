#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void MyPrint(vector<int> _heap,int _i)
{
    int i = _i;
    while(i!=1)
    {
        cout<<_heap[i]<<" ";
        i = i/2;
    }
    cout<<_heap[i]<<endl;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> heap(N+1);
    heap[0] = -20000;
    for(int i=1;i<=N;i++)
    {
        cin>> heap[i];
        int j = i;
        while(j!=0)
        {
            if(heap[j]<heap[j/2])
            {
                int tmp = heap[j/2];
                heap [j/2] = heap[j];
                heap[j] = tmp;
            }
            else
                break;
            j = j/2;
        }
    }
    vector<int> printnums(M);
    for(int i=0;i<M;i++)
    {
        cin>>printnums[i];
    }
    //Print
    for(int i=0;i<M;i++)
    {
        MyPrint(heap,printnums[i]);
    }
    return 0;
}