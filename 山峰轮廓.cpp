#include<iostream>
#include<cmath>
using namespace std;

int x,y,sum;
int a[101][101];
int main()
{
	cin>>x>>y;
	for(int j=1;j<=y;j++)
	{
		for(int i=1;i<=x;i++)
		{
			cin>>a[i][j];
		}
	}
	for(int j=1;j<=y;j++)
	{
		for(int i=1;i<=x;i++)
		{
			if(a[i][j])
			{
				if(i==1||a[i-1][j]==0)sum++;//left
				if(i==x||a[i+1][j]==0)sum++;//right
				if(j==1||a[i][j-1]==0)sum++;//up
				if(j==y||a[i][j+1]==0)sum++;//down
			}
		}
	}	
		
	cout<<sum;
	
	return 0;
}

