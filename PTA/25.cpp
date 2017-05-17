#include <stdio.h>
#include <iostream>

using namespace std;
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
//归并排序
void Merge(int _A[],int _tmpA[],int _L,int _R, int _R_end)
{
    int p1 = _L;
    int p2 = _R;
    int p3 = _L;
    int end1 = _R-1;
    int end2 = _R_end;
    while(p1<=end1&&p2<=end2)
    {
        if(_A[p1]<=_A[p2])
        {
            _tmpA[p3++]=_A[p1++];
        }
        else
        {
            _tmpA[p3++]=_A[p2++];
        }
    }
    while(p1<=end1)
    {
        _tmpA[p3++]=_A[p1++];
    }
    while(p2<=end2)
    {
        _tmpA[p3++]=_A[p2++];
    }
}
void Merge_Pass(int _A[],int _tmpA[],int _N,int _length)
{
    int i;
    for(i=0;i+2*_length<_N;i+=2*_length)
    {
        Merge(_A,_tmpA,i,i+_length,i+2*_length-1);//注意 要减1
    }
    if(i+_length<_N)
    {
        Merge(_A,_tmpA,i,i+_length,_N-1);
    }
    else
    {
        for(;i<_N;i++)
        {
            _tmpA[i]=_A[i];
        }
    }
}
bool Merge_Sort(int _A[],int _B[],int _N)
{
    int *tmpA = new int[_N];
    if(tmpA!=NULL)
    {
        int length = 1;
        bool flag = false;
        while(length<_N)
        {
            Merge_Pass(_A,tmpA,_N,length);
            if(flag)
            {
                for(int i=0;i<_N;i++)
                {
                    _A[i] = tmpA[i];
                }
                return true;
            }
            if(Myequal(tmpA,_B,_N))
            {
                flag = true;
            }
            length*=2;
            Merge_Pass(tmpA,_A,_N,length);
            if(flag)
            {
                return true;
            }
            if(Myequal(_A,_B,_N))
            {
                flag = true;
            }
            length*=2;
        }
        delete [] tmpA;
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
        if(Merge_Sort(A2,B,N))
        {
            cout<<"Merge Sort"<<endl;
            cout<<A2[0];
            for(int i=1;i<N;i++)
            {
                cout<<" "<<A2[i];
            }
        }
    }
    //判断是否为归并排序
    return 0;
}