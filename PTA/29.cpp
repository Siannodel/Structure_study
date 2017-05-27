#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int> a(N);
    vector<int> p(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        p[a[i]] = i;
    }
    int count = 0;
    int swap_sum = 0;
    while(count<N)
    {
        while(a[count]==count && count<N)
        {
            count++;
        }
        if(count == N)
            break;
        int i = count;
        int circle_n = 0;
        bool has0 = false;
        while(a[i]!=i)
        {
            if(a[i]==0)
                has0=true;
            int b = a[i];
            a[i] = p[b];
            i = b;
            circle_n++;
        }
        if(has0)
            swap_sum += circle_n-1;
        else
            swap_sum += circle_n+1;
    }
    printf("%d",swap_sum);
    return 0;
}