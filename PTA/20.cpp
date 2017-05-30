#include <stdio.h>
#include <iostream>

using namespace std;
int N,M,S,D;
#define INF  10000000
struct Route{
    int dist;
    int charge;
};
int FindMinDist(Route _graph[500][500], int _dist[], bool _book[])
{
    int minV,V;
    int minDist = INF;
    for(V=0;V<N;V++)
    {
        if(_book[V]==false && _dist[V]<minDist)
        {
            minDist = _dist[V];
            minV = V;
        }
    }
    if(minDist<INF)
        return minV;
    else
        return -1;
}
int main()
{
    scanf("%d %d %d %d",&N,&M,&S,&D);
    Route graph[500][500];
    int dist[500];
    int charge[500];
    bool book[500];
    //初始化
    for(int i=0;i<N;i++)
    {
        dist[i] = INF;
        charge[i] = 0;
        book[i] = false;
        for(int j=0;j<N;j++)
        {
            graph[i][j].dist = INF;
        }
    }
    //构造图
    for(int i=0;i<M;i++)
    {
        Route tmp;
        int c1,c2;
        scanf("%d %d %d %d",&c1,&c2,&tmp.dist,&tmp.charge);
        graph[c1][c2] = graph[c2][c1] = tmp;
    }
    dist[S] = 0;
    charge[S] = 0;
    book[S] = true;
    //
    while(1)
    {
        int V = FindMinDist(graph,dist,book);
        if(V==-1)
            break;
        book[V]=true;
        for(int W = 0;W<N;W++)
        {
            if(book[W]==false && graph[V][W].dist<INF)
            {
                
            }
        }
    }
    return 0;
}