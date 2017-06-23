#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    int sum = A+B;
    bool flag=true;
    deque<int> v;
    if(sum<0)
    {
        flag = false;
        sum = -sum;
    }
    while(sum/1000>0)
    {
        int tmp = sum%1000;
        v.push_front(tmp);
        sum = sum/1000;
    }
    if(!flag)
        printf("-");
    printf("%d",sum);
    for(int i=0;i<v.size();i++)
        printf(",%03d",v[i]);
    
    int a;
    cin>>a;
    return 0;
}