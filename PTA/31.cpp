#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int n)
{
    if(n<2)
    {
        return false;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int T = M;
    while(!is_prime(T))
    {
        T++;
    }
    //vector<int> input(N);
    vector<int> hash(T,-1);
    vector<int> output(N);
    for(int i=0;i<N;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        int set = tmp%T;
        int j=0;
        while(hash[set]!=-1 && j<T)
        {
            j++;
            if(j%2)
            {
                set = set+(j+1)*(j+1)/4;
                if(set>=T)
                {
                    set = set%T;
                }
            }
            else
            {
                set = set-j*j/4;
                while(set<0)
                {
                    set += T;
                }
            }
        }
        if(hash[set]==-1)
        {
            hash[set] = tmp;
            output[i] = set;
        }
        else
        {
            output[i] = -1;
        }
    }
    printf("%d",output[0]);
    for(int i=1;i<N;i++)
    {
        if(output[i]==-1)
        {
            printf(" -");
        }
        else
        {
            printf(" %d",output[i]);
        }
    }
    printf("\n");
    return 0;
}