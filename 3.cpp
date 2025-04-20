#include<iostream>
#include<cmath>
using namespace std;
int in;
int a[150][150];
int n;

void squire(int in)
{
	for(int i=1;i<=(in+1)/2;i++)
	{
		for(int j=1;j<=(in+1)/2;j++)
		{
		
			if(i<j)a[i][j]=i;
			else a[i][j]=j;
			a[in+1-i][in+1-j]=a[i][j];
			a[i][in+1-j]=a[i][j];
			a[in+1-i][j]=a[i][j];
		}
	}
	for(int i=1;i<=in;i++)
	{
		for(int j=1;j<=in;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	while(1)
	{
	
	cin>>n;
	if(n==0)break;
	squire(n);
	
	}
	return 0;
}

