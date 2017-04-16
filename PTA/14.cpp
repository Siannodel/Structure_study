#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int comp(string str1,string str2)
{
    return str1.size()<str2.size();
}
bool fun(vector<string> &_codes)
{
    sort(_codes.begin(),_codes.end(),comp);
    int size = _codes.size();
    for(int i =0;i<size-1;i++)
    {
        int l = _codes[i].size();
        for(int j=i+1;j<size;j++)
        {
            if(_codes[i] == _codes[j].substr(0,l))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    vector<int> v;
    vector<int> frequency;
    for(int i =0;i<N;i++)
    {
        char tmp1,tmp3;
        int tmp2;
        //cin>>tmp1>>tmp2;
        scanf("%c%c%d",&tmp1,&tmp3,&tmp2);
        v.push_back(tmp2);
        frequency.push_back(tmp2);
    }
    sort(v.begin(),v.end(),greater<int>());
    //计算WPL
    int WPL=0;
    while(v.size() > 1)
    {
        int a = v[v.size()-1]+v[v.size()-2];
        WPL += a;
        v.pop_back();
        v.pop_back();
        v.push_back(a);
        //sort(v.begin(),v.end(),greater<int>());   
        int i = v.size()-2;
        while(a>v[i] && i>=0)
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = a;
       
    }

    int M;
    cin>>M;
    vector<bool> result; 
    for(int i =0;i<M;i++)
    {
        vector<string> codes;
        int WPL2 = 0;
        for(int j =0;j<N;j++)
        {
            char tmp1;
            string tmp2;
            cin>>tmp1>>tmp2;
            codes.push_back(tmp2);
            WPL2 += tmp2.size()*frequency[j];
        }
        if(WPL2!=WPL)
        {
            result.push_back(false);
            continue;
        }
        if(!fun(codes))
        {
            result.push_back(false);
            continue;
        }
        result.push_back(true);
    }
    for(int i =0;i<M;i++)
    {
        if(result[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}