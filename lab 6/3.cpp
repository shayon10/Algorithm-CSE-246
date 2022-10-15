#include<bits/stdc++.h>
using namespace std;
int mx=-(INT_MAX),nod;
int vis[10001],dis[10001];
vector<int>adj[10001];
void dfs(int node,int d)
{
	vis[node]=1;
	dis[node]=d;
	if(dis[node]>mx)
	{
		mx=dis[node];
		nod=node;
	}
	for(int child: adj[node])
	{
		if(vis[child]==0)
		{
			dfs(child,dis[node]+1);
		}
	}
}
int main()
{
	int n,m,u,v,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	mx=-1;
	for(i=1;i<=n;i++)
        vis[i]=0;
	dfs(nod,0);
	cout<<mx<<endl;
	return 0;
}
