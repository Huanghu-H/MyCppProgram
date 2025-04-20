#include<iostream>
#include<cmath>
using namespace std;
int a[50];
int n;
int p(int b)
{
	return pow(2,b-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=32;i++)
	{
	a[i]=n/p(i)%2;	
	}	
	for(int i=32;i>=1;i--)
	{
		cout<<a[i];
		if(i%8==1)
		if(i<32)
		cout<<' ';
	}
	return 0;
}

