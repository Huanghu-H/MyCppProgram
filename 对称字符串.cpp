#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
//ToDo
int n;int flag=0;
char* GetStrings()
{
    cin>>n;
    char* a=new char[100];
    getchar();
    gets(a);
    return a;
}
//ToDo
//Attention!! str_list[i] is forbidden!!
void Func(char* str_list)
{
	char *p1=str_list;//head
	char *p2=str_list+strlen(str_list)-1;//tail
	for(;*(p1+1)!='\0';p1=p1+2)
	{
		if(p1==str_list)
		{
			char *head=p1;
			char *tail=p2;
			int y=0;
			for(;head<tail;head=head+2,tail=tail-2)
			{
				if(*head!=*tail){
				y=-1;break;}
			}
			if(y==-1)continue;
			cout<<str_list<<endl;
			flag=1;return; 
			
		}
		else
		{
			char* tail=p1-2;
			char* head=p1;
			int y=0;
			//cout<<*head<<'h'<<*tail<<'t'<<endl;
			for(;tail!=str_list,*(head+1)!='\0';tail=tail-2,head=head+2)
			{
				if(*tail!=*head)
				{
					y=-1;break;
				}
			}
			if(y==-1)continue;
			if(tail==str_list)
			{
				if(*tail!=*head)continue;
				tail=p2;head=head+2;
				for(;head<tail;head=head+2,tail=tail-2)
				{
					if(*head!=*tail)
					{
						y=-1;break;
					}
				}
				if(y==-1)continue;
			}
			else
			{
				char *hhh=str_list;
				char *ttt=tail;
				for(;hhh<ttt;ttt=ttt-2,hhh+=2)
				{
					if(*head!=*tail)
					{
						y=-1;break;
					}
				}
				if(y==-1)continue;
				
			}
			
			char *aaa=p1;
			for(;*(p1+1)!='\0';p1=p1+2)
				cout<<*p1<<" ";
				cout<<*p2<<" ";
			for(char *bbb=str_list;bbb<aaa;bbb+=2)
				cout<<*bbb<<" ";
			flag=1;return;
		}
	}
	if(flag==0)cout<<"False"<<endl;return;
}

int main()
{
    char* str_list = GetStrings();
    Func(str_list);
}
