#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int N;
    int hash_table[1000];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&hash_table[i]);
    }
    int graph[1000][1000];
    int in_degree[1000];
    bool visited[1000];
    for(int i=0;i<N;i++)
    {
        in_degree[i] = 0;
        visited[i] = false;
        for(int j=0;j<N;j++)
        {
            graph[i][j] = -1;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(hash_table[i]==-1)
        {
            visited[i] = true;
            continue;
        }
        int tmp = hash_table[i]%N;
        //if(tmp<=i)
        //{
        //    in_degree[i] = i-tmp;
        //}
        //else
        //{
        //    in_degree[i] = i+N-tmp;
        //}
        int j = tmp;
        while(j!=i)
        {
            graph[j][i] = 1;
            in_degree[i]++;
            j++;
            if(j==N)
            {
                j=0;
            }
        }
    }
    int output[1000];
    int count = 0;
    while(1)
    {
        int min = 1000000;
        int min_i = -1;
        for(int i=0;i<N;i++)
        {
            if(!visited[i] && in_degree[i]==0 && hash_table[i]<min)
            {
                min = hash_table[i];
                min_i = i;
            }
        }
        if(min_i == -1)
            break;
        output[count++] = min;
        visited[min_i] = true;
        for(int j=0;j<N;j++)
        {
            if(graph[min_i][j]==1)
            {
                in_degree[j]--;
            }
        }
    }
    printf("%d",output[0]);
    for(int i=1;i<count;i++)
    {
        printf(" %d",output[i]);
    }
    printf("\n");
    return 0;
}