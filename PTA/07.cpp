#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode{
    char lchildren;
    char rchildren;
};
int main()
{
    int N;
    cin>>N;
    TreeNode tree[10];
    bool flag[10]={true,true,true,true,true,true,true,true,true,true};
    for(int i=0;i<N;i++)
    {

        cin>>tree[i].lchildren>>tree[i].rchildren;
        if(tree[i].lchildren!='-')
        {
            flag[int(tree[i].lchildren-'0')] = false;
        }
        if(tree[i].rchildren!='-')
        {
            flag[int(tree[i].rchildren-'0')] = false;
        }
    }
    queue<int> q;
    vector<int> result;
    for(int i=0;i<N;i++)
    {
        if(flag[i])
        {
            q.push(i);
            break;
        }
    }
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if(tree[tmp].lchildren=='-' && tree[tmp].rchildren=='-')
        {
            result.push_back(tmp);
            continue;
        }
        if(tree[tmp].lchildren!='-')
            q.push(int(tree[tmp].lchildren-'0'));
        if(tree[tmp].rchildren!='-')
            q.push(int(tree[tmp].rchildren-'0'));
    }

    for(int i=0;i<result.size();i++)
    {
        if(i==0)
            cout<<result[i];
        else
            cout<<" "<<result[i];
    }
    return 0;
}