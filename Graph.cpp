#include<iostream>
#include<cmath>
using namespace std;
#define vNum 9

class Vertex
{
public:
	int u;//邻接点 
	int w;//权重
	//int v;//自己的位置 
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

class LinkList
{
public:
	int TopNum[vNum];
	int data[vNum];
	Vertex* edge[vNum];
	int v,e;
	int Indegree[vNum];
	LinkList()
	{
		for(int i=0;i<vNum;i++)
		{
			Indegree[i]=0;
			edge[i]=nullptr;
		}
	}	
};

void add_edge(LinkList* g,int u,int v,int w)
{
	Vertex *t=new Vertex(v,w);
	if(g->edge[u]==nullptr)	g->edge[u]=new Vertex;
	t->next=g->edge[u]->next;
	g->edge[u]->next=t;
	g->Indegree[v]++;	
}

LinkList* creat_graph()
{
	int u,v,w;
	LinkList* g=new LinkList;
	cin>>g->v>>g->e;//输入顶点与边数
	for(int i=0;i<g->e;i++)
	{
		cin>>u>>v>>w;
		add_edge(g,u,v,w);
	//	add_edge(g,v,u,w); //无向图 
	}
	return g; 
}

int FindZeroIndegree(LinkList* g)
{
	for(int i=g->v-1;i>=0;i--)
	{
		if(g->Indegree[i]==0)return i;
	}
	return vNum+1;
}

void DecreaseIndegree(LinkList* g,int v)
{
	Vertex* p=g->edge[v];
	while(p!=nullptr&&p->next!=nullptr)
	{
		int i=p->next->u;
		g->Indegree[i]--;
		p=p->next;
	}
	//cout<<g->Indegree[0]<<" "<<g->Indegree[1]<<" "<<g->Indegree[2]<<endl;
}

void Topsort(LinkList* g)
{
	for(int i=0;i<g->v;i++)
	{
		int V=FindZeroIndegree(g);
		if(V==vNum+1) return;
		g->TopNum[i]=V;
		g->Indegree[V]=vNum+1;
		DecreaseIndegree(g,V);
	}	
}

/*
3 3 0 1 1 0 2 1 1 2 1
*/

int main()
{
	LinkList* Graph=creat_graph();
	Topsort(Graph);
	for(int i=0;i<vNum;i++)cout<<Graph->TopNum[i]<<" ";
	return 0;
}
/*
9
1 1
1 3
1 3
0
1 2
1 2
1 2
1 1
5 0 4 5 6 7

9 12
0 1 1
1 3 1
2 3 1
4 2 1
5 2 1
6 2 1
7 1 1
8 0 1
8 4 1
8 5 1
8 6 1
8 7 1
8 0 4 5 6 2 7 1 3

8 7 6 5 4 2 0 1 3
*/
