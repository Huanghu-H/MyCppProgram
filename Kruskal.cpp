#include<iostream>
#include<cmath>
using namespace std;
#define MAX 101
typedef int DisjSet[MAX]; 

class Edge
{
public: 
	int w;
	int v;//Vertex
	int u;//Adjacency Vertex
	Edge* next;
	Edge()
	{
		w=0;v=0;u=0;next=nullptr;
	}
	Edge(int w1,int v1,int u1)
	{
		w=w1;v=v1;u=u1;next=nullptr;
	}
};

class PriorityQ
{
public:
	int size;
	Edge* E[MAX]; 
};

class Vertex
{
public:
	int u;//adjacency Vertex
	int w;//weight
	Vertex* next;
	Vertex()
	{
		u=0;w=0;next=nullptr;
	}
	Vertex(int u1,int w1)
	{
		u=u1;w=w1;next=nullptr;
	}
} ;

class Linklist
{
public:
	int vNum;
	int eNum;
	Vertex* vhead[MAX];	
	Linklist()
	{
		vNum=0;eNum=0;
		for(int i=0;i<MAX;i++)
		{
			vhead[i]=nullptr;
		}
	}	
};
class TableEntry
{
public:
	int Known;
	int Dist;
	int Path;
	TableEntry()
	{
		Known=0;Dist=MAX;Path=-1;
	}
};
void add_edge(Linklist* g,int v,int u,int w)
{
	Vertex* t=new Vertex(u,w);
	if(g->vhead[v]==nullptr)g->vhead[v]=new Vertex;
	t->next=g->vhead[v]->next;
	g->vhead[v]->next=t;
}
void creat_graph(Linklist* g)
{
	cin>>g->vNum;
	for(int i=0;i<g->vNum;i++)
	{
		int AdjNum;
		cin>>AdjNum;
		g->eNum+=AdjNum;
		for(int j=0;j<AdjNum;j++)
		{
			int u,w;
			cin>>u>>w;
			add_edge(g,i,u,w);
		}
	} 
}

PriorityQ* creat_heap(int eNum)
{
	PriorityQ* h=new PriorityQ;
	Edge* e=new Edge;
	Edge* min_e=new Edge(-1,0,0);
	for(int i=0;i<MAX;i++)
	{
		h->E[i]=e;
	}
	
	h->size=0;
	h->E[0]=min_e;
	return h;
} 
//Edge* read_graph(Linklist* g)
//{
//	Edge* ehead=new Edge;
//	Edge* etail=ehead;
//	for(int i=0;i<g->vNum;i++)
//	{
//		Vertex* v=g->vhead[i];
//		if(v!=nullptr)v=v->next;
//		while(v!=nullptr)
//		{
//			Edge* e=new Edge(v->w,i,v->u);
//			e->next=etail->next;
//			etail->next=e;
//			v=v->next;
//		}
//	}
//	return ehead;
//}
void Insert(PriorityQ* h,Edge* e)
{
	int i;
	for(i=++h->size;h->E[i/2]->w>e->w;i=i/2)
	{
		h->E[i]=h->E[i/2];
	}
	h->E[i]=e;
}
void build_heap(PriorityQ* h,Edge* e)
{
	e=e->next;
	while(e!=nullptr)
	{
		Insert(h,e);
		e=e->next;
	}
}
//Edge* delete_min(PriorityQ* h)
//{
//	int i,child;
//	
//	if(h->size==0)return h->E[0];
//	Edge* min_e=h->E[1];
//	Edge* last_e=h->E[h->size--];
//	
//	for(i=1;i*2<=h->size;i=child)
//	{
//		child=i*2;
//		if(child!=h->size&&h->E[child+1]<h->E[child])child++;
//		
//		if(last_e->w>h->E[child]->w)h->E[i]=h->E[child];
//		else break;
//	}
//	h->E[i]=last_e;
//	return min_e;
//}

