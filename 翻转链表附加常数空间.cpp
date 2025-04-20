#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int value;
	node *next;
};

node *head1=new node;
node *head2=new node;

void input()
{
	int l1;
	cin>>l1;
	node *tail1=new node;
	tail1=head1; 
	for(int i=0;i<l1;i++)
	{
		int x;cin>>x;
		if(i==0)
		{
			head1->next=tail1;
			tail1->value=x;
			tail1->next=NULL;
		}
		else
		{
			node *n1=new node;
			tail1->next=n1;
			n1->value=x;
			n1->next=NULL;
			tail1=n1;
		}
	}
}

void reverse()
{
	node *tail2=new node;
	tail2->value=head1->value;
	tail2->next=NULL;
	head2=tail2;
	tail2=head2;
	for(node *p=head1->next;p!=NULL;p=p->next)
	{
		node *q=new node;
		q->value=p->value;		
		q->next=head2;
		head2=q;
	}	
}

void output()
{
	node *p=head2;
	while(p!=NULL)
	{
		cout<<p->value<<" ";
		p=p->next;
	}
}

int main()
{
	input();
	reverse();
	output();
	return 0;
}

