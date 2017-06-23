#include <stdio.h>
#include <iostream>

using namespace std;

const int INF=0x7fffffff;
const int MAX_CITY_NUM=500;
int road[MAX_CITY_NUM][MAX_CITY_NUM];
int city[MAX_CITY_NUM];
bool visited[MAX_CITY_NUM];
int dist[MAX_CITY_NUM];
int max_rescue[MAX_CITY_NUM];
int same_num[MAX_CITY_NUM];

void Dij(int start,int end,int n)
{
    //max_rescue[start] = city[start];
    same_num[start] = 1;
    dist[start] = 0;
    max_rescue[start] = city[start];
    int now,next,min_dist;
    now = start;
    while(true)
    {
        visited[now]=true;
        min_dist = INF;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                continue;
            if(road[now][i])
            {
                int d = dist[now]+road[now][i];
                if(dist[i]>d)
                {
                    dist[i] = d;
                    same_num[i] = same_num[now];
                    max_rescue[i] = max_rescue[now]+city[i];
                }
                else if(dist[i]==d)
                {
                    same_num[i] += same_num[now];
                    if(max_rescue[i]<max_rescue[now]+city[i])
                    {
                        max_rescue[i] = max_rescue[now]+city[i];
                    }
                }
            }

            if(dist[i]<min_dist)
            {
                min_dist = dist[i];
                next = i;
            }
        }
        if(next == end)
            break;
        now = next;
    }
    return;
}
int main()
{
    int n,m,sc,dc;
    cin>>n>>m>>sc>>dc;
    //初始化
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dist[i] = INF;
        for(int j=0;j<n;j++)
        {
            road[i][j]=0;
        }
    }
    int i;
    for(i=0;i<n;i++)cin>>city[i];
    int c1,c2;
    for(i=0;i<m;i++)
    {
        cin>>c1>>c2;
        cin>>road[c1][c2];
        road[c2][c1]=road[c1][c2];
    }
    
    Dij(sc,dc,n);
    cout<<same_num[dc]<<' '<<max_rescue[dc]<<endl;

    int test;
    cin>>test;
    return 0;
}
