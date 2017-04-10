#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <malloc.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
}Tree;
void Myprint(Tree* _tree, int _firstdata)
{
    if(_tree == NULL)
        return;
    Myprint(_tree->lchild, _firstdata);
    Myprint(_tree->rchild, _firstdata);
    if(_tree->data == _firstdata)
        cout<<_tree->data;
    else
        cout<<_tree->data<<" ";
}
int main()
{
    int N;
    cin>>N;
    int N2 = N*2;
    TreeNode* c_node = NULL;
    bool flag = true;
    stack<TreeNode*> s;
    Tree* tree;
    for(int i =0;i<N2;i++)
    {
        string str;
        cin>>str;
        if(str == "Push")
        {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            cin >> node->data;
            node->lchild = NULL;
            node->rchild = NULL;
            if(c_node!=NULL)
            {
                if(flag)
                    c_node->lchild = node;
                else
                    c_node->rchild = node;
            }
            else
            {
                tree = node;
            }
            s.push(node);
            c_node = node;
            flag = true;
        }
        else
        {
            c_node = s.top();
            flag = false;
            s.pop();
        }
    }
    Myprint(tree, tree->data);
    return 0;
}