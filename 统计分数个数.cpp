#include<iostream>
#include<cmath>
using namespace std;

int n,flag;
int shu=0;
int shu2=0;
//int zi[105];mu[105];

void f(int zi,int mu)
{
	while(zi!=0)
	{
		mu=mu%zi;
		int t=zi;
		zi=mu;
		mu=t;
	}
	if(mu==1)
	{
		shu++;
		flag=1;
	}

}

void g(int zi,int mu)
{
	if(flag==1)
	{
		int c1=0;int c2=0;
		for(int i=2;i*i<=zi;i++)
		{
			if(zi%i==0)
			{
				c1=-1;break;
			}
			
		}
		for(int i=2;i*i<=mu;i++)
		{
			if(mu%i==0)
			{
				c2=-1;break;
			}
			
		}
		if(c1==0&&c2==0&&zi!=1)
		shu2++;
	}
}


int main()
{
	cin>>n;
	
	for(int mu=2;mu<=n;mu++)
	{
		for(int zi=1;zi<mu;zi++)
		{
			f(zi,mu);
			g(zi,mu);
		}
	}
	cout<<shu<<' '<<shu2;
	return 0;
}

