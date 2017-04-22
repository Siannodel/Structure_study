#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> preTraversal;
vector<int> midTraversal;
vector<int> postTraversal;
void solve(int preL,int inL,int postL,int n)
{
    if(n==0) return;
    if(n==1) 
    {
        postTraversal[postL]=preTraversal[preL];
        return;
    }
    int root = preTraversal[preL];
    postTraversal[postL+n-1] = root;
    int i=0;
    for(;i<n;i++)
    {
        if(midTraversal[inL+i]==root)
            break;
    }
    int L_n = i;
    int R_n = n-L_n-1;
    solve(preL+1,inL,postL,L_n);
    solve(preL+i+1,inL+L_n+1,postL+L_n,R_n);
}

int main()
{
    int N;
    cin>>N;
    stack<int> s;
    postTraversal.resize(N);
    for(int i=0;i<N*2;i++)
    {
        string str;
        cin>>str;
        if(str == "Push")
        {
            int node;
            cin>>node;
            s.push(node);
            preTraversal.push_back(node);
        }
        else
        {
            int node = s.top();
            s.pop();
            midTraversal.push_back(node);
        }
    }
    solve(0,0,0,N);
    cout<<postTraversal[0];
    for(int i =1;i<N;i++)
    {
        cout<<" "<<postTraversal[i];
    }
    return 0;
}