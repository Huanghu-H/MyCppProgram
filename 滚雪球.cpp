#include<iostream>
#include<cmath>
using namespace std;

int x,y;
char a[55][55]={'a'};

int main()
{
	cin>>x>>y;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
		cin>>a[i][j];
	for(int step=1;step<=x*x;step++)
	{
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=y;j++)
			{
				if(a[i][j]=='o'&&a[i+1][j]=='.')
				{
					a[i][j]='.';
					a[i+1][j]='o';
				}
			}
		}
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		cout<<a[i][j];
		cout<<endl;
	}
	
	
	return 0;
}

