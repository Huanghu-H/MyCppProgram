#include<iostream>
#include<cmath>
#include<vector>
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
	cin>>g->vNum>>g->eNum;
	for(int i=1;i<=g->eNum;i++)
	{
		int u,v;
		cin>>u>>v;
		add_edge(g,u,v,1);
		add_edge(g,v,u,1);
	} 
}
int visited[MAX];
void search(Linklist* g,int x)
{
	visited[x]=1;
	Vertex* v=g->vHead[x];
	while(v!=nullptr)
	{
		if(visited[v->u]==0)
		{
			search(g,v->u);
		}
		v=v->next;
	}
}
int component(Linklist* g)
{
	int comp_num=0;
	int i=1;
	while(i<=g->vNum)
	{
		if(visited[i]==0)
		{
			search(g,i);
			comp_num++;
			i=0;
		}
		i++;
	}
	return comp_num;
}
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	cout<<component(G)<<endl; 
	return 0;
}

