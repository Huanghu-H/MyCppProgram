#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
#define MAX 105

int G[MAX][MAX];
int degree[MAX];
int cnt[MAX];// Each vertex odd or even degree 
int N,M;// vNum eNum 
stack<int> S;// Euler Trail
 
void dfs(int u)
{
    for(int v=N;v>=1;v--)
        if(G[u][v])
		{
            G[u][v]-=1;
            G[v][u]-=1;
            dfs(v);
            // the edge v-u has been visited
            // no need to recover
        }
    S.push(u);
}
void init()
{
	// all cnt = 0; all G[u][v] = 0;
	memset(cnt,0,sizeof cnt);
	memset(G,0,sizeof G);
}
void Print_Trail()
{
	while(!S.empty())
	{
	    cout<<S.top()<<" ";
	    S.pop();
	}
	cout<<endl;
	return ;
}
int judge()
{
	int res=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			//cout<<G[i][j]<<" " ;
			if(G[i][j]>0) res=0;
		}
		//cout<<endl;
	}
	return res;	
}
// 6 8 1 2 1 5 1 6 2 5 5 6 2 3 2 4 3 4
// 3 3 1 2 1 3 2 3
int main()
{
	cin>>N>>M;
	init();
	int u,v;
	for(int i=1;i<=M;++i)
	{
		cin>>u>>v;
		degree[u]++;
		degree[v]++;
    	G[u][v]+=1;
    	G[v][u]+=1;
    	cnt[u]^=1;
		cnt[v]^=1;
		// Add edge and Change the u/v parity 
	}
	int odd_vertex=0; 
	int max_odd_v=0;
	int max_have_edge_v=0;
	for(u=1;u<=N;u++)
	{
		if(degree[u]!=0)max_have_edge_v=u;
	    if(cnt[u]) 
	    {
	    	max_odd_v=u;
	    	odd_vertex++;
		}
	}
	//0 odd
	if(odd_vertex==0)
	{
		dfs(max_have_edge_v);
		if(judge()==0)
		{
			cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	//2 odd
	else if(odd_vertex==2)
	{
		dfs(max_odd_v);
		if(judge()==0)
		{
			cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	//No Euler Trail
	else cout<<0<<endl;
	if((odd_vertex==0||odd_vertex==2)&&judge()==1)Print_Trail();
    return 0;
}
