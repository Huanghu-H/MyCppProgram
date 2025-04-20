#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};
node *head=NULL;
int re;
void input()
{
	int l;
	cin>>l;
	for(int i=1;i<=l;i++)
	{
		int x;cin>>x;
		node *p=new node;
		p->no=x;
		if(i==1)
		{
			head=p;
			p->next=NULL;
		}
		else 
		{
			p->next=head;head=p;
		}
	}
	cin>>re;
} 

void output()
{
	node *p=head;
	while (p->next!=NULL)
	{
		if(p->no==re) 
		{
			p=p->next;
		}
		else 
		{
			cout<<p->no<<" ";p=p->next;
		}
	} 
	if(p->no!=re)cout<<p->no<<endl;
}

int main()
{
	input();
	output();
	return 0;
}

