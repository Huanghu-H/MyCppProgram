#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};
int l;
node *a=NULL;
node *b=NULL;
void input()
{	
	node *head=NULL;
	node *head2=NULL;node *tail2=head2;
	for(int i=1;i<=l;i++)
	{
		int x;
		node *p=new node;
		node *p2=new node;
	 	cin>>x;
	 	p->no=x;
	 	p2->no=x;
	 	//tuocha
		if(head==NULL)
		{
			head=p;
			p->next=NULL;
		}
		else 
		{
			p->next=head;
			head=p;
		}
		//weicha
		p2->next=NULL;
		if(head2==NULL)
		{
			head2=p2;
			tail2=head2;
		}
		else 
		{
			tail2->next=p2;
			tail2=p2;
		}
	}
	a=head;
	b=head2;
}

void output()
{
	node *p=a;
	while(p->next!=NULL)
	{
		cout<<p->no<<" ";
		p=p->next;
	}
	cout<<p->no<<endl;
}
void judge()
{   int flag=1;
	while(a!=NULL)
	{
		if(a->no!=b->no)
		{
			cout<<"false"<<endl;flag=0;break;
		}
		a=a->next;
		b=b->next;
	}
	if(flag==1)cout<<"true"<<endl;
}
int main()
{
	cin>>l;
	input();
	output();
	judge();
	return 0;
}

