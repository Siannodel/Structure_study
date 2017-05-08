#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int graph[100][100];
    vector<int> earliest(N,-1);
    vector<bool> done(N,false);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            graph[i][j] = -1;
        }
    }
    for(int i=0;i<M;i++)
    {
        int v1,v2,dist;
        cin>>v1>>v2>>dist;
        graph[v1][v2] = dist;
    }
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int j=0;j<N;j++)
        {
            bool can_start = true;
            bool start_point = true;
            int tmp = earliest[j];
            for(int i=0;i<N;i++)
            {
                if(graph[i][j]!=-1)
                {
                    start_point = false;
                    if(earliest[i]!=-1)
                        tmp = tmp>earliest[i]+graph[i][j]?tmp:earliest[i]+graph[i][j];
                    else
                        can_start = false;
                }
            }
            if(start_point&&earliest[j]==-1)
            {
                earliest[j] = 0;
                flag = true;
                continue;
            }
            if(can_start&&earliest[j]!=tmp)
            {
                earliest[j] = tmp;
                flag = true;
            }               
            
        }
    }
    sort(earliest.begin(),earliest.end());
    if(earliest[0]==-1)
        cout<<"Impossible";
    else
        cout<<earliest[N-1];
    return 0;
}