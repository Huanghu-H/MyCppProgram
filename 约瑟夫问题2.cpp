#include<iostream>
#include<cmath>
using namespace std;

class node
{
	public:
		int index;
		node *next;
} ;

int m,s,n;
node *first=new node;
node *last=first;

void creat(int m)
{	
	first->index=1;
	for(int i=1;i<m;i++)
	{
		node *p=new node;
		p->index=i+1;
		last->next=p;
		last=p;
	}	
	last->next=first;
}

void calc(int begin,int interval)
{
	int n_of_chdrn=m;
	node *prev=last;
	for(int i=0;i<begin;i++)
	{
		prev=prev->next;
	}
	while(n_of_chdrn>1)
	{
		for(int count=1;count<interval;count++)prev=prev->next;
		node *p=prev->next;
		prev->next=p->next;
		cout<<p->index<<" ";
		delete p;
		n_of_chdrn--;
	}
	cout<<prev->index<<endl;
	delete prev;
}


int main()
{
	cin>>m>>n;
	creat(m);
	calc(1,n);
	return 0;
}

