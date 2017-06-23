#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N,M;
    vector<int> childs[100];
    int level[100];
    int result[100];
    int max_level = 0;
    for(int i=0;i<100;i++)
    {
        level[i]=0;
        result[i]=0;
    }
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int ID,K;
        cin>>ID>>K;
        for(int j=0;j<K;j++)
        {
            int child_ID;
            cin>>child_ID;
            childs[ID].push_back(child_ID);
        }
    }
    queue<int> q;
    q.push(1);
    level[1] = 1;
    max_level = 1;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        if(childs[parent].empty())
        {
            result[level[parent]]++;
            continue;
        }
        for(int i=0;i<childs[parent].size();i++)
        {
            level[childs[parent][i]]=level[parent]+1;
            if(max_level<level[childs[parent][i]])
                max_level=level[childs[parent][i]];
            q.push(childs[parent][i]);
        }
    }
    cout<<result[1];
    for(int i=2;i<=max_level;i++)
    {
        cout<<" "<<result[i];
    }
    int test;
    cin>>test;
    return 0;
}