void read_graph(Linklist* g,Edge* all_e[])
{
	int index_e=0;
	for(int i=0;i<g->vNum;i++)
	{
		Vertex* v=g->vhead[i];
		if(v!=nullptr) v=v->next;
		while(v!=nullptr)
		{
			Edge* temp_e=new Edge(v->w,i,v->u);
			all_e[index_e]=temp_e;
			index_e++;
			v=v->next;
		}
	}
}
void sort_edge(Linklist* g,Edge* all_e[])
{
	Edge** e=new Edge*[MAX];
	for(int i=0;i<MAX;i++)
	{
		e[i]=new Edge;
	}
	int index_e=0;
	
	int sorted[MAX];
	for(int i=0;i<MAX;i++)sorted[i]=0;
	while(index_e<g->eNum/2)
	{
		int min_index=0;
		int min_w=MAX;

		// Find the min wight
		for(int i=0;i<g->eNum;i++)
		{
			if(all_e[i]->w<min_w&&sorted[i]==0)
			{
				min_index=i;
				min_w=all_e[i]->w;
			}
		}
		sorted[min_index]=1;
		// See if min_index is existed 
		int exist=0;
		for(int i=0;i<index_e;i++)
		{
			if(all_e[min_index]->w==e[i]->w&&all_e[min_index]->u==e[i]->v
			&&all_e[min_index]->v==e[i]->u)
			exist=1;
		}
		// Insert 
		if(exist==0)
		{
			e[index_e]->w=all_e[min_index]->w;
			e[index_e]->u=all_e[min_index]->u;
			e[index_e]->v=all_e[min_index]->v;
			index_e++;
		}
		
	}
	//for(int i=0;i<g->eNum/2;i++)cout<<e[i]->w<<endl;
	// Transfer e to all_e
	for(int i=0;i<g->eNum;i++)
	{
		all_e[i]->w=0;all_e[i]->u=0;all_e[i]->v=0;
	}
	
	for(int i=0;i<g->eNum/2;i++)
	{
		all_e[i]->w=e[i]->w;all_e[i]->u=e[i]->u;all_e[i]->v=e[i]->v; 
	}
	cout<<endl;
	//for(int i=0;i<g->eNum/2;i++)cout<<all_e[i]->w<<endl;
}

void Initialize(DisjSet s)
{
	for(int i=0;i<MAX;i++)s[i]=-1;
}
void Union(DisjSet s,int r1,int r2)
{
	s[r2]=r1;
}
int Find(int x,DisjSet s)
{
	if(s[x]<=0)return x;
	else Find(s[x],s);
}

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


void Kruskal(Linklist* g)
{
	Linklist* G=new Linklist;
	G->vNum=g->vNum;
	int minEdge=0;
	DisjSet s;
	PriorityQ* h=creat_heap(g->eNum);
	int U,V;
	int uset,vset;
	Edge* e;
	
	Initialize(s);
	Edge** All_e=new Edge*[MAX];
	for(int i=0;i<MAX;i++)
	{
		All_e[i]=new Edge;
	}
	
	read_graph(g,All_e);
	//build_heap(h,ehead);
	sort_edge(g,All_e);
//	for(int i=0;i<g->eNum/2;i++)
//	{
//		cout<<All_e[i]->w<<endl;
//	}
	int min_index=0;
	while(minEdge<g->vNum-1)
	{
		e=All_e[min_index];
		min_index++;
		//cout<<e->w<<endl;
		U=e->u;
		V=e->v;
//		if(U>V)
//		{
//			int t=U;U=V;V=t;
//		} 
		uset=Find(U,s);
		vset=Find(V,s);
		//if(uset==8&&vset==1)cout<<U<<" "<<V<<endl;
		if(uset!=vset)
		{
			add_edge(G,U,V,e->w);
			add_edge(G,V,U,e->w);
			G->eNum++;
			minEdge++;
			Union(s,uset,vset);
		}
		//for(int i=0;i<g->vNum;i++)cout<<s[i]<<" ";
		//cout<<endl;
	}
	TableEntry **Table=new TableEntry*[G->vNum+1];
	for(int i=0;i<G->vNum;i++)
	{
		Table[i]=new TableEntry;
	}
	InitTable(0,G,Table);
	Dijkstra(Table,G);
	for(int i=0;i<G->vNum;i++)
	cout<<Table[i]->Path<<" ";
}

int main()
{
	Linklist* Graph=new Linklist;
	creat_graph(Graph);
	Kruskal(Graph);

	return 0;
}
/*

9
3    1 2    5 7    6 3
3    0 2    2 4    6 6
3    1 4    3 2    7 2
3    2 2    4 1    7 8
3    3 1    5 6    8 2
3    0 7    4 6    8 5
4    0 3    1 6    7 3    8 1
4    2 2    3 8    6 3    8 4
4    4 2    5 5    6 1    7 4

-1 0 3 4 8 8 0 2 6

要求如题目所示。

输入：
第一行，一个整数N，表示有N个顶点，顶点编号为0到N-1；
记下来的N行是出边表的输入，第i行表示第i个顶点的出边表（i从0开始计算）。
每一行首先是一个整数k，表示该顶点有k条出边；接下来是k个整数，
表示出边的目标结点。

输出：
N个整数，表示每个结点所在的强连通子图的编号。
每个强连通子图的编号为该子图中最小结点的编号。
注意，算法得出的编号未必是SCC中最小结点的编号，
因此在输出时需要进行一个转换。这个转换过程通过扫描
上面算法得到的SCC信息，很容易解决（可能需要额外的数组来实现编号转换）。

示例：
Input：
7
3    1    2    5
2    2    3
0
2    0    2
1    6
2    0    2
1    4

OUTPUT:
0 0 2 0 4 0 4
*/
