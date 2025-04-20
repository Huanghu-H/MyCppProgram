#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 105

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
class edge
{
public:
	int u;
	int v;
	edge()
	{
		u=0;v=0;
	}
	edge(int u1,int v1)
	{
		u=u1;v=v1;
	}
};
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
	cin>>g->vNum;
	for(int i=1;i<=g->vNum;i++)
	{
		int AdjNum;
		cin>>AdjNum;
		for(int j=0;j<AdjNum;j++)
		{
			int u;cin>>u;
			add_edge(g,i,u,1);
			add_edge(g,u,i,1);
		}
	} 
}
vector<int> cutVertex;
vector<edge*> cutEdge;
int time=0;
int stk[MAX],low[MAX],visited[MAX],parent[MAX],child_num[MAX],isCutV[MAX];
void DFSTree(Linklist* g,int x)
{
	time++;
	stk[x]=time;
	low[x]=stk[x];
	visited[x]=1;
	Vertex* v=g->vHead[x];
	while(v!=nullptr)
	{
		if(visited[v->u]==0)
		{
			parent[v->u]=x;
			child_num[x]++;
			DFSTree(g,v->u);
			low[x]=min(low[x],low[v->u]);
		}
		else if(v->u!=parent[x])
		{
			low[x]=min(low[x],stk[v->u]);
		}
		v=v->next;
	}
}
void cut_Vertex(Linklist* g)
{
	for(int i=1;i<=g->vNum;i++)
	{
		//cout<<child_num[i]<<endl;
		if(parent[i]==0&&child_num[i]>=2)isCutV[i]=1;
		else if(parent[parent[i]]!=0&&low[i]>=stk[parent[i]])
		{
			isCutV[parent[i]]=1;
		}
	}
	for(int i=1;i<=g->vNum;i++)
	{
		if(isCutV[i]==1)cutVertex.push_back(i);
	}
}
void cut_Edge(Linklist* g)
{
	for(int i=1;i<=g->vNum;i++)
	{
		if(stk[i]==low[i]&&parent[i]!=0)
		{
			edge* e=new edge(i,parent[i]);
			cutEdge.push_back(e);
		}
	}
}
// 6 2 2 4 3 3 4 5 1 4 0 1 6 0
// 7 2 2 3 2 4 5 2 6 7 0 0 0 0 
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	DFSTree(G,1);
	//DFSCV(G,1);
	cut_Edge(G);
	cut_Vertex(G);
	cout<<"CutVertex:"<<endl;
	for(auto x:cutVertex)
	{
		cout<<x<<" ";
	}
	cout<<endl<<"CutEdge:"<<endl;
	for(auto x:cutEdge)
	{
		cout<<"("<<x->u<<","<<x->v<<") ";
	}
	return 0;
}
void DFSCV(Linklist* g,int x)
{
	time++;
	stk[x]=time;
	low[x]=stk[x];
	visited[x]=1;
	Vertex* v=g->vHead[x];//cout<<"A0"<<endl;
	while(v!=nullptr)
	{
		//cout<<x<<" "<<v->u<<endl;;
		if(visited[v->u]==0)
		{//cout<<"B"<<endl;
			parent[v->u]=x;
			child_num[x]++;
			DFSCV(g,v->u);
			low[x]=min(low[x],low[v->u]);
			if(parent[x]==0&&child_num[x]>=2)
			{
				cutVertex.push_back(x);
				isCutV[x]=1;
			}
			else if(parent[x]!=0&&low[v->u]>=stk[x])
			{
				cutVertex.push_back(x);
				isCutV[x]=1;
			}
		}
		else if(v->u!=parent[x])
		{//cout<<"C"<<endl;
			low[x]=min(low[x],stk[v->u]);
		}
		v=v->next;
	}
} 
