#include<iostream>
#include<cmath>
using namespace std;
#define MAX 101

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
	Vertex* vhead[MAX];
	int Indegree[MAX]; 
	int TopNum[MAX];
	Linklist()
	{
		vNum=0;eNum=0;
		for(int i=0;i<MAX;i++)
		{
			vhead[i]=nullptr;
			Indegree[i]=0;
			TopNum[i]=0;
		}
	}
};
void add_edge(Linklist* g,int v,int u,int w)
{
	Vertex* t=new Vertex(u,w);
	if(g->vhead[v]==nullptr)g->vhead[v]=new Vertex;
	t->next=g->vhead[v]->next;
	g->vhead[v]->next=t; 
	g->Indegree[u]++;
}
void creat_graph(Linklist* g)
{
	cin>>g->vNum;
	for(int i=0;i<g->vNum;i++)
	{
		int AdjNum;
		cin>>AdjNum;
		for(int j=0;j<AdjNum;j++)
		{
			int u;cin>>u;
			add_edge(g,i,u,1);
		}
	}
}
int dfn[MAX],low[MAX],tot;
int stk[MAX],instk[MAX],top;
int scc[MAX],siz[MAX];
int find_min_v(int x,int y)
{
	int p=top;
	int m=x;//cout<<x<<" "<<y<<endl;
	while(stk[p]!=x)
	{
		m=min(m,stk[p]);
		p--;
	} //cout<<m<<endl;
	return m;
}
void Tarjan(Linklist* g,int x)
{
	// Put in time_stamp dfn and stack
	dfn[x]=low[x]=++tot;
	stk[++top]=x;instk[x]=1;
	
	Vertex* v=g->vhead[x];
	if(v!=nullptr)v=v->next;
	while(v!=nullptr)
	{
		if(dfn[v->u]==0)
		{
			Tarjan(g,v->u);
			low[x]=min(low[x],low[v->u]);
		}
		else if(instk[v->u]==1)
		{
			low[x]=min(low[x],dfn[v->u]);
		}
		v=v->next;
	} 
	if(dfn[x]==low[x])
	{
		int y=stk[top];
		int min_v=find_min_v(x,y);//cout<<min_v<<endl;
		do
		{
			y=stk[top--];
			instk[y]=0;
			scc[y]=min_v;
			++siz[min_v];
		}while(y!=x);
	}

}
int FindZeroIndegree(Linklist* g)
{
	for(int i=0;i<g->vNum;i++)
	{
		if(g->Indegree[i]==0)return i;
	}
	return g->vNum+1;
}

void DecreaseIndegree(Linklist* g,int v)
{
	Vertex* p=g->vhead[v];
	while(p!=nullptr&&p->next!=nullptr)
	{
		int i=p->next->u;
		g->Indegree[i]--;
		p=p->next;
	}
	//cout<<g->Indegree[0]<<" "<<g->Indegree[1]<<" "<<g->Indegree[2]<<endl;
}

void Topsort(Linklist* g)
{
	for(int i=0;i<g->vNum;i++)
	{
		int V=FindZeroIndegree(g);
		if(V==g->vNum+1) return;
		g->TopNum[i]=V;
		g->Indegree[V]=g->vNum+1;
		DecreaseIndegree(g,V);
	}	
}
int main()
{
	Linklist* G=new Linklist;
	creat_graph(G);
	//Topsort(G);cout<<G->TopNum[0]<<endl;
	for(int i=0;i<G->vNum;i++)scc[i]=-1;
	for(int i=0;i<G->vNum;i++)
	{
		if(scc[i]==-1)Tarjan(G,i);
	}
	for(int i=0;i<G->vNum;i++)cout<<scc[i]<<" ";
	cout<<endl;
	return 0;
}
/*
Ҫ������Ŀ��ʾ��

���룺
��һ�У�һ������N����ʾ��N�����㣬������Ϊ0��N-1��
��������N���ǳ��߱�����룬��i�б�ʾ��i������ĳ��߱�i��0��ʼ���㣩��
ÿһ��������һ������k����ʾ�ö�����k�����ߣ���������k��������
��ʾ���ߵ�Ŀ����.

���:
N����������ʾÿ��������ڵ�ǿ��ͨ��ͼ�ı�š�
ÿ��ǿ��ͨ��ͼ�ı��Ϊ����ͼ����С���ı�š�
ע�⣬�㷨�ó��ı��δ����SCC����С���ı�ţ�
��������ʱ��Ҫ����һ��ת�������ת������ͨ��ɨ��
�����㷨�õ���SCC��Ϣ�������׽����������Ҫ�����������ʵ�ֱ��ת������

ʾ����
Input��
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
