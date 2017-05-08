#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Route{
    int v1;
    int v2;
    int charge;
};

int comp(Route a,Route b)
{
    return a.charge<b.charge;
}

int findRoot(vector<int> &_connect,int _v)
{
    int tmp = _v;
    while(_connect[tmp]!=-1)
    {
        tmp = _connect[tmp];
    }
    return tmp;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<Route> routes;
    for(int i=0;i<M;i++)
    {
        Route tmp;
        cin>>tmp.v1>>tmp.v2>>tmp.charge;
        routes.push_back(tmp);
    }
    sort(routes.begin(),routes.end(),comp);
    vector<int> connect(N+1,-1);
    int sum_charge=0;
    int num_edge = 0;
    for(int i=0;i<M && num_edge<N-1;i++)
    {
        int root1 = findRoot(connect,routes[i].v1);
        int root2 = findRoot(connect,routes[i].v2);
        if(root1!=root2)
        {
            connect[root2]=root1;
            sum_charge += routes[i].charge;
            num_edge++;
        }
    }
    if(num_edge<N-1)
        cout<<-1;
    else
        cout<<sum_charge;
    return 0;
}