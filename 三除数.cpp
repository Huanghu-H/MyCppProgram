#include<iostream>
#include<cmath>
using namespace std;
int a; 
int flag;
int main()
{
	cin>>a;
	for(int i=2;i<=101;i++)
	{
		if(i*i==a)
		{
			if(a==4||a==9)flag=1;
			for(int j=2;j*j<=i;j++)
			{
				if(i%j!=0)
				{
					flag=1;
				}
				else
				{
					flag=0;break;
				}
			}
			break;
		}
	}	
	if(flag==1)
	{
		cout<<1<<endl;flag=0;
	}
	else cout<<0<<endl;
	return 0;
}

