#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int A[100000];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    sort(A,A+N);
    int count = 0;
    while(count<N)
    {
        int age = A[count];
        int num = 1;
        count++;
        while(count<N && A[count]==age)
        {
            num++;
            count++;
        }
        printf("%d:%d\n",age,num);
    }
    return 0;
}