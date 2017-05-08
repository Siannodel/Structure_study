#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define INF 1000000
int main()
{
    int N,M;
    //scanf("%d %d",&N,&M);
    cin>>N>>M;
    int Mat[101][101];
    //初始化Mat
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j)
                Mat[i][j]=0;
            else
                Mat[i][j]=INF;
        }
    }
    //读入数据
    while(M--)
    {
        int v1,v2,route;
        //scanf("%d %d %d",&v1,&v2,&route);
        cin>>v1>>v2>>route;
        Mat[v1][v2] = Mat[v2][v1] = route;
    }
    //
    //Floyd
    for(int n=1;n<=N;n++)
    {
        for(int i=1;i<=N;i++)
        {
                for(int j=1;j<=N;j++)
                {
                    if(Mat[i][j]>Mat[i][n]+Mat[n][j])
                    {
                        Mat[i][j] = Mat[i][n]+Mat[n][j];
                    }
                }
        }
    }
    //寻找动物
    int result;
    int long_result = INF;
    int max_long = 0;
    for(int i=1;i<=N;i++)
    {
        max_long = 0;
        for(int j=1;j<=N;j++)
        {
            if(max_long<Mat[i][j])
                max_long = Mat[i][j];    
        }
        if(max_long < long_result)
        {
            long_result = max_long;
            result = i;
        }
    }
    //输出
    if(long_result == INF)
    {
        cout<<0;
    }
    else
    {
        cout<<result<<" "<<long_result;
    }
    return 0;
}