#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool test(int _stack_capacity,vector<int> &_sequence)
{
    int size = _sequence.size();
    stack<int> s;
    int count = 0;
    for(int i=1;i<=size;i++)
    {
        if(s.size()>=_stack_capacity)
        {
           return false;
        }
        s.push(i);
        while(s.top()==_sequence[count])
        {
            s.pop();
            count++;
            if(s.empty())
            {
                break;
            }
        }
    }
    if(count == size)
    {
        return true;
    }
    return false;
}
int main()
{
    int M,N,K;
    cin>>M>>N>>K;
    vector<bool> result;
    for(int i=0;i<K;i++)
    {
        vector<int> sequence;
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin>>tmp;
            sequence.push_back(tmp);
        }
        bool tmp = test(M,sequence);
        result.push_back(tmp);
    }
    for(int i=0;i<K;i++)
    {
        if(result[i])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}