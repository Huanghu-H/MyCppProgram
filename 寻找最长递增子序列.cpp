
#include<iostream>
#include<cmath>
using namespace std;

int Larray[105];
int a[105];
int Lperele[105];
int maxarray;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Lperele[i]=1;
	}
	Lperele[1]=1;
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i]&&Lperele[i]==Lperele[j])
			{
				Lperele[i]++;
			}
		}
	}

	int max=0;
	for(int i=1;i<=n;i++)
	{
		if(max<Lperele[i])
		max=Lperele[i];
	}
	
	int m=max;
	int min=100000;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;Lperele[j]<=max&&j<=n;j++)
		{
			if(min>a[j]&&max==Lperele[j]) 
			{
				min=a[j];
				Larray[max]=a[j];
			}
		}
		max--;
	}
	cout<<m<<endl;
	if(m==1)
	{
		int mmm=100000;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<mmm)
			mmm=a[i];
		}
		cout<<mmm<<endl;
	}
	else
	{
		for(int i=1;i<=m;i++)
	    cout<<Larray[i]<<' ';
	}
	
	
	return 0;
}

