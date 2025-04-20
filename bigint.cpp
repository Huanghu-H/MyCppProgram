#include<iostream>
#include<cmath>
using namespace std;
int g(int a1[],int a2[]);
int a1[1005];char c1[1005];
int a2[1005];char c2[1005];
int sign1=0,sign2=0,n1,n2;

void f(int a1[],int a2[],int s1,int s2)
{
	if(s1==1&&s2==1)
	{
		int p[1005]={0};
		for(int i=0;i<=1005;i++)
		{
			p[i]+=a1[i]+a2[i];
			if(p[i]>=10)
			{
				p[i]-=10;
				p[i+1]++;
			}
		}
		//cout<<p[3]<<endl;
		int wei=0;
		for(int i=1005;i>=0;i--)
		{
			if(p[i]!=0)
			{
				wei=i+1;
				break;	
			}
		}
		for(int i=wei-1;i>=0;i--)
		{
			cout<<p[i];
		}
		cout<<endl;return;
	}
	if(s1==-1&&s2==-1)
	{
		cout<<"-";
		int p[1005]={0};
		for(int i=0;i<=1005;i++)
		{
			p[i]+=a1[i]+a2[i];
			if(p[i]>=10)
			{
				p[i]-=10;
				p[i+1]++;
			}
		}
		int wei=0;
		for(int i=1005;i>=0;i--)
		{
			if(p[i]!=0)
			{
				wei=i+1;
				break;	
			}
		}
		for(int i=wei-1;i>=0;i--)
		{
			cout<<p[i];
		}
		cout<<endl;return;
		
	}
	if(s1!=s2)
	{
		if(g(a1,a2)==1)
		{
			if(s1==-1)cout<<'-';
			int m[1005]={0};
			for(int i=0;i<=1005;i++)
			{
				m[i]+=a1[i]-a2[i];
				if(m[i]<0)
				{
					m[i]+=10;m[i+1]--;
				}
			}
			int wei=0;
			for(int i=1005;i>=0;i--)
			{
				if(m[i]!=0)
				{
					wei=i+1;
					break;	
				}
			}
			for(int i=wei-1;i>=0;i--)
			{
				cout<<m[i];
			}
			cout<<endl;return;
			
		}
		if(g(a1,a2)==2)
		{
			if(s2==-1)cout<<'-';
			int m[1005]={0};
			for(int i=0;i<=1005;i++)
			{
				m[i]+=a2[i]-a1[i];
				if(m[i]<0)
				{
					m[i]+=10;m[i+1]--;
				}
			}
			int wei=0;
			for(int i=1005;i>=0;i--)
			{
				if(m[i]!=0)
				{
					wei=i+1;
					break;	
				}
			}
			for(int i=wei-1;i>=0;i--)
			{
				cout<<m[i];
			}
			cout<<endl;return;
		}
		if(g(a1,a2)==0)
		{
			cout<<0<<endl;
		}
	}
}
int g(int a1[],int a2[])
{
	for(int i=1005;i>=0;i--)
	{
		if(a1[i]==a2[i])continue;
		if(a1[i]<a2[i])return 2;
		if(a1[i]>a2[i])return 1;
	}
	return 0;
}
int main()
{
	cin>>n1;
	char t;
	cin>>t;
		
	if(t=='-')
	{
		sign1=-1;
		for(int i=1;i<=n1;i++)
		{
			cin>>c1[n1-i];a1[n1-i]=(int)c1[n1-i]-(int)'0';
		}
	}
	else
	{
		sign1=1;
		a1[n1-1]=(int)t-(int)'0';
		for(int i=2;i<=n1;i++)
		{
			cin>>c1[n1-i];a1[n1-i]=(int)c1[n1-i]-(int)'0';
		}
	}

	cin>>n2;
	char t2;
	cin>>t2;
		
	if(t2=='-')
	{
		
		sign2=-1;
		for(int i=1;i<=n2;i++)
		{
			cin>>c2[n2-i];a2[n2-i]=(int)c2[n2-i]-(int)'0';
		}
	}
	else
	{
		sign2=1;
		a2[n2-1]=(int)t2-(int)'0';
		for(int i=2;i<=n2;i++)
		{
			cin>>c2[n2-i];a2[n2-i]=(int)c2[n2-i]-(int)'0';
		}
	}
	//cout<<a1[2]<<a1[1]<<a1[0];
	f(a1,a2,sign1,sign2);
	f(a1,a2,sign1,-sign2);
	return 0;
}

