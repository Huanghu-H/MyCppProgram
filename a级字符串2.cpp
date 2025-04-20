#include<iostream>
#include<cmath>
using namespace std;
/*
9
b
bc
bbcd
bbbbccde
aabcbbbb
ccde
bbce
bbaa
bbbbccdc

Êä³ö
b
b
b
b
b
c
0
0
0
*/
int len(char b[])
{
	int i=0;
	for(;b[i]!='\0';i++);
	return i;
}

int n;
char a[10005][129];
char ans[10005];

int xt(char b[])
{
	for(int i=0;i<len(b);i++)
	{
		if(b[i]!=b[0])return -1;
	}
	return 1;
}
char ji(char b[])
{
	if(len(b)==1)return b[0];
	else if(len(b)==2)
	{
		if(b[1]==(char)((int)b[0]-1)||b[1]==(char)((int)b[0]+1))
		return min(b[0],b[1]);
		else return '\0';
	}
	else 
	{
		char cl[111],cr[111];
		for(int i=0;i<111;i++)
		{
			cl[i]='\0';cr[i]='\0';
		} 
		for(int i=0;i<len(b)/2;i++)cl[i]=b[i];
		for(int i=0;i<len(b)/2;i++)cr[i]=b[i+len(b)/2];
		if(xt(cl)==1)
		{
			if((int)ji(cr)==(int)cl[0]+1||(int)ji(cr)==(int)cl[0]-1)
			return cl[0];
			else return '\0';
		}
		else if(xt(cr)==1)
		{
			if((int)ji(cl)==(int)cr[0]+1||(int)ji(cl)==(int)cr[0]-1)
			return cr[0];
			else return '\0';
		}
		else return '\0';
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ji(a[i])!='\0')cout<<ji(a[i])<<endl;
		else cout<<0<<endl;
	}
	return 0;
}

