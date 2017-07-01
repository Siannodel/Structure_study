#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int K;
    cin>>K;
    vector<int> N;
    int max_sum = -1;
    int s1,e1;
    for(int i=0;i<K;i++)
    {
        int tmp;
        cin>>tmp;
        N.push_back(tmp);
    }
    s1 = N[0];
    e1 = N[K-1];

    int now_sum = 0;
    int s2,e2;
    bool new_q = true;
    for(int i=0;i<K;i++)
    {
        if(new_q)
        {
            s2 = N[i];
            new_q = false;
        }

        now_sum += N[i];
        e2 = N[i];

        if(now_sum>max_sum)
        {
            max_sum = now_sum;
            s1 = s2;
            e1 = e2;
        }
        
        if(now_sum<0)
        {
            new_q = true;
            now_sum = 0;
        }
    }
    if(max_sum>=0)
    {
        cout << max_sum << " " << s1 << " " << e1; 
    }
    else
    {
        cout<< 0 << " " << N[0] << " " << N[K-1];
    }
    int test;
    cin>>test;
    return 0;
}