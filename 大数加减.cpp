#include<iostream>
#include<cmath>
using namespace std;

char a[1000];
char b[1000];
int c[1000];
int d[1000];
int ans[1000];

int main()
{
	cin>>a;
	cin>>b;
	int long1=0;
	int long2=0;
	 
	for(int i=0;a[i]!='\0';i++)
	{
		c[i]=(int)a[i]-(int)'0';
		long1=i;
	}
	for(int i=0;b[i]!='\0';i++)
	{
		d[i]=(int)b[i]-(int)'0';
		long2=i;
	}
	//cout<<d[0]<<d[1]<<d[2]<<endl;
	//比较大小
	int big=0;
	if(long1>long2)big=1;
	else if(long2>long1)big=2;
	else
	{
		int i=0;//最高位 
		while(big==0)
		{
			if(c[i]>d[i])big=1;
			else if(d[i]>c[i])big=2;
			else if(i<long1)i++;
			else break; 
		}
	}
	if(big==1)
	{
		//cout<<long1<<" "<<long2<<endl;
		for(int i=0;i<=long1;i++)
		{
			if(i<=long2)
			{
				ans[long1-i]=c[long1-i]-d[long2-i];
				if(ans[long1-i]<0)
				{
					ans[long1-i]+=10;
					c[long1-i-1]-=1;
				}
				//cout<<ans[3]<<endl;return 0;
			}
			else ans[long1-i]=c[long1-i];
			//cout<<ans[3]<<endl;
			
		} 
	}
	if(big==2)
	{
		for(int i=0;i<=long2;i++)
		{
			if(i<=long1)
			{
				ans[long2-i]=d[long2-i]-c[long1-i];
				if(ans[long2-i]<0)
				{
					ans[long2-i]+=10;
					d[long2-i-1]-=1;
				}
			}
			else ans[long2-i]=d[long2-i];
		} 
	}
	if(big==0)
	{
		cout<<0<<endl;return 0;
	}
	int i=0;
	while(ans[i]==0&&i<max(long1,long2))
	{
		i++;
	}
	for(;i<=max(long1,long2);i++)cout<<ans[i];
	return 0;
}

