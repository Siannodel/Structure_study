#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int graph[10][10];
int N;
bool Visited[10];
void DFS(int v)
{
    Visited[v] = true;
    printf("%d ",v);
    for(int i =0;i<N;i++)
    {
        if(graph[v][i]==1 && !Visited[i])
        {
            DFS(i);
        }
    }
}
void DFS_print()
{
    for(int i=0;i<N;i++)
    {
        if(!Visited[i])
        {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }
    }
    return;
}
void BFS(int v)
{
    queue<int> q;
    q.push(v);
    Visited[v] = true;
    while(!q.empty())
    {
        int tmp = q.front();
        printf("%d ",tmp);
        q.pop();
        for(int i =0;i<N;i++)
        {
            if(graph[tmp][i]==1 && !Visited[i])
            {
                q.push(i);
                Visited[i] = true;
            }
        }
    }
}
void BFS_print()
{
     for(int i=0;i<N;i++)
    {
        if(!Visited[i])
        {
            printf("{ ");
            BFS(i);
            printf("}\n");
        }
    }
    return;
}
void InitVisit()
{
    for (int i = 0; i < N; i++)
        Visited[i] = false;
}
int main()
{
    int E;
    cin>>N>>E;
    for(int i =0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    DFS_print();
    InitVisit();
    BFS_print();
    return 0;
}