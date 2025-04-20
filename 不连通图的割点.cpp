#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 200001
 
class vertex
{
public:
	int u;//vertex name
	int w;//edge weight
	vertex* next;
	vertex()
	{
		u=0;w=0;next=nullptr;
	}
	vertex(int u1,int w1)
	{
		u=u1;w=w1;next=nullptr;
	}
};
class Linklist
{
public:
	int vNum;
	int eNum;
	vertex* vHead[MAX];
	Linklist()
	{
		vNum=0;eNum=0;
		for(int i=0;i<MAX;i++)
		{
			vHead[i]=nullptr;
		}
	}
};
class Table
{
public:
	int time;
	int low[MAX];
	int stk[MAX];
	int child_num[MAX];
	int visited[MAX];
	int parent[MAX];
	int isCutV[MAX];
	Table()
	{
		time=0;
		for(int i=0;i<=MAX;i++)
		{
			low[i]=stk[i]=child_num[i]=visited[i]=
			parent[i]=isCutV[i]=0;
		}
	}
};
void add_edge(Linklist* g,int v,int u,int w)
{
	vertex* t=new vertex(u,w);
	if(g->vHead[v]==nullptr)
	{
		g->vHead[v]=t;
	}
	else 
	{
		t->next=g->vHead[v]->next;
		g->vHead[v]->next=t;
	}
}
void creat_graph(Linklist* g)
{
	cin>>g->vNum>>g->eNum;
	for(int i=1;i<=g->eNum;i++)
	{
		int u,v;
		cin>>u>>v;
		add_edge(g,u,v,1);
		add_edge(g,v,u,1);
	}
}

void DFSCV(Linklist* g,int x,Table* t)
{
	t->time++;
	t->stk[x]=t->time;
	t->low[x]=t->stk[x];
	t->visited[x]=1;
	
	vertex* v=g->vHead[x];
	while(v!=nullptr)
	{
		if(t->visited[v->u]==0)
		{
			t->parent[v->u]=x;
			t->child_num[x]++;
			DFSCV(g,v->u,t);
			t->low[x]=min(t->low[x],t->low[v->u]);
			if(t->parent[x]==0&&t->child_num[x]>=2)
			{
				//cutVertex.push_back(x);
				t->isCutV[x]=1;
			}
			else if(t->parent[x]!=0&&t->low[v->u]>=t->stk[x])
			{
				//cutVertex.push_back(x);
				t->isCutV[x]=1;
			}
		} 
		else if(v->u!=t->parent[x]) 
		{
			t->low[x]=min(t->low[x],t->stk[v->u]);
		}
		v=v->next;
	}
}
//6 7 1 2 1 4 2 3 2 4 2 5 3 4 5 6 
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	Table* T=new Table; 
	for(int i=1;i<=G->vNum;i++)
	{
		if(T->visited[i]==0)
		{
			DFSCV(G,i,T);
		}
	}
	int CutVNum=0;
	for(int i=1;i<=G->vNum;i++)
	{
		if(T->isCutV[i]==1)CutVNum++;
	}
	cout<<CutVNum<<endl;
	for(int i=1;i<=G->vNum;i++)
	{
		if(T->isCutV[i]==1)cout<<i<<endl;
	}
	return 0;
}

