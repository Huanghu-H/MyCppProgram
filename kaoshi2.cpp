#include<iostream>
#include<cmath>
using namespace std;

int a[55][55];
int x,y;



int main()
{
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int k=1;k<50;k++)
	{
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				if(a[i][j]==1)
				{
					//cout<<"AAA";
					if(i>1&&a[i-1][j]==0)a[i-1][j]=1;
					if(i<x&&a[i+1][j]==0)a[i+1][j]=1;
					if(j>1&&a[i][j-1]==0)a[i][j-1]=1;
					if(j<y&&a[i][j+1]==0)a[i][j+1]=1;
				}
			}
		}
	}
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<y;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<a[i][y];
		cout<<endl;
	}
	return 0;
}

