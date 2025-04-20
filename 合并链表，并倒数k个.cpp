#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};
node *head=NULL; 
int daoshu;
int l1;
int l2;
void input()
{
	cin>>l1;
	node *tail=head; 
	for(int i=1;i<=l1;i++)
	{
		node *p=new node ;
		int x;
		cin>>x;
		p->no=x;
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			tail=p; 
		}
	}
	cin>>l2;
	for(int i=1;i<=l2;i++)
	{
		node *p=new node;
		int x;
		cin>>x;
		p->no=x;
		node *q=head;
		if(head->no>=x)
		{
			p->next=head;
			head=p;
			continue;
		}
		while(q->next!=NULL&&q->next->no<=x)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	} 
	//cin>>daoshu;
}

void output()
{
	node *p=head;
	while(p->next!=NULL)
	{
		cout<<p->no<<" ";
		p=p->next;
	}
	cout<<p->no;
	cout<<endl;
}

int main()
{
	input();
	output();
	return 0;
}

