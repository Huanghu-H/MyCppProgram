#include<iostream>
#include<cmath>
using namespace std;

int n,last;
int a[200000];
int b[200000];
int c[200000];
int weizhi[200000];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		weizhi[a[i]]=i;
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(weizhi[b[i]]>last)
		{
			cout<<weizhi[b[i]]-last<<" ";
			last=weizhi[b[i]];
		}
		else
		{
			cout<<0<<" ";
		}
		
	}
	return 0;
}

