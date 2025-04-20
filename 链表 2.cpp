#include<iostream>
#include<cmath>
using namespace std;
//单链表
//链表程序的主题结构 
struct node
{
	int no;
	node *next; 
};

node *head=NULL;//初始为空值 

node *list()//建立链表 
{
	node *head=NULL;
	node *p=new node;
	p->no=1;
	//头插 
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
	//依次插入节点；建立链表 
	//尾插
	node *q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	} 
	q->next=p;
	p->next=NULL;
	//i的后面个插入
	//输入i 
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
	//输出没有；
	return head; 
}

void output(node *head)//输出 
{
	for(node* p=head;p!=NULL;p=p->next)
	{
		cout<<p->no<<endl;
	} 
}

void de(node *head)
{
	//删除头节点 
	node *p=head;
	head=head->next;
	delete p;
	//删除尾节点
	node *q1=NULL;
	node *q2=head;
	while(q2->next!=NULL)
	{
		q1=q2;
		q2=q2->next;
	}
	//如果只有一个节点；
	if(q1==NULL)
	{
		head=NULL;
	} 
	else 
	{
		q1->next=NULL;
	}
	delete q2;
	//删除第i个节点
	int i=0; 
	if(i==1)
	;//略
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
		//没有第i个节点 
	} 
	 
	
}

void delete1(node *head)//删除，释放 
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
////单链表
////链表程序的主题结构 
//
//
//node *list()//建立链表 
//{
//	node *head=NULL;
//	node *p=new node;
//	p->no=1;
//	//头插 
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
//	//依次插入节点；建立链表 
//	//尾插
//	node *q=head;
//	while(q->next!=NULL)
//	{
//		q=q->next;
//	} 
//	q->next=p;
//	p->next=NULL;
//	//i的后面个插入
//	//输入i 
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
//	//输出没有；
//	return head; 
//}
//
//void output(node* head)//输出 
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
//void delete1(node *head)//删除，释放 
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
//12.1授课
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
	;//未找到 
}
//链表的反转
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

 
 









