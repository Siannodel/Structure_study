#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int MyFindRoot(const vector<int> &_Net,int computer_N)
{
    int root = computer_N;
    while(_Net[root]!=-1)
        root = _Net[root];
    return root;
}


int main()
{
    int N;
    //scanf("%d",&N);
    cin>>N;
    vector<int> Net(N+1,-1);
    vector<bool>result;
    while(true)
    {
        char flag;
        //scanf("%c",&flag);
        cin>>flag;
        if(flag == 'S')
            break;
        if(flag == 'I')
        {
            int c1,c2;
            cin>>c1>>c2;
            int root1 = MyFindRoot(Net,c1);
            int root2 = MyFindRoot(Net,c2);
            if(root1 != root2)
            {
                Net[root2] = root1;
            }
        }
        else
        {
            int c1,c2;
            cin>>c1>>c2;
            int root1 = MyFindRoot(Net,c1);
            int root2 = MyFindRoot(Net,c2);
            if(root1 == root2)
                result.push_back(true);
            else
                result.push_back(false);
        }
    }
    vector<bool>::iterator it = result.begin();
    while(it!=result.end())
    {
        if(*it)
            printf("yes\n");
        else
            printf("no\n");
        it++;
    }
    vector<int>::iterator it_Net = Net.begin();
    int count = 0;
    it_Net++;
    while(it_Net!=Net.end())
    {
        if(*it_Net == -1)
            count++;
        it_Net++;
    }
    if(count==1)
        printf("The network is connected.");
    else
        printf("There are %d components.",count);
    return 0;
}