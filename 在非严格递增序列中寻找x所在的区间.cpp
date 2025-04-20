#include<iostream>
#include<cmath>
using namespace std;

int n1,n2;
int a[105],b[105];

int main()
{
	cin>>n1;
	for(int i=0;i<n1;i++)cin>>a[i];
	cin>>n2;
	for(int i=0;i<n2;i++)cin>>b[i];
	
	for(int i=0;i<n2;i++)
	{
		int Fb=n1;
		for(int j=0;j<n1;j++)
		{
			if(b[i]<=a[j])
			{
				Fb=j;break;
			} 
		}
		int Ls=n1-1;
		for(int j=0;j<n1;j++)
		{
			if(b[i]<a[j])
			{
				Ls=j-1;break; 
			}
		}
		cout<<Fb<<" "<<Ls<<endl;
	}
	
	return 0;
}

