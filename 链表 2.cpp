#include<iostream>
#include<cmath>
using namespace std;
//������
//������������ṹ 
struct node
{
	int no;
	node *next; 
};

node *head=NULL;//��ʼΪ��ֵ 

node *list()//�������� 
{
	node *head=NULL;
	node *p=new node;
	p->no=1;
	//ͷ�� 
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
	//���β���ڵ㣻�������� 
	//β��
	node *q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	} 
	q->next=p;
	p->next=NULL;
	//i�ĺ��������
	//����i 
	int i=3;
	node *q1=head;
	int j=1;
	while(j<i&&q1->next!=NULL)
	{
		q1=q1->next;
		j++;
	} 
	//
	if(j==i)
	{
		p->next=q1->next;
		q1->next=p;
	}
	else
	//���û�У�
	return head; 
}

void output(node *head)//��� 
{
	for(node* p=head;p!=NULL;p=p->next)
	{
		cout<<p->no<<endl;
	} 
}

void de(node *head)
{
	//ɾ��ͷ�ڵ� 
	node *p=head;
	head=head->next;
	delete p;
	//ɾ��β�ڵ�
	node *q1=NULL;
	node *q2=head;
	while(q2->next!=NULL)
	{
		q1=q2;
		q2=q2->next;
	}
	//���ֻ��һ���ڵ㣻
	if(q1==NULL)
	{
		head=NULL;
	} 
	else 
	{
		q1->next=NULL;
	}
	delete q2;
	//ɾ����i���ڵ�
	int i=0; 
	if(i==1)
	;//��
	else
	{
		node *p=head;
		int j=1;
		while(j<i-1)
		{
			if(p->next==NULL)
			{
				break;
			}
			p=p->next;
			j++;
		}
		if(p->next=NULL)
		{
			node *q=p->next;
			p->next=q->next;
			delete q;
			
		}
		else;
		//û�е�i���ڵ� 
	} 
	 
	
}

void delete1(node *head)//ɾ�����ͷ� 
{
	while(head)
	{
		node *current=head;
		head=head->next;
		delete current;
		//free(no);
	}
}
//-----------------------------------------------
int main()
{
	node *head=list();  
	
 
	output(head);
	delete1(head);
	return 0;
}
//-----------------------------------------------
//#include<iostream>
//#include<cmath>
//using namespace std;
////������
////������������ṹ 
//
//
//node *list()//�������� 
//{
//	node *head=NULL;
//	node *p=new node;
//	p->no=1;
//	//ͷ�� 
//	if(head==NULL)
//	{
//		head=p;
//		p->next=NULL;
//	}
//	else
//	{
//		p->next=head;
//		head=p;
//	}
//	//���β���ڵ㣻�������� 
//	//β��
//	node *q=head;
//	while(q->next!=NULL)
//	{
//		q=q->next;
//	} 
//	q->next=p;
//	p->next=NULL;
//	//i�ĺ��������
//	//����i 
//	node *q=head;
//	int j=1;
//	while(j<i&&q->next!=NULL)
//	{
//		q=q->next;
//		j++;
//	} 
//	//
//	if(j===i)
//	{
//		p->next=q->next;
//		q->next=p;
//	}
//	else
//	//���û�У�
//	return head; 
//}
//
//void output(node* head)//��� 
//{
//	for(node* p=head;p!=NULL;p=p->next)
//	{
//		cout<<p->no<<endl;
//	} 
//}
//
//
//
//
//void delete1(node *head)//ɾ�����ͷ� 
//{
//	while(head)
//	{
//		node *current=head;
//		head=head->next;
//		delete current;
//		//free(no);
//	}
//}
////-----------------------------------------------
//int main()
//{
//	node *head=list();   
//	output(head);
//	delete1(head);
//	return 0;
//}
//---------------------------------------------------
//
//
//12.1�ڿ�
// 
//
void jiansuoa(node *head)
{
	int a;
	cin>>a;
	int index=0;
	node *p=head;
	for(;p!=NULL;index++)
	{
		if(p->no==a)break;
		p=p->next;
	}
	if(p!=NULL)
	{
		cout<<"zhaodao "<<index<<" "<<a<<endl;
	}
	else
	;//δ�ҵ� 
}
//����ķ�ת
node *reverse(node *head)
{
	node *pre=NULL;
	node *now=NULL;
	node *next=head;
	while(next!=NULL)
	{
		pre=now;
		now=next;
		next=now->next;
		now->next=pre;
	}	
} 

 
 









