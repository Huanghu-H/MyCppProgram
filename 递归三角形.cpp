#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[1000][1000];

int main()
{
	cin>>n;
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int x=1;x<=pow(2,i-2);x++)
		{
			for(int y=1;y<=pow(2,i-2);y++)
			{
				if(a[x][y]==1)
				{
					a[x][y+int(pow(2,i-2))]=1;
					a[x+int(pow(2,i-2))][y]=1;
				}
			}
		}
	}
	for(int i=1;i<=(int)pow(2,n-1);i++)
	{
		for(int j=1;j<=(int)pow(2,n-1);j++)
		{
			if(a[i][j]==1)
			{
				cout<<"* ";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	return 0;
}

