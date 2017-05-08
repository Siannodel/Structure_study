#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF=0x7fffffff;
const int N = 102;

int graph[N][N];
int in_degree[N];
int out_degree[N];
int vearly[N];
int vlate[N];
int n,m;
int min_time;//最少花费时间
vector<int> v_start;//入度为0的点
vector<int> v_end;//出度为0的点

//求出vearly，并能据此判断是否是合理的调度
bool sol_vearly()
{
    vector<int>::iterator it = v_start.begin();
    vector<bool> vis(n+1,false);
    while(it!=v_start.end())
    {
        queue<int> que;
        que.push(*it);
        vearly[*it] = 0;
        vis[*it] = true;

        while(!que.empty())
        {
            int nowNum = que.front();
            que.pop();
            for(int i=1;i<=n;i++)
            {
                if(graph[nowNum][i]>=0&&!vis[i])
                {
                    in_degree[i]--;
                    vearly[i] = max(vearly[i],vearly[nowNum]+graph[nowNum][i]);
                    if(in_degree[i]==0)
                    {
                        que.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
        ++it;
    }
    min_time = vearly[1];
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
            return false;
        if(vearly[i]>min_time)
        {
            min_time = vearly[i];
        }
    }
    return true;
}
//求事件的最迟发生时间
void solve_vlate()
{
    vector<int>::iterator it = v_end.begin();
    vector<bool> vis(n+1,false);
    while(it!=v_end.end())
    {
        int endP = *it;
        vlate[endP] = min_time;//!!!所有出度为0的时间，其最迟发生时间为最大的ve[]
        queue<int> que;
        que.push(endP);
        vis[endP] = true;
        out_degree[endP] = -1;

        while(!que.empty())
        {
            int nowNum = que.front();
            que.pop();
            for(int i=1;i<=n;i++)
            {
                if(vis[i]||graph[i][nowNum]<0)
                    continue;
                out_degree[i]--;
                vlate[i] = min(vlate[i],vlate[nowNum]-graph[i][nowNum]);
                if(out_degree[i]==0)//!!!出度为0的时候，才算访问完毕 
                {
                    vis[i]=true;
                    que.push(i);
                }
            }
        }
        it++;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    //初始化数据
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            graph[i][j] = -1;
        in_degree[i] = 0;
        out_degree[i] = 0;
        vearly[i] = 0;
        vlate[i] = INF;
    }
    int s,e,c;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&s,&e,&c);
        graph[s][e] = c;
        out_degree[s]++;
        in_degree[e]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(in_degree[i]==0)
            v_start.push_back(i);
        if(out_degree[i]==0)
            v_end.push_back(i);
    }

    if(!sol_vearly())
    {
        printf("0\n");
    }
    else
    {
        solve_vlate();
        printf("%d\n",min_time);
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=1;j--)
            {
                if(graph[i][j]>=0&&vearly[i]==(vlate[j]-graph[i][j]))
                    printf("%d->%d\n",i,j);
            }
        }
    }
    return 0;
}