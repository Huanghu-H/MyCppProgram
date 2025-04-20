#include<iostream>
#include<cmath>
using namespace std;

int flag;
int position;
int integer[100];
char c[105];
int type;//1 整数，2 标识符 
string str[100];
int valueofidentifier[100]={0};
int indexofint=0;
int indexofstr=0;
string previousstr;
int gettoken(char x)
{
	for(int i=0;i<100;i++)c[i]='\0';
	integer[indexofint]=0;
	position=0;
	while(x>0)
	{
		if(position==0)
		{
			if(x=='+')cout<<"+"<<endl;
			else if(x=='-')cout<<"-"<<endl;
			else if(x=='*')cout<<"*"<<endl;
			else if(x=='/')cout<<"/"<<endl;
			else if(x=='=')cout<<"="<<endl;
			else if(x=='0')cout<<"integer 0"<<endl;
			else if(x>='1'&&x<='9')
			{
				type=1;integer[indexofint]=10*integer[indexofint]+((int)x-(int)'0');position++;
			}
			else if(x==' '||x=='\n');
			else
			{
				if(x<0)break;
				type=2;c[position]=x;position++;
			}
		}
		else 
		{
			if(x>='0'&&x<='9')
			{
				type=1;integer[indexofint]=10*integer[indexofint]+((int)x-(int)'0');position++;
			}
			else if(x==' '||x=='\n')
			{
				if(type==1)
				{
					indexofint++;
				}
				if(type==2)
				{
					previousstr=c;
					str[indexofstr]=c;
					int strflag=1;
					for(int i=0;i<indexofstr;i++)
					{
						if(str[i]==str[indexofstr])
						{
							c=="\0";strflag=0;
						}
					}
					if(strflag==1)indexofstr++;
				}
				position=0;
				return 1;
			}
			else 
			{
				if(x<0)break;
				type=2;c[position]=x;position++;
			}	
		}
		x=getchar();
	}
	return 0;
}

int main()
{
	char x;
	flag=1;
	while(flag)
	{
		x=getchar();
		flag=gettoken(x);
	}
	
	return 0;
}

