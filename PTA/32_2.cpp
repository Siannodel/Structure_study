#include <stdio.h>
#include <iostream>
#include <map>
#include <utility>
#include <cstring>

using namespace std;
struct ptrcmp{
    bool operator()(const char*a, const char *b)const 
    {
        return strcmp(a,b)<0;
    }
};
int main()
{
    int n;
    char ch;
    char *account,*password;
    map<char*,char*,ptrcmp> m;
    scanf("%d",&n);
    while(n--)
    {
        account = new char[10];
        password = new char[16];
        ch = getchar();
        while(isspace(ch))
            ch = getchar();
        scanf("%s%s",account,password);
        if(ch=='N')
        {
            auto p = m.insert(make_pair(account,password));
            if(!p.second)
                printf("ERROR: Exist\n");
            else printf("New: OK\n");
        }
        else
        {
            auto it = m.find(account);
            if(it==m.end())
            {
                printf("ERROR: Not Exist\n");
            }
            else if(strcmp(it->second,password)==0)
                printf("Login: OK\n");
            else printf("ERROR: Wrong PW\n");
        }
    }
    return 0;
}