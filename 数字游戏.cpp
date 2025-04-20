#include<iostream>
#include<cmath>
using namespace std;

int n;
int wei;
int m[26];
int ans;
int m1; 

int main()
{
	cin>>n;
	for(int i=1;i<=6;i++)
	{
		
		if(int(n/pow(10,i))==0)
		{
			wei=i;break;
		}
	}

	for(int i=1;i<=wei;i++)
	{
		n+=pow(10,i-1);	
	}
	//	cout<<n<<"  "<<wei<<"  ";
	for(int i=1;i<=25;i++)
	{
		m1=(n/pow(2,i-1));
		m[i]=m1%2;
	//	cout<<m[i]<<endl;
		if(m[i]==1)
		{
			ans=ans+1;
			
		}
		//cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

