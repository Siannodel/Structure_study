#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define INF  10000000
int N,M,S,D;
int FindMinDist(vector<vector<pair<int,int> > > _map, vector<int> _dist, vector<bool> _flag)
{
    int min_v;
    int min_dist = INF;
    for(int i=0;i<N;i++)
    {
        if(_flag[i]==false && _dist[i]<min_dist)
        {
            min_dist = _dist[i];
            min_v = i;
        }
    }
    if(min_dist == INF)
    {
        return -1;
    }
    return min_v;
}
int main()
{
    scanf("%d %d %d %d",&N,&M,&S,&D);
    vector<vector<pair<int,int> > > map(N,vector<pair<int,int> >(N,pair<int,int>(INF,0)));
    for(int i=0;i<M;i++)
    {
        int c1,c2;
        pair<int,int> route;
        //cin>>c1>>c2>>route.first>>route.second;
        scanf("%d %d %d %d",&c1,&c2,&route.first,&route.second);
        map[c1][c2] = map[c2][c1] = route;
    }
    vector<int> min_distance(N,INF);
    vector<int> charge(N,0);
    vector<int> path(N,-1);
    vector<bool> collected(N,false);
    min_distance[S] = 0;
    while(1)
    {
        int v = FindMinDist(map,min_distance,collected);
        if(v==-1 || v==D)
            break;
        collected[v] = true;
        for(int i=0;i<N;i++)
        {
            if(collected[i]==false && map[v][i].first<INF)
            {
                if(min_distance[v]+map[v][i].first<min_distance[i]||
                (min_distance[v]+map[v][i].first==min_distance[i] &&
                charge[v]+map[v][i].second<charge[i]))
                {
                    min_distance[i] = min_distance[v]+map[v][i].first;
                    charge[i] = charge[v] + map[v][i].second;
                    path[i] = v;
                }
        
            }
        }
    }
//cout<<min_distance[D]<<" "<<charge[D];
printf("%d %d",min_distance[D],charge[D]);
return 0;
}