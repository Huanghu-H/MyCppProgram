#include<iostream>
#include<cmath>
using namespace std;

int zhi[100005];
int n,k; 

int main()
{
	cin>>k>>n;
	int m=1;
	for(int i=2;i<=k;i++)
	{
		int flag=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=-1;break;
			}
		}
		if(flag==0)
		{
			zhi[m]=i;m++;
		}
	}
	//for(int i=1;i<m;i++)cout<<zhi[i]<<endl;
	int ans;
	for(int i=2;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<m;j++)
		{
			if(i%zhi[j]==0&&i!=zhi[j])
			{
				flag=-1;break;
			}
		}
		if(flag==0)ans++;
	}
	cout<<ans<<endl;
	return 0;
}

