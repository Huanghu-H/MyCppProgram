#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};

node *input()
{
	int x;
	cin>>x;
	node *tail;
	node *head=NULL;
	while(x!=-1)
	{
		node *p=new node;
		p->no=x;
		p->next=NULL;//00000000000000000000000000忘了 
		if(head==NULL)
		{
			head=tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
		cin>>x;
	}
	return head;
}

void output(node *head)
{
	for(node *p=head;p!=NULL;p=p->next)
	cout<<p->no<<" ";
}

void sort(node *head)
{
	if(head==NULL||head->next==NULL)
	return ;
	node *p=head;//用来遍历 
	int max;
	for(;p->next!=NULL;p=p->next)
	{
		node *pmin=p;
		for(node *p2=p->next;p2!=NULL;p2=p2->next)
		{
			if(p2->no<pmin->no)pmin=p2;
		}
		if(pmin!=p)//只交换内容 
		{
			int t=p->no;
			p->no=pmin->no;
			pmin->no=t; 
		}
	}
}

void remove(node *head)
{
	while(head!=NULL)
	{
		node *p=head;
		head=head->next;
		delete p;
	}
}
int main()
{	
    node *head;
	head=input();
	sort(head);
	output(head);
	remove(head);
	return 0;
}

