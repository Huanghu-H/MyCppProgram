#include<iostream>
#include<cmath>
using namespace std;
int q,w,e,r,yi,er;
int n;
int b[1000][1000];
int a[1000][1000];
int main()
{
	cin>>n;
	cin>>yi>>er;
	q=yi/10;
	w=yi%10;
	e=er/10;
	r=er%10;
	a[1][1]=q;
	a[1][2]=w;
	a[2][1]=e;
	a[2][2]=r;
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=pow(2,i);x++)
		{
			for(int y=1;y<=pow(2,i);y++)
			{
				if(a[x][y]==1)
				{
					b[2*x-1][2*y-1]=q;
					b[2*x-1][2*y]=w;
					b[2*x][2*y-1]=e;
					b[2*x][2*y]=r;
				}
				else
				{
					b[2*x-1][2*y-1]=0;
					b[2*x-1][2*y]=0;
					b[2*x][2*y-1]=0;
					b[2*x][2*y]=0;
				}
			}
		}
		for(int j=1;j<=(int)pow(2,i+1);j++)
		{
			for(int k=1;k<=(int)pow(2,i+1);k++)
			{
				a[j][k]=b[j][k];
				b[j][k]=0;
			}
		}
	}
	for(int i=1;i<=(int)pow(2,n+1);i++)
	{
		for(int j=1;j<=(int)pow(2,n+1);j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}

