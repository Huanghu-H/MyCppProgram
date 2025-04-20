#include<iostream>
#include<cmath>
using namespace std;

int T;
int n;
long long k;

int main()
{
	cin>>T;
	long long a[100005];
	for(int i=1;i<=T;i++)
	{
		cin>>n>>k;
		long long sum=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			sum=sum+a[j];	
		}
		long long remain=k%sum;
		int j=1;
		while(remain>0)
		{
			remain-=a[j];
			if(j<n)j++;
			else j=1;		
		} 
		long long t;
		if(j==1)
		{
			t=a[n];cout<<n<<" ";
		}
		else 
		{
			t=a[j-1];cout<<j-1<<" ";
		}
		cout<<remain+t<<endl;
	}
	
	return 0;
}

