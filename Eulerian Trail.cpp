#include<iostream>
#include<cmath>
#include<vector>
#include<set> 
#define NotAVertex (-1)
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
	int from;int to;int visited;
	edge()
	{
		from=to=visited=0;
	}
	edge(int u,int v)
	{
		from=u;to=v;visited=0;
	}	
};set<edge*> remain_e;
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
};TableEntry **Table=new TableEntry*[10];
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
			edge* e=new edge(i,u);
			edge* e2=new edge(u,i);
			remain_e.insert(e);
			remain_e.insert(e2);	
			add_edge(g,i,u,1);
			add_edge(g,u,i,1);
		}
	} 
}
//class Trail
//{
//public:
//	vector<edge> t;
//	Trail()
//	{
//		t.clear();
//	}
//	void add(edge* e)
//	{
//		t.push_back(*e);
//	}	
//};
vector<int> trail;
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
bool judge(Linklist* g)
{
	int odd_degree_v=0;
	for(int i=1;i<g->vNum;i++)
	{
		if(g->degree[i]%2==1)
		odd_degree_v++;
	}
	if(odd_degree_v==0||odd_degree_v==2) return true;
	else return false;
} 
edge* find(set<edge*> s,int x,int y)
{
	for(auto i:s)
	{
		if(i->from==x&&i->to==y)return i;
	}
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
		Vertex* v=g->vHead[m];
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
void print_path(int v,Linklist* g,TableEntry* t[])
{
	if(t[v]->Path!=NotAVertex)
	{
		print_path(t[v]->Path,g,t);
		//cout<<"->";
	}
	trail.push_back(v);
	//cout<<v;
}
void FindTrail(Linklist* g,int begin,int end)
{
	InitTable(begin,g,Table);
	Dijkstra(Table,g);
	print_path(end,g,Table);
}
void EulerTrail(Linklist* g)
{
	int odd_v1=0,odd_v2=0;
	for(int i=1;i<g->vNum;i++)
	{
		if(g->degree[i]%2==1&&odd_v1==0)
		{
			odd_v1=i;
		}
		else if(g->degree[i]%2==1)
		{
			odd_v2=i;
		}
	}
	if(odd_v1!=0) FindTrail(g,odd_v1,odd_v2);
	else FindTrail(g,1,2); 
	int last=trail[0];
	int count=0;
	
	for(auto i:trail)
	{
		if(count==0) 
		{
			count++;continue;
		}
		edge* e1=find(remain_e,i,last);
		edge* e2=find(remain_e,last,i);
		remain_e.erase(e1);
		remain_e.erase(e2);
		count++;
		last=i;
	}
	
	while()
	{
		
	}
	for(auto i:remain_e)
	{
		cout<<i->from<<" "<<i->to<<endl;
	}
} 
// 6 2 2 4 3 3 4 5 1 4 0 1 6 0
// 7 2 2 3 2 4 5 2 6 7 0 0 0 0 
// 3 2 2 3 1 3 0
int main()
{
	Linklist* G=new Linklist;
//	Trail* T=new Trail;
	
	for(int i=0;i<10;i++)
	{
		Table[i]=new TableEntry;
	}		
	creat_graph(G);
	int have_trail=judge(G);
	if(have_trail==true) EulerTrail(G);
	else cout<<"No Eulerian Trail"<<endl;
	return 0;
}

