#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <vector>
using namespace std;
typedef struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
}Tree;
Tree* MyInsert(Tree* _tree, int _data)
{

    if(!_tree)
    {
        _tree = (TreeNode*)malloc(sizeof(TreeNode));
        _tree->data = _data;
        _tree->lchild = NULL;
        _tree->rchild = NULL;
    }
    else
    {
        if(_data < _tree->data)
            _tree->lchild = MyInsert(_tree->lchild,_data);
        else
            _tree->rchild = MyInsert(_tree->rchild,_data);
    }
    return _tree;
}
bool TestTree(Tree* _tree,Tree* _tree2)
{
    if(_tree == NULL && _tree2 == NULL)
        return true;
    if(_tree == NULL || _tree2 == NULL)
        return false;
    if(_tree->data != _tree2->data)
        return false;
    bool l = TestTree(_tree->lchild,_tree2->lchild);
    bool r = TestTree(_tree->rchild,_tree2->rchild);
    if(l && r)
        return true;
    return false;
}
int main()
{
    int N,L;
    vector<bool> result;
    while(true)
    {
        cin>>N;
        if(N==0)
            break;
        cin>>L;
        Tree* tree = NULL;
        for(int j = 0; j<N;j++)
        {
            int tmp;
            cin>>tmp;
            
            tree = MyInsert(tree,tmp);
        }
         for(int i = 0;i < L;i++)
        {
            Tree* tree2 = NULL;
            for(int j = 0; j<N;j++)
            {
                int tmp;
                cin>>tmp;
                
                tree2 = MyInsert(tree2,tmp);
            }
            bool r = TestTree(tree,tree2);
            result.push_back(r);        
        }

    }
    for(int i =0;i<result.size();i++)
    {
        if(result[i])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}