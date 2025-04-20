#include<iostream>
#include<cmath>
using namespace std;
#define NotAVertex (-1)
#define MAX 2147483647

class Vertex
{
public:
	int u;//linkvertex
	int w;//weight
	//int data;
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

class TableEntry
{
public:
	int Adj;
	int Known;
	long long Dist;
	int Path;
	TableEntry()
	{
		Adj=0;Known=0;Dist=MAX;Path=-1;
	}
};

class Linklist
{
public:
	int vNum,eNum;//number
	Vertex* vhead[1000];
	int data[1000];
	int TopNum[1000];
	int Indegree[1000];
	//TableEntry Table[10];
	Linklist()
	{
		for(int i=0;i<1000;i++)
		{
			data[i]=0;
			TopNum[i]=0;
			Indegree[i]=0;
			vhead[i]=nullptr;
		}
	}
};

void InitTable(int Start,Linklist* g,TableEntry* t[])
{	
	for(int i=0;i<g->vNum;i++)
	{
		t[i]->Known=0;
		t[i]->Dist=MAX;// infinity
		t[i]->Path=-1;// not a vertex
	}
	t[Start]->Dist=0;
}

void print_path(int v,Linklist* g,TableEntry* t[])
{
	if(t[v]->Path!=NotAVertex)
	{
		print_path(t[v]->Path,g,t);
		cout<<"->";
	}
	cout<<v;
}

int MinUnknownVertex(TableEntry* t[],Linklist* g)
{
	int Minindex=-1;
	int Min=MAX;
	
	for(int i=0;i<g->vNum;i++)
	{
		if(t[i]->Known==0&&t[i]->Dist<Min)
		{
			Min=t[i]->Dist;
			Minindex=i;
		}	
	}
	return Minindex;	
}

void Dijkstra(TableEntry* t[],Linklist* g)
{
	for(;;)
	{
		int m=MinUnknownVertex(t,g);
		if(m==-1)break;
		
		t[m]->Known=1;
		Vertex* v=g->vhead[m];
		if(v!=nullptr) v=v->next;
		while(v!=nullptr)
		{
			if(t[v->u]->Known==0)
			{
				if(t[m]->Dist+v->w<t[v->u]->Dist)
				{
					t[v->u]->Dist=t[m]->Dist+v->w;
					t[v->u]->Path=m;
				}
			}
			v=v->next;
		} 
	}
}

void add_edge(Linklist* g,int v,int u,int w)
{
	Vertex* t=new Vertex(u,w);
	if(g->vhead[v]==nullptr) g->vhead[v]=new Vertex;
	
	t->next=g->vhead[v]->next;
	g->vhead[v]->next=t;
	
	g->Indegree[u]++;
}

void creat_graph(Linklist* g1,Linklist* g2)
{
	cin>>g1->vNum>>g1->eNum;
	g2->eNum=g1->eNum;g2->vNum=g1->vNum;//input vNum and eNum
	for(int j=0;j<g1->eNum;j++)
	{
		int v,u,w;
		cin>>v>>u>>w;
		v--;u--;
		add_edge(g1,v,u,w);
		add_edge(g2,u,v,w);
	}
}

void Topsort(Linklist* g)
{
	int queue[10];
	int p=0;int t=0;
	for(int i=0;i<10;i++)queue[i]=0;
	
	for(int i=0;i<g->vNum;i++)
	{
		if(g->Indegree[i]==0)
		{
			queue[p]=i;p++;
		}
	}
	
	while(p>0)
	{
		Vertex* V=g->vhead[queue[p-1]];
		g->TopNum[t]=queue[p-1];t++;
		queue[p-1]=0;p--;
	
		if(V!=nullptr)V=V->next;
		while(V!=nullptr)
		{	
			g->Indegree[V->u]--;
			if(g->Indegree[V->u]==0)
			{
				queue[p]=V->u;p++;
			}
			V=V->next;
		}
	}
} 

int main()
{
	Linklist* Graph1=new Linklist;
	Linklist* Graph2=new Linklist;
	creat_graph(Graph1,Graph2);
	TableEntry **Table1=new TableEntry*[Graph1->vNum];
	for(int i=0;i<Graph1->vNum;i++)
	{
		Table1[i]=new TableEntry;
	}
	TableEntry **Table2=new TableEntry*[Graph1->vNum];
	for(int i=0;i<Graph1->vNum;i++)
	{
		Table2[i]=new TableEntry;
	}	
	InitTable(0,Graph1,Table1);InitTable(0,Graph2,Table2);
	Dijkstra(Table1,Graph1);Dijkstra(Table2,Graph2);
	
	long long sum=0;
	for(int i=0;i<Graph1->vNum;i++)
	{
		//cout<<"0 to "<<i<<" "<<Table1[i]->Dist<<" "<<Table2[i]->Dist<<endl;
		sum=sum+Table1[i]->Dist+Table2[i]->Dist;
	}
	cout<<sum<<endl;
	return 0;
}
/*
7
2 3 1 1 2 
2 3 3 4 10
2 0 4 5 5 
4 2 2 5 8 6 4 4 2
1 6 6 
0
1 5 1

0 2 3 1 3 6 5
*/
