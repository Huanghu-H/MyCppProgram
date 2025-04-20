#include<iostream>
#include<cmath>
using namespace std;
long long l,r,sum1,sum2;
long long a[5000000];

int main()
{
	cin>>l>>r;
	int jie1=l/4117644;
	int jie2=r/4117644;
	int yu1=l%4117644;
	int yu2=r%4117644; 
	a[0]=0;
	a[1]=1;
	a[2]=1;
	for(long long i=3;i<=4117645;i++)
		{
			a[i]=a[i-2]+a[i-1];
			if(a[i]>23333333)
			a[i]-=23333333; 
		}
	for(int i=1;i<=4117644;i++)
	{
		long long c=(jie1*(jie1-1)/2*4117644)%23333333;
		long long d=(yu1*jie1)%23333333;
		sum1+=(a[i]*(c+d))%23333333;
	}
	for(int i=1;i<=4117644;i++)
	{
		long long c=(jie2*(jie2-1)/2*4117644)%23333333;
		long long d=(yu2*jie2)%23333333;
		sum2+=(a[i]*(c+d))%23333333;
	}
	
	for(int i=1;i<yu1;i++)
	{
		sum1+=a[i]*(i%23333333);
		sum1=sum1%23333333;
	}
	for(int i=1;i<=yu2;i++)
	{
		sum2+=a[i]*(i%23333333);
		sum2=sum2%23333333;
	}
	int an=sum2-sum1;
	if(an<0)an=an+23333333;		
	cout<<an;
	return 0;
}

