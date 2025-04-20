#include<iostream>
#include<cmath>
#include<set>
using namespace std;
/*
6 4
1 -3 5 1 -2 3
*/
int n,m;
int a[200000];
long long sum[400005];
long long ma=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i+n]=sum[n+i-1]+a[i];
	}
	for(int i=1;i<=2*n;i++)
	{
			for(int j=1;j<=i;j++)
			{
				if(ma<sum[i]-sum[j]&&i-j<=m)
				{
					ma=sum[i]-sum[j];
				}
			}
			
	}
	cout<<ma;
	return 0;
}

