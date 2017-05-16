#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_NUM 100000
void Swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
//冒泡排序
void Bubble_Sort(int _A[],int _N)
{
    for(int i=_N-1;i>=0;i--)
    {
        bool flag = false;
        for(int j=0;j<i;j++)//注意！！！
        {
            if(_A[j]>_A[j+1])
            {
                int tmp = _A[j+1];
                _A[j+1] = _A[j];
                _A[j] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}
//简单插入排序
void Insertion_Sort(int _A[],int _N)
{
    for(int i=1;i<_N;i++)
    {
        int tmp = _A[i];
        int j = i;
        for(;j>0 && _A[j-1]>tmp;j--)
        {
            _A[j] = _A[j-1];
        }
        _A[j] = tmp;
    }
}
//希尔排序
//增量序列
int Sedgewick(int _delta[],int _N)
{
    int i=0;
    int count = 0;
    while(true)
    {
        int tmp = 9*pow(4,i)-9*pow(2,i)+1;
        int tmp2 = pow(4,i)-3*pow(2,i)+1;
        if(tmp2<_N)
        {
            _delta[count]=tmp2;
            count++;
        }
        else
        {
            break;
        }
        if(tmp<_N)
        {
            _delta[count]=tmp;
            count++;
        }
        else
        {
            break;
        }
        i++;
    }
    return count;
}
void Shell_Sort(int _A[],int _N)
{
    //增量序列
    int delta[14] = {1,5,19,41,109,209,505,929,2161,3905,8929,16001,36289,MAX_NUM+1};
    int delta_N = 0;
    while(delta[delta_N+1]<_N)
    {
        delta_N++;
    }
    for(int d=delta_N;d>=0;d--)
    {
        int tmp_delta = delta[d];
        //里面就是个插入排序
        for(int i=tmp_delta;i<_N;i++)
        {
            int tmp = _A[i];
            int j;
            for(j=i;j>=tmp_delta&&_A[j-tmp_delta]>tmp;j-=tmp_delta)
            {
                _A[j] = _A[j-tmp_delta];
            }
            _A[j] = tmp;
        }
    }
}
//选择排序
void Selection_Sort(int _A[],int _N)
{
    for(int i=0;i<_N;i++)
    {
        int min = _A[i];
        int min_n = i;
        for(int j=i;j<_N;j++)
        {
            if(_A[j]<min)
            {
                 min = _A[j];
                 min_n = j;
            }
        }
        if(min_n!=i)
        {
            _A[min_n] = _A[i];
            _A[i] = min;
        }
    }
}
//堆排序 需要注意的一点是，在构建堆的时候 起始下标为1，
void PercDown(int _A[],int _i,int _N)
{
    int Parent,Child;
    int data = _A[_i];
    for(Parent = _i+1;Parent*2<=_N;Parent = Child)
    {
        Child = Parent*2;
        if((Child-1<_N-1)&&(_A[Child-1]<_A[Child]))
            Child++;
        if(data<_A[Child-1])
        {
            _A[Parent-1] = _A[Child-1];
        }
        else
            break;
    }
    _A[Parent-1] = data;
}
void Heap_Sort(int _A[],int _N)
{
    for(int i=_N/2;i>=0;i--)
    {
        PercDown(_A,i,_N);
    }
    for(int n=_N-1;n>0;n--)
    {

        int tmp = _A[0];
        _A[0] = _A[n];
        _A[n] = tmp;
        PercDown(_A,0,n);
    }
}
//归并排序
//合并
void Merge(int _A[],int _TmpA[],int _L,int _R,int _R_end)
{
    int end1 = _R-1;
    int end2 = _R_end;
    int p1 = _L;
    int p2 = _R;
    int p3 = _L;
    while(p1<=end1 && p2<=end2)
    {
        if(_A[p1]>_A[p2])
        {
            _TmpA[p3++] = _A[p2++];
        }
        else
        {
            _TmpA[p3++] = _A[p1++];
        }
    }
    while(p1<=end1)
    {
        _TmpA[p3++] = _A[p1++];
    }
    while(p2<=end2)
    {
        _TmpA[p3++] = _A[p2++];
    }
    //for(int i=_L;i<=_R_end;i++)
    //{
        //_A[i] = _TmpA[i]; 
    //}
}
//归并
void Merge_Pass(int _A[],int _TmpA[],int _N,int _length)
{
    int i;
    for(i=0;i<_N-2*_length;i+=2*_length)
    {
        Merge(_A,_TmpA,i,i+_length,i+2*_length-1);
    }
    if(i+_length<_N)
    {
        Merge(_A,_TmpA,i,i+_length,_N-1);
    }
    else
    {
        for(int j=i;j<_N;j++)
        {
            _TmpA[j] = _A[j];
        }
    }
}
void Merge_Sort(int _A[],int _N)
{
    int length = 1;
    int *TmpA;
    TmpA = new int[_N];
    if(TmpA!=NULL)
    {
        while(length<_N)
        {
            Merge_Pass(_A,TmpA,_N,length);
            length *=2;
            Merge_Pass(TmpA,_A,_N,length);
            length *=2;       
        }
        delete [] TmpA;
    }
}
//快速排序
//选择主元
int Median(int _A[],int _Left,int _Right)
{
    int Center = (_Left+_Right)/2;
    if(_A[_Left]>_A[Center])
        Swap(_A[_Left],_A[Center]);
    if(_A[_Left]>_A[_Right])
        Swap(_A[_Left],_A[_Right]);
    if(_A[Center]>_A[_Right])
        Swap(_A[Center],_A[_Right]);
    Swap(_A[Center],_A[_Right-1]);
    return _A[_Right-1];
}
void QuickSort(int _A[],int _Left,int _Right)
{
    if(_Right-_Left>=100)
    {
        int Pivot = Median(_A,_Left,_Right);
        int i = _Left;
        int j = _Right-1;
        for(;;)
        {
            while(_A[++i]<Pivot){}
            while(_A[--j]>Pivot){}
            if(i<j)
                Swap(_A[i],_A[j]);
            else
                break;
        }
        Swap(_A[i],_A[_Right-1]);
        QuickSort(_A,_Left,i-1);
        QuickSort(_A,i+1,_Right);
    }
    else
    {
        Insertion_Sort(_A+_Left,_Right-_Left+1);
    }
}
//接口
void Quick_Sort(int _A[],int _N)
{
    QuickSort(_A,0,_N-1);
}
int main()
{
    int N;
    int A[MAX_NUM];
    //输入
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    //排序
    Quick_Sort(A,N);
    //输出
    printf("%d",A[0]);
    for(int i=1;i<N;i++)
    {
        printf(" %d",A[i]);
    }
    printf("\n");
    return 0;
}