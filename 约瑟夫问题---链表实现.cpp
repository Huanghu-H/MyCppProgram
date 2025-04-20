#include<iostream>
#include<cmath>
using namespace std;

int n,m;//n=人数；m=数； 
struct node
{
	int no;
	node *next;
};

node *input()
{
	node *head;
	node *tail;
	node *p=new node;//000000000000000000注意！！创建新的动态变量 
		p->no=0;
		p->next=NULL;
		tail=p;
		head=p;

	for(int i=1;i<n;i++)
	{
		node *p=new node;
		p->no=i;
		p->next=NULL;
		tail->next=p;
		tail=p;
	}
	tail->next=head;
	return head;
} 

void output(node *head)
{
	for(node *p=head;p!=NULL;p=p->next)
	{
		cout<<p->no<<endl;
	}
}

int main()
{
	cin>>n>>m;
	node *head;
	head=input();
	int ans;
	node *p=head;//用来遍历 
	int i=1;
	int remained=n;
	while(remained>0)
	{
		while(i<m-1)
		{
			p=p->next;
			i++; 
		}
		i=0;
		ans=p->no;
		node *q=p->next;
		p->next=q->next;
		delete q;
		remained--;
	}
//	output(head);
	cout<<ans;
	return 0;
}

