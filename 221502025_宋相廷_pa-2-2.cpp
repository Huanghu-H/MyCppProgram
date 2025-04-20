#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define N 10005
#define P 100000005
#define INF 199999999
int n,m,root;
int u,v,w;
int g[N][N],inCost[N],pre[N];
int id[N],vis[N];
struct node
{
    int u,v,w;
}edges[N];
int zhuliu()
{
    int res = 0;
    while(true){
        for(int i = 1; i <= n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1;
        for(int i = 0; i < m; ++ i)
		{
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(u != v && w < inCost[v])
			{
                inCost[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(i != root && inCost[i] == INF)
			{
               
                return -1;
            }
        }
        inCost[root] = 0;
        int tn = 0;
        for(int i = 1; i <= n; ++ i)
		{
            res += inCost[i];
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
			{
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
			{
                id[v] = ++tn;
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;
            }
        }
        if(tn == 0)break;
        for(int i = 1; i <= n; ++ i)
		{
            if(id[i] == -1)
			{
                id[i] = ++tn;
            }
        }
        int i = 0;
        while(i < m)
		{
            int vv = edges[i].v;
            edges[i].u = id[edges[i].u], edges[i].v = id[edges[i].v];
            if(edges[i].u != edges[i].v)
			{
                edges[i ++].w -= inCost[vv];
            }
            else
			{
                swap(edges[i],edges[-- m]);
            }
        }
        n = tn;
        root = id[root];
    }
    return res;
}
void solve()
{
    printf("%d\n", zhuliu());
}
int main(){	
	root=1;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)for(int j = 1; j <= n; ++ j)g[i][j] = INF;
    for(int i = 0; i < m; ++ i)
	{
        scanf("%d%d%d", &u, &v, &w);
        if(u == v)continue;
        g[u][v] = min(g[u][v],w);
    }
    m = 0;
    for(int i = 1; i <= n; ++ i)
	{
        for(int j = 1; j <= n; ++ j)
		{
            if(g[i][j] != INF)
			{
                edges[m].u = i,edges[m].v = j,edges[m ++].w = g[i][j];
            }
        }
    }
    solve();
    return 0;
}

