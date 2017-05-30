#include <stdio.h>
#include <iostream>

using namespace std;
void getpre(int _mid[], int _post[],int n)
{
    if(n<=0)
        return;
    int root = _post[n-1];
    int i;
    for(i=0;i<n;i++)
    {
        if(_mid[i]==root)
            break;
    }
    cout<<' '<<root;
    getpre(_mid,_post,i);
    getpre(_mid+i+1,_post+i,n-i-1);
}
int main()
{
    int N;
    cin>>N;
    int post[30];
    int mid[30];
    int pre[30];
    for(int i=0;i<N;i++)
    {
        cin>>post[i];
    }
      for(int i=0;i<N;i++)
    {
        cin>>mid[i];
    }
    cout<<"Preorder:";
    getpre(mid,post,N);
    cout<<endl;
    return 0;
}