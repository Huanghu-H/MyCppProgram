#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int value;
	node *next;
} ;

node *headl=new node;
node *headp=new node;

void input()
{
	int l,p;
	cin>>l>>p;
	node *taill=new node;
	taill=headl;
	node *tailp=new node;
	tailp=headp;
	for(int i=0;i<l;i++)
	{
		int x;cin>>x;
		if(i==0)
		{
			headl->next=taill;
			taill->value=x;
			taill->next=NULL;
		}
		else
		{
			node *nl=new node;
			taill->next=nl;
			nl->value=x;
			nl->next=NULL;
			taill=nl;
		}
	}
	for(int i=0;i<p;i++)
	{
		int x;cin>>x;
		if(i==0)
		{
			headp->next=tailp;
			tailp->value=x;
			tailp->next=NULL;
		}
		else
		{
			node *np=new node;
			tailp->next=np;
			np->value=x;
			np->next=NULL;
			tailp=np;
		}	
	}
}
void printlots()
{
	int indexl=1;
	node *np=headp;
	node *nl=headl;
	while(np!=NULL)
	{
		if(np->value==indexl)
		{
			cout<<nl->value<<" ";
			np=np->next;
			nl=nl->next;indexl++;
		}
		else 
		{
			nl=nl->next;indexl++;
		}
	}
}

//7 4 1 2 3 4 5 6 7 1 3 4 6
int main()
{
	input();
	printlots();
	return 0;
}

