#include<iostream>
#include<cmath>
using namespace std;

int n; 
int a[1005];
int b[1005];
int c[1005];

int main()
{
	cin>>n;
	int sum=0; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i],&a[i]);
		sum+=b[i];
	}
	int min=99999;
	for(int i=1;i<=n;i++)
	{
		if(min>a[i])
		min=a[i];
	}
	int ans;
	ans=min+sum;
	cout<<ans;
	return 0;
}

