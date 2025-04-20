#include<iostream>
#include<cmath>
using namespace std;
#define MAX 99999

class Vertex
{
public:
	int u;
	int w;
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
	Vertex* vhead[10];
	Linklist()
	{
		for(int i=0;i<10;i++)
		{
			vhead[i]=nullptr;
		}
	} 
}; 

class TableEntry
{
public:
	int dist;
	int known;
	int pre;
	TableEntry()
	{
		dist=MAX;known=0;pre=-1;
	}	
}; 

void InitTable(int Start,Linklist* g,TableEntry* t[])
{
	//t[Start]->known=1;
	t[Start]->dist=0;
}

void add_edge(Linklist* g,int u,int v,int w)
{
	Vertex* t=new Vertex(v,w);
	if(g->vhead[u]==nullptr)g->vhead[u]=new Vertex;
	t->next=g->vhead[u]->next;
	g->vhead[u]->next=t;
}

Linklist* creat_graph()
{
	Linklist* g=new Linklist;
	cin>>g->vNum>>g->eNum;
	for(int i=0;i<g->eNum;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		u--;v--;
		add_edge(g,u,v,w);
	} 
	return g;
}

int Prim(Linklist* g,TableEntry* t[])
{
	int weight_sum=0;
	
	for(int i=0;i<g->vNum;i++)
	{
		//find the vertex that have min distance to the set
		int minvertex=-1;
		for(int j=0;j<g->vNum;j++)
		{
			if(t[j]->known==0&&(minvertex==-1||t[minvertex]->dist>t[j]->dist))
				minvertex=j;
		}
		t[minvertex]->known=1;
		if(t[minvertex]->dist!=MAX) weight_sum+=t[minvertex]->dist;
		//update other vertex
		Vertex* m=g->vhead[minvertex];
		if(m!=nullptr)m=m->next;
		while(m!=nullptr)
		{
			t[m->u]->dist=min(t[m->u]->dist,m->w);
			m=m->next;
		}
	}
	return weight_sum;
}

int main()
{
	Linklist* Graph=creat_graph();
	TableEntry** Table=new TableEntry*[10];
	for(int i=0;i<10;i++)
	{
		Table[i]=new TableEntry;
	} 
	InitTable(0,Graph,Table);
	cout<<Prim(Graph,Table)<<endl;
	return 0;
}
/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
*/
