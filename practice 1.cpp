#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

struct node
{
	int no;
	node *next;
};

node *head=NULL;

node *clisttou()
{
	node *head=NULL;
	node *p=new node;
	int a;
	cin>>a;
	p->no=a;//toucha
	if(head==NULL)
	{
		head=p;
		p->next=NULL;
	}
	else
	{
		p->next=head;
		p=head; 
	}
	return head;
}
node *clistwei(node *head)
{
	int a;
	cin>>a;
	 
	node *pin=new node;
	pin->no=a;
	node *p1=head;
	while(p1->next!=NULL)
	{
		p1=p1->next;
	}
	p1->next=pin;
	pin->next=NULL;
	return p1;
}
node *clisti(node *head)//错的 
{
	
	int a,i;//在第i个后插入元素a 
	cin>>i>>a;
	int counter=1;
	node *pin=new node;
	node *p=head;
	pin->no=a;
	while(counter<i&&p->next!=NULL)
	{
		p=p->next;
		counter++;
	}//找到第i个元素；
	if(counter==i)//也有可能找不到 
	{
		p->next=pin->next;
		pin->next=p;
	} 
	return head;
}

void output(node *head)
{
	node *p=head;
	for(;p!=NULL;p=p->next)
	cout<<p->no<<endl;
}

void delete1(node *head)
{
	while(head)
	{
		node *current=head;
		head=head->next;
		delete current;
	}
}
int main()
{
	node *head=clisttou();
	head=clistwei(head);
//	head=clisti(head);	
	output(head);
//	delete1(head);
	return 0;
}
