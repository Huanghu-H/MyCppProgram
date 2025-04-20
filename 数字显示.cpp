#include<iostream>
#include<cmath>
using namespace std;

//string chuan;
char shu[101];
int x;
int i;
int num(char a)
{
	int b;
	b=a-int('0');
	return b;
}

void hang1(int a,int i)
{
	if(a==0||a==2||a==3||a==5||a==6||a==7||a==8||a==9) cout<<"XXX";
	else if(a==1) cout<<"..X";
	else cout<<"X.X";
	if((i+1)!=x)cout<<".";
} 

void hang2(int a,int i)
{
	if(a==0||a==4||a>=8)cout<<"X.X";
	else if(a==1||a==2||a==3||a==7)cout<<"..X";
	else cout<<"X..";if((i+1)!=x)cout<<".";
}

void hang3(int a,int i)
{
	if(a==2||a==3||a==6||a==4||a==5||a==8||a==9)cout<<"XXX";
	else if(a==0)cout<<"X.X";
	else cout<<"..X"; if((i+1)!=x)cout<<".";
}

void hang4(int a,int i)
{
	if(a==0||a==6||a==8)cout<<"X.X";
	else if(a==2)cout<<"X..";
	else cout<<"..X";if((i+1)!=x)cout<<".";
}

void hang5(int a,int i)
{
	if(a==1||a==4||a==7) cout<<"..X";
	else cout<<"XXX";if((i+1)!=x)cout<<".";
}

int main()
{
	cin>>x;
	cin>>shu;
	for(int i=0;shu[i]!='\0';i++)
	{
		hang1(num(shu[i]),i);
	}
	cout<<endl;
		for(int i=0;shu[i]!='\0';i++)
	{
		hang2(num(shu[i]),i);
	}
	cout<<endl;
		for(int i=0;shu[i]!='\0';i++)
	{
		hang3(num(shu[i]),i);
	}
	cout<<endl;
		for(int i=0;shu[i]!='\0';i++)
	{
		hang4(num(shu[i]),i);
	}
	cout<<endl;
		for(int i=0;shu[i]!='\0';i++)
	{
		hang5(num(shu[i]),i);
	}
	cout<<endl;
	
	
	
	return 0;
}

