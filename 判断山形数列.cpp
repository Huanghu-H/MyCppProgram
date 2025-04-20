#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[100];

int main()
{
	cin>>n;
	int flag=1;
	bool up=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&up==1)
		{
			if(a[i]>a[i-1])
			{
				continue;
			}
			else 
			{
				up=false;
			}
		}
		if(i>1&&up==0)
		{
			if(a[i]<a[i-1])
			{
				continue;
			}
			else 
			{
				flag=0;break;
			}
		}
	}
	if(flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

