#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void myprint(int a)
{
    switch(a)
    {
        case 0:
        {
            cout<<"zero";
            break;
        }
        case 1:
        {
            cout<<"one";
            break;
        }
        case 2:
        {
            cout<<"two";
            break;
        }
        case 3:
        {
            cout<<"three";
            break;
        }
        case 4:
        {
            cout<<"four";
            break;
        }
        case 5:
        {
            cout<<"five";
            break;
        }
        case 6:
        {
            cout<<"six";
            break;
        }
        case 7:
        {
            cout<<"seven";
            break;
        }
        case 8:
        {
            cout<<"eight";
            break;
        }
        case 9:
        {
            cout<<"nine";
            break;
        }
        default:
        {
            break;
        }
    }
}
int main()
{
    string s;
    cin>>s;
    int longth = s.length();
    int sum = 0;
    for(int i=0;i<longth;i++)
    {
        int tmp = s[i]-'0';
        sum += tmp;
    }
    vector<int> result;
    while(true)
    {
        int tmp = sum % 10;
        result.push_back(tmp);
        sum/=10;
        if(sum==0)
        {
            break;
        }
    }
    for(int i=result.size()-1;i>0;i--)
    {
        myprint(result[i]);
        cout<<" ";
    }
    myprint(result[0]);
    int test;
    cin>>test;
    return 0;
}