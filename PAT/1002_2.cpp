#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    double a[1001];
    int num=0;
    for(int i=0;i<1001;i++)
    {
        a[i]=0;
    }
    int k;
    scanf("%d",&k);
    int tmp_n;
    double tmp_a;
    for(int i=0;i<k;i++)
    {
        scanf("%d %lf",&tmp_n,&tmp_a);
        a[tmp_n]=tmp_a;
        num++;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d %lf",&tmp_n,&tmp_a);
        if(a[tmp_n]==0)
            num++;
        a[tmp_n]+=tmp_a;
        if(a[tmp_n]==0)
            num--;
    }
    printf("%d",num);
    for(int i=1000;i>=0;i--)
    {
        if(a[i]!=0)
        {
            printf(" %d %.1lf",i,a[i]);
        }
    }
    int test;
    cin>>test;
    return 0;
}