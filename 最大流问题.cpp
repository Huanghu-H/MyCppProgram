#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 205
#define INF 0x7fffffff
#define ll long long
ll min(ll a, ll b) 
{
	return a > b ? b : a;
}
using namespace std;
// From s to t
ll g[N][N], pre[N], dis[N]; 
ll n, m, s, t, ans;
queue <ll> q; 

ll bfs () 
{ 
	for(int i = 1; i <= n; i++) pre[i] = -1;
	while(!q.empty()) q.pop();
	q.push(s);
	dis[s] = INF;
	while (!q.empty()) 
	{
		ll x = q.front();
		q.pop();
		if(x == t) break; 
		for(int i = 1; i <= n; i++) 
		{
			if(pre[i] == -1 && g[x][i]) 
			{ 
				pre[i] = x;
				dis[i] = min(dis[x], g[x][i]); 
				q.push(i);
			}
		}
	}
	if(pre[t] == -1) return -1; 
	else return dis[t];
}

void EK () 
{ 
	ll inc;
	while (1) 
	{
		inc = bfs();
		if(inc == -1) break; 
		ll k = t; // from terminate find pre  
		while (k != s) 
		{
			g[k][pre[k]] += inc; 
			g[pre[k]][k] -= inc; 
			k = pre[k];
		}
		ans += inc;
	}
}

int main () 
{
	ll u, v, cost;
	scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
	memset(dis, 0, sizeof(dis));
	memset(g, 0, sizeof(g));
	ans = 0;
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld %lld %lld", &u, &v, &cost);
		g[u][v] += cost;
	}
	EK();
	printf("%lld\n", ans);
	return 0;
}
