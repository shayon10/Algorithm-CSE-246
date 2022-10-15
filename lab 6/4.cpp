#include<bits/stdc++.h>
using namespace std;
vector<int>vt[100000];
#define MOD   1000000007
int vis[1000000], di[200005], path[10000];

void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    di[x]=0;
    path[x]=1;

    while(!q.empty())
    {
        int u=q.front();

        q.pop();
        for(int i=0;i<vt[u].size();i++)
        {
            int v=vt[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }

           if (di[v] > di[u] + 1)
            {
                di[v] = di[u] + 1;
                path[v] = path[u]%MOD;
            }


            else if (di[v] == di[u] + 1)
                path[v] = (path[v] + path[u])%MOD;
        }
    }
}

int main()
{
    int n, a, b, x,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
     for(int i=1;i<=n;i++)
        di[i]=INT_MAX;
    bfs(1);

    cout<<path[n]<<endl;
    if (n==1){
        cout<<"Yes"<<endl;}
        else
              cout<<"No"<<endl;


    return 0;
}
