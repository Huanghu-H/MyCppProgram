#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int n;
int flag=0;
char a[10000]={'\0'}; 
//ToDo
char* GetStrings()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
	char *p=a;
    return p;
}
//ToDo
//Attention!! str_list[i] is forbidden!!
void Func(char* str_list)
{
	char *head=str_list;
	char *tail=str_list+strlen(str_list)-1;
	for(int i=n-1;i>=0;i--)
	{
		if(i==0)
		{
			char *p1=head;
			char *p2=tail;
			int y=0;
			for(;p1<p2;p1++,p2--)
			{
				if(*p1!=*p2)
				{
					y=-1;break;
				}
			}
			if(y==-1)continue;
			for(int k=0;k<n;k++)cout<<a[k]<<" ";
			flag=-1;return; 
		}
		else 
		{
			
			if(i*2>n)
			{
				char *p1=head+i;
				char *p2=p1-1;
				int y=0;
				int j=0;
				for(;j<=n-i-1;j++)
				{
					p1=head+i+j;
					p2=head+i-j-1;
					if(*p1!=*p2)
					{
						y=-1;break;
					}
				}
				if(y==-1)continue;
				p2--;p1=head;
				for(;p1<p2;j++)
				{
					if(*p1!=*p2)
					{
						y=-1;break;
					}
					p2--;p1++;
				}
				if(y==-1)continue;
				flag=-1;
				for(char *p=head+i;*p!='\0';p++)cout<<*p<<" ";
				for(char *p=head;p!=head+i;p++)cout<<*p<<" ";
				return;
				
			}
			else
			{
				char *p1=head+i;
				char *p2=p1-1;
				int y=0;
				int j=0;
				for(;j<i;j++)
				{
					p1=head+i+j;
					p2=head+i-1-j;
					if(*p1!=*p2)
					{
						y=-1;break;
					}
				}
				if(y==-1)continue;
				p2=tail;p1++;
				for(;p1<p2;j++)
				{
					p1=head+i+j;
					if(*p1!=*p2)
					{
						y=-1;break;
					}
					p2=p2-1;
				}
				if(y==-1)continue;
				flag=-1;
				for(char *p=head+i;*p!='\0';p++)cout<<*p<<" ";
				for(char *p=head;p!=head+i;p++)cout<<*p<<" ";
				return;
			}
		}
	
	}
	if(flag==0)cout<<"False";
}

int main()
{
    char* str_list = GetStrings();
    Func(str_list);
    return 0;
}
