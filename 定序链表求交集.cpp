#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int value;
	node *next;
} ;

node *headl1=new node;
node *headl2=new node;
node *headans=new node;
node *tailans=new node;

int position=0;

void input()
{
	int l1,l2;
	cin>>l1>>l2;
	node *taill1=new node;
	taill1=headl1;
	node *taill2=new node;
	taill2=headl2; 
	for(int i=0;i<l1;i++)
	{
		int x;cin>>x;
		if(i==0)
		{
			headl1->next=taill1;
			taill1->value=x;
			taill1->next=NULL;
		}
		else
		{
			node *nl1=new node;
			taill1->next=nl1;
			nl1->value=x;
			nl1->next=NULL;
			taill1=nl1;
		}
	}
	for(int i=0;i<l2;i++)
	{
		int x;cin>>x;
		if(i==0)
		{
			headl2->next=taill2;
			taill2->value=x;
			taill2->next=NULL;
		}
		else
		{
			node *nl2=new node;
			taill2->next=nl2;
			nl2->value=x;
			nl2->next=NULL;
			taill2=nl2;
		}	
	}
}
void insert_v(int v)
{
	if(position==0)
	{
		headans->next=tailans;
		tailans->value=v;
		tailans->next=NULL;
		position++;
	}
	else
	{
		node *n=new node;
		tailans->next=n;
		n->value=v;
		n->next=NULL;
		tailans=n;
		position++;
	}
}
void intersection()
{
	node *nl1=headl1;
	node *nl2=headl2;
	while(nl2!=NULL&&nl1!=NULL)
	{
		if(nl1->value<nl2->value)
		{
			insert_v(nl1->value);nl1=nl1->next;
		}
		else if(nl1->value>nl2->value)
		{
			insert_v(nl2->value);nl2=nl2->next; 
		}
		else 
		{
			insert_v(nl1->value);nl1=nl1->next;nl2=nl2->next; 
		}
	}
	if(nl2==NULL)
	{
		while(nl1!=NULL)
		{
			insert_v(nl1->value);nl1=nl1->next;
		}
	}
	else if(nl1==NULL)
	{
		while(nl2!=NULL)
		{
			insert_v(nl2->value);nl2=nl2->next;
		}
	}
} 


void output()
{
	node *n=headans;
	while(n!=NULL)
	{
		cout<<n->value<<" ";
		n=n->next;
	}
} 

// 3 4 1 2 3 2 3 4 5
int main()
{
	input();
	tailans=headans;
	intersection();
	output();
	return 0;
}

