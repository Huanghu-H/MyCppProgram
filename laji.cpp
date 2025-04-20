#include<iostream>
#include<cmath>
using namespace std;
long long l,r;
long long a[5000000];

int main()
{
//	cin>>l>>r;
//	l=l%4117642;
//	r=r%4117642; 
	long long sum=0;
	a[1]=1;
	a[2]=1;
	long long i=1;
//	if(l==1)sum=0;
//	else if(l==2)sum=1;
	
//	else
//	{
		//sum=3;
	    for(long long i=3;i<50000000;i++)
		{
			a[i]=a[i-2]+a[i-1];
			if(a[i]>23333333)
			a[i]-=23333333; 
			//sum+=i*a[i];
			//if(sum>23333333)
			//sum=sum%23333333;
			if(a[i]==1)
			{
			cout<<a[4117644]<<endl;
			}	
		}
//	}
	//int a1=sum;
	
	//cout<<a1<<" "<<i;
	return 0;
}

