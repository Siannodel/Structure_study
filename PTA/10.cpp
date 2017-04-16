#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
}Tree;
int GetTreeHeight(TreeNode* _node)
{
    if(_node == NULL)
        return 0;
    else
        return _node->height;
}
int CalTreeHeight(TreeNode* _node)
{
    return (GetTreeHeight(_node->left)>GetTreeHeight(_node->right)?
            GetTreeHeight(_node->left):GetTreeHeight(_node->right))+1;
}
Tree* Rotate_LL(Tree* _tree)
{
    TreeNode* tmp = _tree->left;
    _tree->left = tmp->right;
    tmp->right = _tree;
    //调整高度
    _tree->height = CalTreeHeight(_tree);
    tmp->height = CalTreeHeight(tmp);
    return tmp;
}
Tree* Rotate_RR(Tree* _tree)
{
    TreeNode* tmp = _tree->right;
    _tree->right = tmp->left;
    tmp->left = _tree;
    //调整高度
    _tree->height = CalTreeHeight(_tree);
    tmp->height = CalTreeHeight(tmp);
    return tmp;
}
Tree* Rotate_LR(Tree* _tree)
{
    _tree->left = Rotate_RR(_tree->left);
    return Rotate_LL(_tree);
}
Tree* Rotate_RL(Tree* _tree)
{
    _tree->right = Rotate_LL(_tree->right);
    return Rotate_RR(_tree);
}
Tree* MyInsert(TreeNode* _node,int _data)
{
    if(_node == NULL)
    {
        _node = (TreeNode*)malloc(sizeof(TreeNode));
        _node->data = _data;
        _node->left = _node->right = NULL;
        _node->height = 1;
        return _node;
    }
    if(_data < _node->data)
    {
        _node->left = MyInsert(_node->left,_data);
        if(GetTreeHeight(_node->left) - GetTreeHeight(_node->right) == 2)
        {
            if(_data < _node->left->data)
            {
                _node = Rotate_LL(_node);//LL
            }
            else
            {
                 _node = Rotate_LR(_node);//LR
            }
        }
    }
    else
    {
        _node->right = MyInsert(_node->right,_data);
        if(GetTreeHeight(_node->right) - GetTreeHeight(_node->left) == 2)
        {
            if(_data > _node->right->data)
            {
                 _node = Rotate_RR(_node);//RR
            }
            else
            {
                 _node = Rotate_RL(_node);//RL
            }
        }
    }
    _node->height = CalTreeHeight(_node);
    
    return _node;
}
int main()
{
    int N;
    cin>>N;
    Tree* tree = NULL;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        tree = MyInsert(tree,tmp);
    }
    cout<< tree->data <<endl;
    return 0;
}