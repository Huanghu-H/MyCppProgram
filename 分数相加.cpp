#include<iostream>
#include<cmath>
using namespace std;

int n,z,m,s;
int zi[11];int mu[11];
int zxgbs=1; 

int bei(int a,int b)
{
	int max=a>b?a:b;
	int min=a>b?b:a;
	for(int i=1;i<=min;i++)
	{
		if(max*i%min==0)
		{
			return i*max;
			break;
		}
	}
}


int yue(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>zi[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		cin>>mu[i];
		zxgbs=bei(zxgbs,mu[i]);
	}
	for(int i=1;i<=n;i++)
	{
		z+=zxgbs/mu[i]*zi[i];
	}
	
	s=yue(z,zxgbs);
	//cout<<s<<z<<zxgbs; 
	if(z)cout<<z/s<<" "<<zxgbs/s<<endl;
	else cout<<0<<" "<<1<<endl;
	return 0;
}

