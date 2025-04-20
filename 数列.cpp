#include<iostream>
#include<cmath>
using namespace std;

int n,k,flag,sum;
int a[101];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-k;i++)
	{
		
		for(int j=i;j<=k+i-1;j++)
		{
		//	cout<<'h'<<" ";	
			if(a[j]<2*a[j+1])
			{
			
				flag=1;
			}
			else
			{
				flag=0;break;
			}
		}
		if(flag==1)
		{
			flag=0;
			sum++;
		}
	}
	
	cout<<sum; 
	return 0;
}

