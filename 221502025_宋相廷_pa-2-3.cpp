#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000005
#define INF 99999999
 
struct node
{
    ll t,cap,flow,next;    
}e[N];
int head[N],cur[N],cnt; 
void init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
}
void add(int u,int v,ll cap)   
{
    e[cnt]=node{v,cap,0,head[u]};
    head[u]=cnt++;
    e[cnt]=node{u,0,0,head[v]};   
    head[v]=cnt++;
}
int d[N];    
bool bfs(int s,int t) 
{
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];~i;i=e[i].next)
        {
            int v=e[i].t;
            if(d[v]==0&&e[i].cap-e[i].flow>0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]>0;     
}
ll dfs(int s,int t,ll minedge)
{
    if(s==t)return minedge;
    ll flow=0;   
    for(int &i=cur[s];~i;i=e[i].next)
    {
        int v=e[i].t;
        if(d[v]==d[s]+1&&e[i].cap-e[i].flow>0)   
        {
            ll temp=dfs(v,t,min(minedge-flow,e[i].cap-e[i].flow));
            e[i].flow+=temp;    
            e[i^1].flow-=temp;    
            flow+=temp;   
            if(flow==minedge)return flow; 
        }
    }
    if(flow==0)d[s]=0;  
    return flow;
}
ll dinic(int s,int t)   
{
    ll maxflow=0;
    while(bfs(s,t))   
    {
        memcpy(cur,head,sizeof(head));  
        maxflow+=dfs(s,t,INF);
    }
    return maxflow;
}
int pro[220];
int main()
{
    int n,m,u,v;
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pro[i]);
    }
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u,&v);
        add(v,u,INF);
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(pro[i]>0)
		{
            add(0,i,pro[i]);
            sum+=pro[i];
        }
        else if(pro[i]<0)add(i,n+1,-pro[i]);
    }
    int ans=dinic(0,n+1);
    cout<<sum-ans<<endl;
    return 0;
}
