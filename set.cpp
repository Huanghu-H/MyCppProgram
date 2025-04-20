#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

char a[1000];
int b[1000];
int chongfu;
string str[20];
int n=0;

int size(char a[])
{
	int i;
	for( i=1;a[i]!='\0';i++);
	return i;
}

int main()
{
	cin>>a;
	int s=size(a);
	for(int i=0;i<s-6;i++)
	{
		for(int j=i+1;j<=s-6;j++)
		{
			int k=0;
			while(k<6&&a[i+k]==a[j+k])
			{
				k++;
			}
			
			
			if(k==6&&a[i]==a[i+1])
			{
				int flag=0;
				string m={a[i],a[i+1],a[i+2],a[i+3],a[i+4],a[i+5],'\0'};
				//cout<<m<<endl;
				for(int x=0;x<=n;x++)
				{
					if(m==str[x])flag=-1; 
				}
				if(flag==0)
				{
					str[n]=m;
					n++;
				}
				
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<str[i]<<endl;
	
	
	
	//cout<<s<<endl;
	return 0;
}

