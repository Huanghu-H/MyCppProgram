#include<iostream>
#include<cmath>
using namespace std;

int a[12];
int n,n1,wei;
int c,flag,z; 

int main()
{
	cin>>n;
	if(n<0)
	{
		flag=-1;n=-n;
	}
	for(int i=1;i<=10;i++)
	{
		int p=pow(10,i-1);
		if(n/p!=0)wei=i;
		c=n/pow(10,i-1);
		a[i]=c%10;
	}
	n1=n;
	for(int i=1;i<=10;i++)
	{
		if(n1%10==0&&n1>=10)
		{
			n1=n1/10;z++;
		}
	}
	//cout<<z<<" guhuhu";
	//cout<<wei;
	if(flag==-1)cout<<"-";
	if(wei!=1&&wei!=0)
	{
		cout<<a[wei];
		if(wei-1-z)cout<<".";
		for(int i=wei-1;i>=1+z;i--)
		{
			cout<<a[i];
		}
		cout<<"e"<<wei-1;
	}
	if(wei==1&&n!=0)
	cout<<n<<"e"<<0;
	if(n==0)
	cout<<0;
	return 0;
}

