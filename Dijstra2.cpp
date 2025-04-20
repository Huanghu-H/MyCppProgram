#include<iostream>
#include<cmath>
#include<list>
// push/pop_front/back()
using namespace std;
#define MAX 105 

class vertex
{
public:
	int u;//linkvertex name
	int w;//edge weight
	vertex* next;
	vertex()
	{
		u=w=0;next=nullptr;
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
		vNum=eNum=0;
		for(int i=0;i<MAX;i++)
		{
			vHead[i]=nullptr;
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
	cin>>g->vNum;
	for(int i=1;i<=g->vNum;i++)
	{
		int AdjNum;
		cin>>AdjNum;
		for(int j=1;j<=AdjNum;j++)
		{
			int u;cin>>u;
			add_edge(g,i,u,1);
			add_edge(g,u,i,1);
		}
	}
}
list<int> vlist;
int visited[MAX],parent[MAX],d[MAX];
int isnot_visited(Linklist* g)
{
	for(int i=1;i<=g->vNum;i++)
	{
		if(visited[i]==0)return i;
	}
	return -1;
} 
void Dijstra(Linklist* g,int x)
{
	vlist.push_back(x);
	visited[x]=1;
	while(vlist.size()!=0)
	{
		vertex* v=g->vHead[vlist.front()];
		while(v!=nullptr)
		{
			if(visited[v->u]==0)
			{
				vlist.push_back(v->u);
				parent[v->u]=vlist.front();
				d[v->u]=d[vlist.front()]+1;
			}
			else
			{
				if(d[v->u]>d[vlist.front()]+1)
				{
					parent[v->u]=vlist.front();
					d[v->u]=d[vlist.front()]+1;
				}
			}
			visited[v->u]=1;
			v=v->next;	
		}
		vlist.pop_front();
	}
}
void output(Linklist* g)
{
	for(int i=1;i<=g->vNum;i++)
	{
		cout<<d[i]<<"    "<<i<<" ";
		int j=i;
		while(parent[j]!=0)
		{
			cout<<"<- "<<parent[j]<<" ";
			j=parent[j];
		}
		cout<<endl;
	}
}
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	Dijstra(G,2);
	output(G);
	return 0;
}

