#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode{
    char data;
    char lchildern;
    char rchildern;
};
int comp(const TreeNode &_a, const TreeNode &_b)
{
    return _a.data<_b.data;
}
void Myfunction(vector<TreeNode> &_Tree)
{
    int size = _Tree.size();
    for(int i=0;i<size;i++)
    {
        if(_Tree[i].lchildern!='-')
        {
            _Tree[i].lchildern = _Tree[int(_Tree[i].lchildern-'0')].data;
        }
        if(_Tree[i].rchildern!='-')
        {
            _Tree[i].rchildern = _Tree[int(_Tree[i].rchildern-'0')].data;
        }
    }
    sort(_Tree.begin(),_Tree.end(),comp);
}
int main()
{
    //输入第一颗树
    int N1;
    cin>>N1;
    vector<TreeNode> Tree1;
    for(int i=0;i<N1;i++)
    {
        TreeNode tmpNode;
        cin>>tmpNode.data>>tmpNode.lchildern>>tmpNode.rchildern;
        Tree1.push_back(tmpNode);
    }
    //输入第二颗树
    int N2;
    cin>>N2;
    vector<TreeNode> Tree2;
    for(int i=0;i<N2;i++)
    {
        TreeNode tmpNode;
        cin>>tmpNode.data>>tmpNode.lchildern>>tmpNode.rchildern;
        Tree2.push_back(tmpNode);
    }
    //
    if(N1!=N2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    Myfunction(Tree1);
    Myfunction(Tree2);
    for(int i=0;i<N1;i++)
    {
        if(!(Tree1[i].data==Tree2[i].data &&
        ((Tree1[i].lchildern==Tree2[i].lchildern &&
        Tree1[i].rchildern==Tree2[i].rchildern)||
        (Tree1[i].lchildern==Tree2[i].rchildern &&
        Tree1[i].rchildern==Tree2[i].lchildern))))
        {
            cout<<"No"<<endl;
            return 0;
        }

    }
    cout<<"Yes"<<endl;
    return 0;
}