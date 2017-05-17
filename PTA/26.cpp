#include <stdio.h>
#include <iostream>

using namespace std;
void Swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
//判断两个数组是否相等(大小一定相等)
bool Myequal(int _A[],int _B[],int _N)
{
    for(int i=0;i<_N;i++)
    {
        if(_A[i]!=_B[i])
            return false;
    }
    return true;
}
//插入排序
bool Insertion_Sort(int _A[],int _B[],int _N)
{
    bool flag = false;
    for(int i=1;i<_N;i++)
    {
        int tmp = _A[i];
        int j;
        for(j=i;j>0&&_A[j-1]>tmp;j--)
        {
            _A[j] = _A[j-1];
        }
        _A[j] = tmp;
        if(flag)
        {
            return true;
        }
        if(Myequal(_A,_B,_N))
        {
            flag = true;
        }
    }
    return false;
}
//堆排序
void PrecDown(int _A[],int _N,int _i)
{
    int i = _i+1;
    int parent,child;
    int data = _A[_i];
    for(parent = i;parent*2<=_N;parent=child)
    {
        child = 2*parent;
        if(child<=_N-1 && _A[child]>_A[child-1])
        {
            child++;
        }
        if(data<_A[child-1])
        {
            Swap(_A[parent-1],_A[child-1]);
        }
        else
        {
            break;
        }
    }
    _A[parent-1] = data;
}
bool Heap_Sort(int _A[],int _B[],int _N)
{
    bool flag = false;
    for(int i=_N/2;i>=0;i--)
    {
        PrecDown(_A,_N,i);
    }
    for(int i=_N-1;i>0;i--)
    {
        if(flag)
        {
            return true;
        }
        if(Myequal(_A,_B,_N))
        {
            flag = true;
        }
        Swap(_A[0],_A[i]);
        PrecDown(_A,i,0);
    }
    return false;
}
int main()
{
    int N;
    cin>>N;
    int A1[100];
    int A2[100];
    int B[100];
    for(int i=0;i<N;i++)
    {
        cin>>A1[i];
        A2[i] = A1[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>B[i];
    }
    //判断是否为插入排序
    if(Insertion_Sort(A1,B,N))
    {
        cout<<"Insertion Sort"<<endl;
        cout<<A1[0];
        for(int i=1;i<N;i++)
        {
            cout<<" "<<A1[i];
        }
    }
    else
    {
        if(Heap_Sort(A2,B,N))
        {
            cout<<"Heap Sort"<<endl;
            cout<<A2[0];
            for(int i=1;i<N;i++)
            {
                cout<<" "<<A2[i];
            }
        }
    }
    return 0;
}