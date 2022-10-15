#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
vector<int>V[100],traversed;
int color[MAX],d[MAX],f[MAX],pREV[MAX], white=0,grey=1,black=2,inf=10000,mx=-1,c,t=0;
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
            c++;
            pREV[x] = u;
            DFS(x);
        }
    }
    color[u] = black;
    t++;
    f[u] = t;
    traversed.push_back(u);
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
        }
    }
    for(i=1;i<=node;i++)
    {
        sort(V[i].begin(),V[i].end());
    }
    for(i=1;i<=node;i++)
    {
        color[i]=white;
        pREV[i] = inf;
        d[i] = inf;
        f[i] = inf;
    }
    for(i=node;i>=1;i--)
    {

        for(j=V[i].size()-1;j>=0;j--)
        {
            if(color[V[i][j]]==white)
            {
                DFS(V[i][j]);
            }
        }
        if(color[i] == white)
        {
            DFS(i);
        }

    }
    for(i=traversed.size()-1;i>=0;i--)
    {
        printf("%d\n",traversed[i]);
    }
}

