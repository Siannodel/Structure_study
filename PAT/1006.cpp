#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
using namespace std;
struct Time{
    int H;
    int M;
    int S;
};
bool comp(const Time &t1,const Time &t2)
{
    if(t1.H>t2.H) return true;
    else if(t1.H<t2.H) return false;
    else
    {
        if(t1.M>t2.M) return true;
        else if(t1.M<t2.M) return false;
        else
        {
            if(t1.S>t2.S) return true;
            else return false;
        }
    }
}
int main()
{
    int M;
    scanf("%d",&M);
    //char unlock_ID[15];
    //char lock_ID[15];
    string unlock_ID;
    string lock_ID;
    Time first_time = {24,59,59};
    Time last_time = {0,0,0};
    for(int i=0;i<M;i++)
    {
        string ID;
        char tmp;
        Time sign_in,sign_out;
        cin>>ID;
        scanf("%d%c%d%c%d",&sign_in.H,&tmp,&sign_in.M,&tmp,&sign_in.S);
        scanf("%d%c%d%c%d",&sign_out.H,&tmp,&sign_out.M,&tmp,&sign_out.S);
        if(comp(first_time,sign_in))
        {
            first_time = sign_in;
            unlock_ID = ID;
        }
        if(!comp(last_time,sign_out))
        {
            last_time = sign_out;
            lock_ID = ID;
        }
    }
    cout<<unlock_ID<<" "<<lock_ID;
    int test;
    cin>>test;
    return 0;
}