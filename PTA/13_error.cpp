#include<stdio.h>
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int MyFindRoot(const vector<int> &_Net,int computer_N)
{
    int root = computer_N;
    while(_Net[root]!=-1)
        root = _Net[root];
    return root;
}
void MyCreateTree(vector<int> &_Net,vector<pair<int,int> > &_v_I)
{
    vector<pair<int,int> >::iterator it = _v_I.begin();
    while(it!=_v_I.end())
    {
        int root1 = MyFindRoot(_Net,it->first);
        int root2 = MyFindRoot(_Net,it->second);
        if(root1 != root2)
        {
            _Net[root2] = root1;
        }        
        it++;
    }
}
void MyPrint(vector<int> &_Net,vector<pair<int,int> > &_v_C)
{
    vector<pair<int,int> >::iterator it = _v_C.begin();
    while(it!=_v_C.end())
    {
        int root1 = MyFindRoot(_Net,it->first);
        int root2 = MyFindRoot(_Net,it->second);
        if(root1 == root2)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        it++;
    }
    vector<int>::iterator it_Net = _Net.begin();
    int count = 0;
    it_Net++;
    while(it_Net!=_Net.end())
    {
        if(*it_Net == -1)
            count++;
        it++;
    }
    if(count==1)
        printf("The network is connected.");
    else
        printf("There are %d components.",count);
}
int main()
{
    int N;
    //scanf("%d",&N);
    cin>>N;
    vector<int> Net(N+1,-1);
    vector<pair<int,int> > v_I;
    vector<pair<int,int> > v_C;
    while(true)
    {
        char flag;
        //scanf("%c",&flag);
        cin>>flag;
        if(flag == 'S')
            break;
        if(flag == 'C')
        {
            pair<int,int> tmp_C;
            //scanf("%d %d",&tmp_C.first,&tmp_C.second);
            cin>>tmp_C.first>>tmp_C.second;
            v_C.push_back(tmp_C);
        }
        else
        {
            pair<int,int> tmp_I;
            //scanf("%d %d",&tmp_I.first,&tmp_I.second);
            cin>>tmp_I.first>>tmp_I.second;
            v_I.push_back(tmp_I);
        }
    }
    MyCreateTree(Net,v_I);
    MyPrint(Net,v_C);
    return 0;
}