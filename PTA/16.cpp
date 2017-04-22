#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;

double Island_R = 7.5;
int Border = 50;

double CalDistance(pair<int,int> _point1,pair<int,int> _point2)
{
    return sqrt(double((_point1.first-_point2.first)*(_point1.first-_point2.first)+
        (_point1.second-_point2.second)*(_point1.second-_point2.second)));
}
bool Escape(pair<int,int> _point,int _D)
{
    if(abs(_point.first)+_D >= Border || abs(_point.second)+_D >= Border)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    int N,D;
    scanf("%d %d",&N,&D);
    if(Island_R+D>Border)
    {
        printf("Yes");
        return 0;
    }
    vector<pair<int,int> > crocodiles;
    queue<pair<int,int> > q;
    vector<bool> visited;
    pair<int,int> center(0,0);
    for(int i=0;i<N;i++)
    {
        pair<int,int> crocodile;
        scanf("%d %d",&crocodile.first,&crocodile.second);
        crocodiles.push_back(crocodile);
        //double tmp = CalDistance(center,pair<int,int>(3,4));
        if(CalDistance(center,crocodile)<=D+Island_R)
        {
            q.push(crocodile);
            visited.push_back(true);
        }
        else
        {
            visited.push_back(false);
        }
    }
    while(!q.empty())
    {
        pair<int,int> tmp = q.front();
        q.pop();
        if(Escape(tmp,D))
        {
            printf("Yes");
            return 0;
        }
        for(int i=0;i<N;i++)
        {
            if(!visited[i] && CalDistance(tmp,crocodiles[i])<=D)
            {
                q.push(crocodiles[i]);
                visited[i] = true;
            }
        }
    }
    printf("No");
    return 0;
}