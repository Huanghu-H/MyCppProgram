
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
	int sumofarray[105]={0};sumofarray[1]=a[1];
	int preindex[105]={0};preindex[1]=0;
	int sumofindex[105]={0};sumofindex[1]=1;
	int maxsum=a[1];
	int maxindex=1;
	//放数列，求最大的sum，求最大的index； 
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=i;j++)//5 7 3 5 6 2 5 6 7 6
		{	
			if(Lperele[j]==Lperele[i]-1&&a[i]>a[j])
			{
				if(sumofarray[i]==0)
				{
					sumofarray[i]=a[j]+a[i];
					sumofindex[i]=sumofindex[j]+i;
					preindex[i]=j;
				}
				else if(a[j]+a[i]>sumofarray[i]||(a[j]+a[i]>sumofarray[i]&&sumofindex[i]<sumofindex[j]+i)) 
				{
					sumofarray[i]=a[i]+a[j];
					sumofindex[i]=sumofindex[j]+i;
					preindex[i]=j;
				}
				flag=1;
			}	
		}
		if(flag==0)
		{
			sumofarray[i]=a[i];
			sumofindex[i]=i;
			preindex[i]=0;
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		if(maxsum<sumofarray[i])
		{
			maxsum=sumofarray[i];
			maxindex=i;
		}
	}
	for(int i=max;i>=1;i--)
	{
		Larray[i]=a[maxindex];
		maxindex=preindex[maxindex];
	}

//10
//5 7 3 5 6 2 5 6 7 6

//4
//0 5 7 6
	
	cout<<m<<endl;
	if(m==1)
	{
		int mmm=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>mmm)
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


