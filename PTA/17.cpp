#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<list<int> > Network(N+1);
    for(int i=0;i<M;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        Network[v1].push_back(v2);
        Network[v2].push_back(v1);
    }

    for(int i=1;i<=N;i++)
    {
        queue<int> q;
        q.push(i);
        vector<int> visited(N+1,-1);
        visited[i] = 0;
        int level = 0;
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            list<int>::iterator it = Network[tmp].begin();
            while(it!=Network[tmp].end())
            {
                if(visited[*it]==-1)
                {
                    int v = *it;
                    q.push(v);
                    visited[v] = visited[tmp]+1;
                }
                it++;
            }
        }
        int count = 0;
        vector<int>::iterator it_v = visited.begin();
        while(it_v!=visited.end())
        {
            if(*it_v<=6 && *it_v!=-1)
            {
                count++;
            }
            it_v++;
        }
        float rotio = float(count)/float(N)*100;
        printf("%d: %0.2f%%\n",i,rotio);
    }
    return 0;
}