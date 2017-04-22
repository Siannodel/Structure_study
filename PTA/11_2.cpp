#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int LeftNodeNum(int _n)
{
    int h = log(_n+1)/log(2);
    int last = _n-(pow(2,h)-1)<pow(2,h-1)?_n-(pow(2,h)-1):pow(2,h-1);
    int leftnode_num = pow(2,h-1)-1+last;

    return leftnode_num;
}
void slove(const vector<int> &_input,vector<int> &_result,int _size,int pre=0, int _n=1)
{
    if(_size == 1)
    {
        _result[_n] = _input[pre];
    }
    if(_size == 0)
        return;

    int leftnodenum = LeftNodeNum(_size);
    int rightnodenum = _size-leftnodenum-1;
    _result[_n] = _input[pre+leftnodenum];
    slove(_input,_result,leftnodenum,pre,2*_n);
    slove(_input,_result,rightnodenum,pre+leftnodenum+1,2*_n+1);
}
int main()
{
    int N;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    vector<int> result(N+1);
    slove(v,result,N);
    cout<<result[1];
    for(int i =2;i<=N;i++)
    {
        cout<<" "<<result[i];
    }
    return 0;
}