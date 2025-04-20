#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[50000];
int b[50000]={0};
int c[50000];
int main()
{
	a[0]=1;
	c[0]=1;
	cin>>n;
	a[1]=1;c[1]=1;
	for(int j=1;j<=n;j++)
	{
		for(int i=1;c[i]!=0;i++)
		{
			a[i]=a[i]*2;
			if(b[i]==1)
			{
				b[i]=0;a[i]++;
			}
			if(a[i]>=10)
			{
				if(a[i+1])
				{
					a[i]-=10;
					b[i+1]++;
				}
				else 
				{
					a[i]-=10;
					a[i+1]=1;
					c[i+1]=1;
					i++;
				}
				
			}
			//cout<<a[3]<<a[2]<<a[1]<<endl;
		}
	}
	int len=1;
	for(;c[len]!=0;len++);
	for(int i=1;i<=len;i++)
	if(i!=1)cout<<a[len+1-i];
	return 0;
}

