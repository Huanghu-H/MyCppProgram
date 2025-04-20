#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};

int main()
{
	int n;cin>>n;
	int a;cin>>a;
	node *p=new node;
		p->no=a;
		p->next=NULL;
	node *head1=p;
	node *head2=p;
	node *tail2=p;
	for(int i=1;i<n;i++)
	{
		node *ph=new node;
		int b;
		cin>>b;
		ph->no=b;
		ph->next=head1;
		head1=ph;
		node *pt=new node;
		pt->no=b;
		pt->next=NULL;
		tail2->next=pt;
		tail2=pt;
	}
	node *outp=head1;
	for(;outp!=NULL;outp=outp->next)
		cout<<outp->no<<" ";
	return 0;
}

