#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int K1,K2;
    vector<pair<int,float> >v1;
    vector<pair<int,float> >v2;
    vector<pair<int,float> >result;
    scanf("%d",&K1);
    for(int i=0;i<K1;i++)
    {
        pair<int,float> tmp;
        scanf("%d %f",&tmp.first,&tmp.second);
        v1.push_back(tmp);
    }
    scanf("%d",&K2);
    for(int i=0;i<K2;i++)
    {
        pair<int,float> tmp;
        scanf("%d %f",&tmp.first,&tmp.second);
        v2.push_back(tmp);
    }
    int i1=0,i2=0;
    while(i1<v1.size() && i2<v2.size())
    {
        if(v1[i1].first>v2[i2].first)
        {
            result.push_back(v1[i1]);
            i1++;
            continue;
        }
        if(v2[i2].first>v1[i1].first)
        {
            result.push_back(v2[i2]);
            i2++;
            continue;
        }
        if(v1[i1].first==v2[i2].first)
        {
            if(v1[i1].second+v2[i2].second!=0)
                result.push_back(pair<int,float>(v1[i1].first,v1[i1].second+v2[i2].second));
            i1++;
            i2++;
        }
    }
    while(i1<v1.size())
    {
        result.push_back(v1[i1]);
        i1++;
    }
    while(i2<v2.size())
    {
        result.push_back(v2[i2]);
        i2++;
    }
    int size = result.size();
    printf("%d",size);
    for(int i=0;i<size;i++)
    {
        printf(" %d %g",result[i].first,result[i].second);
    }
    int test;
    cin>>test;
    return 0;
}