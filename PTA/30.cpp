#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;

struct ListNode{
    long long number;
    int count;
};
int main()
{
    int N;
    scanf("%d",&N);
    vector<list<ListNode> > phone_number(100000);
    long long number1,number2;
    for(int i=0;i<N;i++)
    {
        scanf("%lld %lld",&number1,&number2);
        int i1 = number1%100000;
        ListNode tmp1;
        tmp1.number=number1;
        tmp1.count = 1;
        list<ListNode>::iterator it1 = phone_number[i1].begin();
        bool flag1 = false;
        while(it1!=phone_number[i1].end())
        {
            if(it1->number == tmp1.number)
            {
                flag1 = true;
                it1->count++;
                break;
            }
            it1++;    
        }
        if(!flag1)
        {
            phone_number[i1].push_front(tmp1);
        }

        int i2 = number2%100000;
        ListNode tmp2;
        tmp2.number = number2;
        tmp2.count = 1;
        list<ListNode>::iterator it2 = phone_number[i2].begin();
        bool flag2 = false;
        while(it2!=phone_number[i2].end())
        {
            if(it2->number == tmp2.number)
            {
                flag2 = true;
                it2->count++;
                break;
            }
            it2++;    
        }
        if(!flag2)
        {
            phone_number[i2].push_front(tmp2);
        }
        
    }
    vector<list<ListNode> >::iterator it = phone_number.begin();
    int max_count = 0;
    long long number;
    int num = 0;
    for(;it!=phone_number.end();it++)
    {
        if(it->empty())
            continue;
        list<ListNode>::iterator it2 = it->begin();
        while(it2!=it->end())
        {
            if(it2->count>max_count)
            {
                max_count = it2->count;
                number=it2->number;
                num = 1;
            }
            else if(it2->count == max_count)
            {
                num++;
                if(number>it2->number)
                {
                    number = it2->number;
                }
            }
            it2++;
        }
    }
    if(num == 1)
    {
        printf("%011lld %d",number,max_count);
    }
    else
    {
        printf("%011lld %d %d",number,max_count,num);
    }
    printf("\n");
    return 0;
}