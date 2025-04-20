#include<iostream>
#include<cmath>
using namespace std;
/*
11 BBFFFBFBBBB
*/
int n;
int a[5005];
int b[5005];

int main()
{
	cin>>n;
	int min=n,min1=0;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='F')a[i]=1;
		else a[i]=0;
	}
	int step=0;
	int x=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n+1-k;i++)
		{
			x=x+b[i];
			b[i]=0;
			if((a[i]+x)%2==0)
			{
				step++;
				x++;
				b[i+k]=-1;
			}
		}
		int flag=1;
		for(int i=n+2-k;i<=n;i++)
		{
			x=x+b[i];
			b[i]=0;
			if((x+a[i])%2==0)
			{
				flag=-1;break;
			}
		}
		if(flag==1&&step<min)
		{
			min=step;min1=k;
		}
		x=0;
		step=0;
		for(int i=1;i<=n;i++)b[i]=0;
	}
	cout<<min1<<" "<<min;
	return 0;
} 
