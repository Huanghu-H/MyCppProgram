#include<iostream>
#include<cmath>
using namespace std;
#define NotAVertex (-1)
#define MAX 9999999
//typedef int (long long) 
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
	int Dist;
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
	Vertex* vhead[10];
	int data[10];
	int TopNum[10];
	int Indegree[10];
	//TableEntry Table[10];
	Linklist()
	{
		for(int i=0;i<10;i++)
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

Linklist* creat_graph()
{
	Linklist* g=new Linklist;
	cin>>g->vNum;//input vNum and eNum
	for(int i=0;i<g->vNum;i++)
	{
		int AdjacentNum;
		cin>>AdjacentNum;
		//input adjacency point 
		for(int j=0;j<AdjacentNum;j++)
		{
			int u,w;
			cin>>u>>w;
			add_edge(g,i,u,w);
			//add_edge(g,u,i,w);
		}
	} 
	return g;
}


int main()
{
	Linklist* Graph=creat_graph();
	TableEntry **Table=new TableEntry*[10];
	for(int i=0;i<10;i++)
	{
		Table[i]=new TableEntry;
	}	
	InitTable(0,Graph,Table);
	Dijkstra(Table,Graph);
	print_path(6,Graph,Table);
	cout<<endl<<"Total Distance: "<<Table[6]->Dist<<endl;
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
