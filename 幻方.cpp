#include<iostream>
#include<cmath>
using namespace std;

int a[101][101];
int n; 
int i,j;

int main()
{
	cin>>n;
	if(n%2==0)
	{
		int step=1;
		for(i=1;i<=n/2;i++)
		{
			for(j=1;j<=n/2;j++)
			{
				if(abs(i-j)%2==0)
				{
				
				a[i][j]=-1;
				a[n+1-i][j]=-1;
				a[i][n+1-j]=-1;
				a[n+1-i][n+1-j]=-1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==-1)
				{
				
					a[i][j]=n*n+1-step;
					a[n+1-i][n+1-j]=step;
					step++;
				}
				 else if(a[i][j]==0)
				{
					a[i][j]=step;
					step++;
				}
				else step++;
			}
			
			
		}		
	}
	
	else
	{	i=1;
		j=(n+1)/2;
		a[1][(n+1)/2]=1;
		for(int step=2;step<=n*n;step++)

		{
			if(i==1)
			{
				
				i=n;
				if(j==n)
				{
					i=2;j=n;
//					j=1;
//					if(a[i][j]!=0)
//					{
//						i=i+2;
//						j=j-1;
//					}
					a[i][j]=step;
					//cout<<i<<j<<endl; 
				}
				else
				{
					j=j+1;
					if(a[i][j]!=0)
					{
						i=i+2;
						j=j-1;
					}
					a[i][j]=step;
					//cout<<i<<j<<endl; 
				}
			}
			else
			{
				i=i-1;
				if(j==n)
				{
					j=1;
					if(a[i][j]!=0)
					{
						i=i+2;
						j=j-1;
					}
					a[i][j]=step;
					//cout<<i<<j<<endl; 
				}
				else
				{
					j=j+1;
					if(a[i][j]!=0)
					{
						i=i+2;
						j=j-1;
					}
					
					a[i][j]=step;
					//cout<<i<<j<<endl; 
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

