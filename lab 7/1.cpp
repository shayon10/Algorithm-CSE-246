#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
vector<int>V[100],traversed;
int color[MAX],d[MAX],f[MAX],pREv[MAX], white=0,grey=1,black=2,inf=10000,t=0,s=-1,e;
void DFS(int u)
{
    int i,j,x;
    color[u] = grey;
    t++;
    d[u] = t;

    for(j=0;j<V[u].size();j++)
    {
        x = V[u][j];
        if(color[x]==white)
        {
            pREv[x] = u;
            DFS(x);
        }
        else if(color[x] == grey && x!=pREv[u])
        {
            s = u;
            e = x;
        }
    }
    color[u] = black;
    t++;
    f[u] = t;
}


int main()
{
    int i,node,edge,u,v,j;
    cin>>node>>edge;
    for(i=1;i<=edge;i++)
    {
        cin>>u>>v;
        if(u==v)
        {
            V[u].push_back(v);
        }
        else
        {
            V[u].push_back(v);
            V[v].push_back(u);
        }
    }


    for(i=1;i<=node;i++)
    {
        color[i]=white;
        pREv[i] = inf;
        d[i] = inf;
        f[i] = inf;
    }

    for(i=1;i<=node;i++)
    {
        if(color[i]==white)
        {
            DFS(i);
        }
    }
    if(s!=-1)
    {
        cout<<"YES"<<endl;
        traversed.push_back(s);
        while(e<s)
        {
            traversed.push_back(pREv[s]);
            s = pREv[s];
        }
        sort(traversed.begin(),traversed.end());
        for(i=0;i<traversed.size();i++)
        {
            printf("%d ",traversed[i]);
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
}



