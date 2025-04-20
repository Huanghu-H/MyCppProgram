#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;
#define MAX 200001

class Vertex
{
public:
	int u;//link name
	int w;//its weight
	Vertex* next;
	Vertex()
	{
		u=0;w=0;next=nullptr;
	}
	Vertex(int u1,int w1)
	{
		u=u1;w=w1;next=nullptr;
	} 
};
class Linklist
{
public:
	int vNum;
	int eNum;
	Vertex* vHead[MAX];
	int degree[MAX];
	Linklist()
	{
		vNum=0;eNum=0;
		for(int i=0;i<MAX;i++)
		{
			vHead[i]=nullptr;
			degree[i]=0;
		}
	}
};

stack<pair<int,int>> edge_stk;
void add_edge(Linklist* g,int v,int u,int w)
{
	Vertex* t=new Vertex(u,w);
	if(g->vHead[v]==nullptr)
	{
		g->vHead[v]=t;
		g->degree[v]++;
	}
	else
	{
		t->next=g->vHead[v]->next;
		g->vHead[v]->next=t;
		g->degree[v]++;
	}
} 
void creat_graph(Linklist* g)
{
	cin>>g->vNum>>g->eNum;
	for(int i=1;i<=g->eNum;i++)
	{
		int x,y;
		cin>>x>>y;
		add_edge(g,x,y,1);
		add_edge(g,y,x,1); 
	} 
}
int Time=0;
vector<int> ans;
int stk[MAX],low[MAX],visited[MAX],parent[MAX],child_num[MAX];
void DFSblk(Linklist* g,int x)
{
	Time++;
	stk[x]=Time;
	low[x]=stk[x];
	visited[x]=1;
	Vertex* v=g->vHead[x];
	if(v==nullptr)ans.push_back(0);
	while(v!=nullptr)
	{
		if(visited[v->u]==0)
		{
			edge_stk.push({x,v->u});
			
			parent[v->u]=x;
			child_num[x]++;
			DFSblk(g,v->u);
			low[x]=min(low[x],low[v->u]);
			if((parent[x]==0&&child_num[x]>=2)||(parent[x]!=0&&low[v->u]>=stk[x]))
			{
				int edge_num=0,a,b;	
				do
				{
					a=edge_stk.top().first;
					b=edge_stk.top().second;
					edge_stk.pop();
				
					//cout<<t.u<<t.v<<" ";
					edge_num++;
				}
				while(!edge_stk.empty()&&
				!((a==x&&b==v->u)||
				(b==v->u&&a==x)));
				//cout<<endl;
				ans.push_back(edge_num);
			}
		}
		else if(v->u!=parent[x])
		{
			if(stk[x]>stk[v->u])
			{
				edge_stk.push({x,v->u});
			}
			low[x]=min(low[x],stk[v->u]);
		}
		v=v->next;
	}
} 
// 6 8 1 2 1 5 1 6 2 5 5 6 2 3 2 4 3 4
// 8 10 1 2 2 3 2 4 3 5 4 5 4 7 5 8 7 8 1 6 6 7
// 7 6 1 2 1 3 2 4 2 5 3 6 3 7 
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	for(int i=1;i<=G->vNum;i++)
	{
       	if(!visited[i]) 
	   	{
            DFSblk(G,i);
    	}
		if(!edge_stk.empty())
		{
			int edge_num=0;
			do
			{
				edge_stk.pop();
				
				//cout<<t0.u<<" "<<t.v<<" ";	
				edge_num++;
			}while(!edge_stk.empty());
			ans.push_back(edge_num);
		}	
    }
	
	
	sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
	{
        cout<<ans[i]<<" ";
    }
	return 0;
}

