#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <vector>  
#include <cstring>  

using namespace std;  

const int CITYNUM = 500;  
const int INF = 0x7fffffff;  

int city[CITYNUM];          // 记录各个城市的团队数  
int road[CITYNUM][CITYNUM]={0};  
bool visited[CITYNUM]={false};  
int minLen[CITYNUM]={0};    // 从源城市到达 index 城市的最短路径值  
int sum[CITYNUM]={0};       // 从源城市到达 index 城市，所能召集的最大团队数  
int same[CITYNUM]={0};      // 从源城市到达 index 城市, 具有相同最短的路径个数  

void Dij(int source, int dest, int n)
{
    int i,t,mm,next;
    int count = 0;
    int cur = source;
    sum[cur] = city[cur];
    same[cur] = 1;
    while(count<n-1)
    {
        visited[cur] = true;
        mm=INF;
        for(i=0;i<n;i++)
        {
            if(visited[i]) continue;
            if(road[cur][i])
            {
                t = minLen[cur]+road[cur][i];
                if(t<minLen[i]||minLen[i]==0)
                {
                    minLen[i]=t;
                    same[i]=same[cur];
                    sum[i]=sum[cur]+city[i];
                }
                else if(t==minLen[i])
                {
                    same[i]+=same[cur];
                    if(sum[cur]+city[i]>sum[i])
                        sum[i]=sum[cur]+city[i];
                }
            }
            if(minLen[i]<mm && minLen[i]!=0)
            {
                mm = minLen[i];
                next = i;
            }
        }
        minLen[cur] = mm;
        if(next == dest) break;
        cur = next;
        count++;
    }
    return;
}
int main()
{
    int n,m,sc,dc;
    cin>>n>>m>>sc>>dc;
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
    cout<<same[dc]<<' '<<sum[dc]<<endl;

    int test;
    cin>>test;
    return 0;
}