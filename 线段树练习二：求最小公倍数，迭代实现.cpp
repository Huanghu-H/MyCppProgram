#include<iostream>
#include<cmath>
using namespace std;

long long lcm(long long m,long long n)
{
	long long s=m*n; 
    long long a=m%n;
    while(a)
	{
    	m=n;
        n=a;
        a=m%n;
    }
    return s/n;
}
//55944 25641 12950 153846 1480
//615384 12950
int nofa;
int a[1005];
int n;

int main()
{
	cin>>nofa;
	for(int i=0;i<nofa;i++)cin>>a[i];
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    long long lbnd,rbnd,ans=1;
		cin>>lbnd>>rbnd;
		for(int j=lbnd;j<rbnd;j++)
		ans=lcm(ans,a[j]);
		cout<<ans<<endl;
	}

	return 0;
}

