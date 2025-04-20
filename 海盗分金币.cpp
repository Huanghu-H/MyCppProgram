#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[25];
int tag[25];

int main()
{
	cin>>n;
	if(n<=3)
	{
		if(n==1)cout<<100<<endl;
		if(n==2)cout<<"100 -1"<<endl;
		if(n==3)cout<<"100 0 0"<<endl;
	} 
	else
	{
		a[n]=0;a[n-1]=0;a[n-2]=100;
		for(int i=4;i<=n;i++)
		{	
			int MOPPES=i/2;
			//找到MOPPES个最小值，然后+1；其余的变成0；
			int k=0;
			int min=0;
			while(k<MOPPES)
			{
				for(int j=n-i+2;j<=n;j++)
				{
					if(a[j]==min&&tag[j]==0)
					{
						//if(i==6)cout<<j<<" "<<a[j]<<endl;
						k++;
						a[j]++;
						tag[j]=1;
						if(k==MOPPES)break;
					}
				}
				min++;
			}
			int sum=0;
			for(int j=n-i+2;j<=n;j++)
			{
				if(tag[j]==0)a[j]=0;
				sum+=a[j];
			}
			for(int j=1;j<=n;j++)tag[j]=0;
			a[n-i+1]=100-sum;
			
		}
		for(int j=1;j<=n;j++)cout<<a[j]<<" ";
		cout<<endl;
	}
	return 0;
}

