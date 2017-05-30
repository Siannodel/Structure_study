#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
struct Q{
    long long number;
    string password;
};
int main()
{
    int N;
    cin>>N;
    vector<list<Q> > hash_QQ(100000);
    vector<int> output(N);
    for(int i=0;i<N;i++)
    {
        char C;
        Q tmp;
        tmp.password.resize(16);
        //scanf("%c %lld %s",&C,&tmp.number,&tmp.password[0]);
        cin>>C>>tmp.number>>tmp.password;
        if(C=='N')//注册
        {
            int set = tmp.number%100000;
            bool is_exist = false;
            list<Q>::iterator it = hash_QQ[set].begin();
            while(it!=hash_QQ[set].end())
            {
                if(it->number == tmp.number)
                {
                    is_exist =  true;
                    break;
                }
                it++;
            }
            if(is_exist)
                output[i] = 2;
            else
            {
                hash_QQ[set].push_front(tmp);
                output[i] = 1;
            }
        }
        else //登录
        {
            int set = tmp.number%100000;
            bool is_exist = false;
            list<Q>::iterator it = hash_QQ[set].begin();
            while(it!=hash_QQ[set].end())
            {
                if(it->number == tmp.number)
                {
                    is_exist =  true;
                    break;
                }
                it++;
            }
            if(is_exist)
            {
                if(it->password == tmp.password)
                {
                    output[i] = 3;
                }
                else
                {
                    output[i] = 5;
                }
            }
            else
            {
                output[i] = 4;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        switch(output[i])
        {
            case 1:
            {
                printf("New: OK");
                break;
            }
            case 2:
            {
                printf("ERROR: Exist");
                break;
            }
            case 3:
            {
                printf("Login: OK");
                break;
            }
            case 4:
            {
                printf("ERROR: Not Exist");
                break;
            }
            case 5:
            {
                printf("ERROR: Wrong PW");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}