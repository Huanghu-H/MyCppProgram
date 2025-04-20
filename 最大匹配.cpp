#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#define Inf 0x7fffffff 
#define N 2005
using namespace std;

vector<int> G[N]; 
int cx[N],cy[N];  
int dx[N],dy[N];
int nx,ny;
int dis,vis[N];

int Searchpath()
{
	queue<int> p;
	dis=Inf;
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	for(int i=1;i<=nx;i++)
	{
		if(cx[i]==-1)
		{
			p.push(i);
			dx[i]=0;
		}
	}
	while(!p.empty())
	{
		int u=p.front();
		p.pop();
		if(dx[u]>dis) break;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(dy[v]==-1)
			{
				dy[v]=dx[u]+1;
				if(cy[v]==-1) dis=dy[v];
				else
				{
					dx[cy[v]]=dy[v]+1;
					p.push(cy[v]);
				}
			}
		}
	}
	return dis!=Inf;
}
int Findpath(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!vis[v]&&dy[v]==dx[u]+1)
		{
			vis[v]=1;
			if(cy[v]!=-1&&dy[v]==dis) continue;
			if(cy[v]==-1||Findpath(cy[v]))
			{
				cy[v]=u;
				cx[u]=v;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch()
{
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	int ans=0;
	while(Searchpath())
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=nx;i++)
		{
			if(cx[i]==-1)
			{
				ans+=Findpath(i);
			}
		}
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>nx>>ny>>m; //vertex and edge number
	n=nx+ny;
	//nx=ny=n;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		b=b+nx;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	nx=ny=n;
	cout<<MaxMatch()/2<<endl;
	return 0;
}

