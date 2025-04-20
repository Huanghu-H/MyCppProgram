#include<iostream>
#include<cmath>
using namespace std;

int a[25];
int n,k; 
int p[25];

int f(int i,int p[])
{
	if(k==3)
	{
		int k1=0,k2=0,k3=0;
		k1=p[max(i-2,1)]+p[max(1,i-1)]+p[i];
		k2=p[max(i-1,1)]+p[i]+p[min(i+1,n)];
		k3=p[i]+p[min(n,i+1)]+p[min(i+2,n)];
		if(k1>=2&&k2>=2&&k3>=2)return 1;
		else return 0;
	}
}

int main()
{
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];sum+=a[i];
	}
	int ans=0;
	int min=sum;
	for(int i=1;i<=(int)pow(2,n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[j]=(i/(int)pow(2,j-1))%2;
		}
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(f(j,p)==1)ans+=a[j];
			else flag=-1;
		}
		if(ans<min&&flag==0)min=ans;
	}
	cout<<min; 
	return 0;
}

