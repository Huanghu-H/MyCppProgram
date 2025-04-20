#include<iostream>
#include<string.h>
#include<set>
#include<vector> 
#include<utility>
using namespace std;
#define MAX 105

int d[MAX],low[MAX],parent[MAX];
vector<int> v[MAX]; 
set<pair<int,int>> ans;
int index,n,m,root;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(d,0,sizeof(d));
	memset(low,0,sizeof(low));
	memset(parent,0,sizeof(parent));
	index=0; 
 } 
 void dfs(int now)
 {
 	 int children=0;
 	 index++;
 	 d[now]=low[now]=index; 
 	 for(int i=0;i<v[now].size();i++)
 	 {
 	 	if(!d[v[now][i]])
 	 	{
 	 		children++;
 	 		parent[v[now][i]]=now;
 	 		dfs(v[now][i]);
 	 		low[now] = min(low[now],low[v[now][i]]);

		}
		else
		{
			if(v[now][i]!=parent[now])
		  	{
		  		low[now]=min(low[now],d[v[now][i]]);
			}
		}
	}
	if(now!=root&&low[now]>d[parent[now]])
 	{
 	 	ans.insert(make_pair(min(parent[now],now),max(parent[now],now)));
	}
	return;
 }
int main()
{
    init();
	for(int i=0;i<n;i++)
	{
		if(!d[i])
		{
			root=i;dfs(i);
		}
	}
	cout<<endl<<ans.size()<<endl;
	for(auto &it:ans)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;	
 } 
