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
	int n1,n2,a1,a2;
	cin>>n1;
	cin>>a1;
	node *p1=new node;
	p1->no=a1;
	p1->next=NULL;
	node *head1=p1;
	node *tail1=p1;
	for(int i=1;i<n1;i++)
	{
		node *p=new node;
		int a;
		cin>>a;
		p->no=a;
		p->next=NULL;
		tail1->next=p;
		tail1=p;
	}
	cin>>n2;
	cin>>a2;
	node *p2=new node;
	p2->no=a2;
	p2->next=NULL;
	node *head2=p2;
	node *tail2=p2;
	for(int i=1;i<n2;i++)
	{
		node *p=new node;
		int a;
		cin>>a;
		p->no=a;
		p->next=NULL;
		tail2->next=p;
		tail2=p; 
	}
	tail1->next=head2;
	for(node *p=head1;p!=NULL;p=p->next)
	cout<<p->no<<endl;
	return 0;
}

