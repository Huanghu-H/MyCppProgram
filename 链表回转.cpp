#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int no;
	node *next;
};

int main()
{
	//˼·��һ��ͷ�壬һ��β�壬�ж��������Ƿ�һ���� 
	int n;cin>>n;
	int a;cin>>a;
	node *p=new node;
		p->no=a;
		p->next=NULL;
	node *head1=p;
	node *head2=p;
	node *tail2=p;
	 
	for(int i=1;i<n;i++)
	{
		//ͷ
		node *ph=new node;
		int b;
		cin>>b;
		ph->no=b;
		ph->next=head1;
		head1=ph;
		//β 
		node *pt=new node;
		pt->no=b;
		pt->next=NULL;
		tail2->next=pt;
		tail2=pt;
	}
	//outputͷ�� 
	node *outp=head1;
	node *q=head2;
	int flag=0;
	for(;q!=NULL;outp=outp->next,q=q->next)
	{
		cout<<outp->no<<" ";
		if(q->no!=outp->no)flag=-1;	
	}
	cout<<"\n"; 
	if(flag==-1)cout<<"false\n";
	else cout<<"true\n";
	while(head1!=NULL)
	{
		node *pp=head1;
		head1=head1->next;
		delete pp;
	}
	return 0;
}

