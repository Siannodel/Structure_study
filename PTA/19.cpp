#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Site{
    int x;
    int y;
    int pre;
    int count;
    int jump;
};
double caldistance(Site _v1, Site _v2)
{
    return sqrt(pow(double(_v1.x-_v2.x),2)+pow(double(_v1.y-_v2.y),2));
}
int main()
{
    int N,D;
    double R = 7.5;
    cin>>N>>D;
    if(D>=50)
    {
        cout<<1;
    }
    vector<Site> coordinates;
    queue<Site> q;
    Site center{0,0,-2,-1,0};
    for(int i=0;i<N;i++)
    {
        Site coordinate{0,0,-2,0,0};
        cin>>coordinate.x>>coordinate.y;
        coordinate.count = i;
        if(caldistance(center,coordinate)<=D+R)
        {
            coordinate.pre = -1;
            coordinate.jump = 1;
            q.push(coordinate);
        }
        coordinates.push_back(coordinate);
    }
    int route = -1;
    while(!q.empty())
    {
        Site coordinate = q.front();
        q.pop();
        if(coordinate.x+D>=50 || coordinate.y+D>=50)
        {
            route = coordinate.count;
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(coordinates[i].pre==-2 && caldistance(coordinate,coordinates[i])<=D)
            {
                coordinates[i].pre = coordinate.count;
                coordinates[i].jump = coordinate.jump+1;
                q.push(coordinates[i]);
            }
        }
    }
    if(route == -1)
    {
        cout<<0;
        return 0;
    }
    vector<Site> routes; 
    while(route != -1)
    {
        Site tmp = coordinates[route];
        routes.push_back(tmp);
        route = tmp.pre;
    }
    cout<<routes.size()+1<<endl;
    for(int i=routes.size()-1;i>=0;i--)
    {
        cout<<routes[i].x<<" "<<routes[i].y<<endl;
    }
    return 0;
}