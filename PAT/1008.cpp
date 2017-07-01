#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int first = 0;
    int time_sum = 5*N;
    for(int i=0;i<N;i++)
    {
        int next;
        cin>>next;
        int d = next - first;
        if(d>0)
        {
            time_sum += d*6;
        }
        else
        {
            time_sum -= d*4;
        }
        first = next;
    }
    cout<< time_sum;
    int test;
    cin>>test;
    return 0;
}