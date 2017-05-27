#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    int score[5];
    int sum_score;
    int num_perfectly;
    int ns;
    Student()
    {
        id=0;sum_score=0;num_perfectly=0;ns=0;
        for(int i=0;i<5;i++)
        {
            score[i] = -2;
        }
    }
};
int comp(Student a,Student b)
{
    if(a.sum_score!=b.sum_score)
    {
        return a.sum_score>b.sum_score;
    }
    if(a.num_perfectly!=b.num_perfectly)
    {
        return a.num_perfectly>b.num_perfectly;
    }
    return a.id<b.id;
}
int main()
{
    int N,K,M;
    int score[5];
    //int id_score[10000][8];
    Student students[10000];
    scanf("%d %d %d",&N,&K,&M);
    for(int i=0;i<N;i++)
    {
        students[i].id = i+1;
    }
    for(int i=0;i<K;i++)
    {
        scanf("%d",&score[i]);
    }
    for(int i=0;i<M;i++)
    {
        int tmp_id,tmp_k,tmp_score;
        scanf("%d %d %d",&tmp_id,&tmp_k,&tmp_score);
        
        if(students[tmp_id-1].score[tmp_k-1]<tmp_score)
        {
            students[tmp_id-1].score[tmp_k-1] = tmp_score;
        }
    }
    for(int i=0;i<N;i++)
    {
        students[i].id = i+1;
        for(int j=0;j<K;j++)
        {
            if(students[i].score[j]>=0)
            {
                students[i].ns=1;
                students[i].sum_score+=students[i].score[j];
            }
            if(students[i].score[j]==score[j])
            {
                students[i].num_perfectly++;
            }
        }
    }
    sort(students,students+N,comp);
    int pre_score = 0;
    int pre_rank = 0;
    for(int i=0;i<N;i++)
    {
        if(students[i].ns == 0)
        {
            break;
        }
        int rank;
        if(pre_score == students[i].sum_score)
        {
            rank = pre_rank;
        }
        else
        {
            rank = i+1;
            pre_rank = i+1;
        }
        printf("%d %05d %d",rank,students[i].id,students[i].sum_score);
        for(int j=0;j<K;j++)
        {
            int tmp_score = students[i].score[j];
            if(tmp_score==-2)
            {
                printf(" -");
            }
            else if(tmp_score== -1)
            {
                printf(" 0");
            }
            else
            {
                printf(" %d",tmp_score);
            }
        }
        printf("\n");
        pre_score = students[i].sum_score;
    }
    return 0;
}