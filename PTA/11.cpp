#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <malloc.h>
using namespace std;

typedef struct BTnode{
    int data;
    BTnode* left;
    BTnode* right;
}BT;

BT* CreateCBT(int _N,int _data)
{
    queue <BTnode*> q;
    int i = 1;
    BTnode* root = (BTnode*)malloc(sizeof(BTnode));
    root->data = _data;
    root->left = root->right = NULL;
    q.push(root);
    while(i!=_N)
    {
        BTnode* tmp_node = q.front();
        q.pop();
        BTnode* child1 = (BTnode*)malloc(sizeof(BTnode));
        child1->data = _data;
        child1->left = child1->right = NULL;
        tmp_node->left = child1;
        i++;
        if(i == _N)
            break;
        BTnode* child2 = (BTnode*)malloc(sizeof(BTnode));
        child2->data = _data;
        child2->left = child2->right = NULL;
        tmp_node->right = child2;
        i++;
        q.push(child1);
        q.push(child2);
    }
    return root;
}
void midTraverse(BT* _tree,vector<int>::iterator &_it)
{
    if(_tree ==NULL)
        return;
    midTraverse(_tree->left,_it);
    _tree->data = *_it;
    _it++;
    midTraverse(_tree->right,_it);
    return;
}
void MyPrint(BT* _tree)
{
    queue <BTnode*> q;
    q.push(_tree);
    while(!q.empty())
    {
        BTnode* tmp = q.front();
        q.pop();
        if(tmp == _tree)
        {
            cout<<tmp->data;
        }
        else
        {
            cout<<" "<<tmp->data;
        }
        if(tmp->left!=NULL)
        {
            q.push(tmp->left);
        }
        if(tmp->right!=NULL)
        {
            q.push(tmp->right);
        }
    }
}

int main()
{
    int N;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    BT* CBT = CreateCBT(N,-1);
    vector<int>::iterator it = v.begin();
    midTraverse(CBT,it);
    MyPrint(CBT);
    return 0;
}