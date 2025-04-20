#include<iostream>
#include<cmath>
using namespace std;

int n;
int a1,a2,a3,a4;
int b1,b2,b3;
 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a4;
		if(a4>=a3)a3=a4;
		if(a3>=a2)
		{
			b2=a2;
			a2=a3;
			a3=b2;
		}
		if(a2>=a1)
		{
			b1=a1;
			a1=a2;
			a2=b1;
		}
	} 
	cout<<a3;
	return 0;
}

