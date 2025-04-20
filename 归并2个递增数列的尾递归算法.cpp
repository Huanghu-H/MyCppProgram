#include<iostream>
#include<cmath>
using namespace std;

int a[105];
int b[105];
int c[105];




int main()
{
	int n1,n2; 
	cin>>n1;
	for(int i=0;i<n1;i++)cin>>a[i];
	cin>>n2;
	for(int i=0;i<n2;i++)cin>>b[i];
	int n=0,l1=0,l2=0;
	while(l1<n1||l2<n2)
	{
		if(l1==n1&&l2<n2)
		{
			c[n]=b[l2];l2++;n++;
		}
		else if(l2==n2&&l1<n1)
		{
			c[n]=a[l1];l1++;n++;
		}
		else
		{
			if(a[l1]<b[l2])
			{
				c[n]=a[l1];l1++;n++;
			}
			else
			{
				c[n]=b[l2];l2++;n++;
			}
		}
	}
	for(int i=0;i<n;i++)cout<<c[i]<<" ";
	
	return 0;
}

