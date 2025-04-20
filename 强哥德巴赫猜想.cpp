#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int ans1=0;
	int ans2=0;
	
	//
	for(int i=2;i+i<=n+1;i++)
	{
		int primenumber1=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)primenumber1=0;
		}
		
		int primenumber2=1;
		for(int j=2;j*j<=n-i;j++)
		{
			if(i%j==0)primenumber2=0;
		}
		
		if(primenumber1+primenumber2==2)
		{
			ans1=i;
			ans2=n-i;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;

	return 0;
}

