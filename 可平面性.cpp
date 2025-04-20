#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 1005
vector<int> G[MAX];
int visit[MAX];

int dfs(int v)
{
	visit[v]=1;
	for(auto u:G[v])
	{
		if(visit[u]==0)
		dfs(u);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int w=0;
	for(int i=0;i<=n;i++)
	{
		if(visit[i]==0&&G[i].size()!=0)
		{
			w++;
			dfs(i);
		}
	}
	cout<<w+1+m-n<<endl;
	return 0;
}
// 4 6 1 2 1 3 1 4 2 3 2 4 3 4
