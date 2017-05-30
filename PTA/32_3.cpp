#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstring>

using namespace std;
struct HashFunc
{
    size_t operator()(const char* a) const
    {
        int len = strlen(a);
        if(len<=6)
        {
            return atoi(a);
        }
        else
        {
            return atoi(a+(len-6));
        }
    }
};
struct EqualKey
{
    bool operator()(const char* a, const char* b) const
    {
        if(strcmp(a,b)==0)
            return true;
        return false;
    }   
}
int main()
{
    int n;
    char ch;
    char *account,*password;
    unordered_map<char*,char*,HashFunc,EqualKey> m;
    scanf("%d",&n);
    while(n--)
    {
        account = new char[10];
        password = new char[16];
        ch = getchar();
        while(isspace(ch))
            ch = getchar();
        scanf("%s%s",account,password);
    }
    return 0;
}