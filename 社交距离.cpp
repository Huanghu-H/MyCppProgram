#include<iostream>
#include<cmath>
using namespace std;
int a;
int n[105];
int s[105];
int m=0;
int main()
{
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>n[i];
	}
	n[0]=1;
	n[a+1]=1; 
	for(int i=0;i<=a+1;i++)
	{
		if(n[i]==1)
		for(int j=1;j<=a;j++)
		{
			if(n[i+j]==1)
			{
				s[i]=j;break;
			} 
			
		}
	}
	m=0;
	for(int i=0;i<=a+1;i++)
	{
		if(s[i]>m) m=s[i];
	}
	//cout<<m<<endl;
	if(m>=4)
	{
		for(int i=0;i<=a+1;i++)
		{
			if(s[i]==m)
			{
				if(i==0)cout<<0<<" ";
				else if(i==a-m+1)cout<<a-1<<" ";
				
				else if(m%2==1&&i!=a-m+1)cout<<(i+(m-3)/2)<<" "<<(i+(m-1)/2)<<" ";
				else if(m%2==0&&i!=a-m+1) cout<<i+m/2-1<<" ";
			}
		}
	}
	else cout<<"-1"<<endl;
	return 0;
}

