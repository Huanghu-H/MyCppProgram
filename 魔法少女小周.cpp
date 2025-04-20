#include<iostream>
#include<cmath>
using namespace std;

int t,a,b,c;
int ans;
int x;

int main()
{
	cin>>t>>a>>b>>c;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			x=i^j;
			//cout<<x<<endl;
			if(x>=c)
			{
				
				ans++;
			//	cout<<i<<" "<<j<<endl;
			}
			
			
		}
	}
	cout<<ans;

	return 0;
}

