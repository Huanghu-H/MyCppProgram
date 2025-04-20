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
0*/
#include<iostream>
#include<cmath>
using namespace std;

int n;
char a[3005][129];

int f(char b[])
{
	int p=0;int i=128;
	for(;i>=0;i--)
	{
		if(b[i]!='\0')break;
	}
	if(i==127);
}
char g(char a[])
{
	
} 

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	//if(f(a[i],i)==1)cout<<g(a[i])<<endl;	
	cout<<a[i]<<endl;
	return 0;
}

