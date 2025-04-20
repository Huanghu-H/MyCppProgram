#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
} ;

node *inputh()//Í·²å 
{
	int a=-1;
	cin>>a;
	node *head=NULL; 
	while(a!=-1)
	{
		node *p=new node;
		p->no=a;
		if(head==NULL)
		{
			head=p;
			head->next=NULL;
		}
		else 
		{
			p->next=head;
			head=p;
		}
		cin>>a;
	}
	return head;
}
node *inputt()//Î²²å 
{
	int a=0;
	cin>>a;
	node *head=NULL;
	node *tail=head;
	while (a!=-1)
	{
		node *p=new node;
		p->no=a;
		p->next=NULL; 
		if(head==NULL)
		{
			head=p;
			tail=p;
		}
		else 
		{	
			tail->next=p;tail=p;	
		}
		cin>>a;
	}
	return head;
} 

void output(node *x)//Êä³ö 
{
	while(x!=NULL)
	{
		cout<<x->no<<endl;
		x=x->next;
	}
}
void remove(node *x)//delete 
{
	while(x!=NULL)
	{
		node *p=new node;
		p=x;
		x=x->next;
		delete p;
	}
}
int main()
{
	//node *a=inputh();
	node *a=inputt();
	output(a);
	remove(a);
	return 0;
}

