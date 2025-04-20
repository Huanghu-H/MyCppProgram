#include<iostream>
#include<cmath>
#include<cstring> // memset
using namespace std;

int climbStairs(int n)
{
	int Fib[50];
	memset(Fib,0,n*sizeof(int));
	Fib[1]=1;
	Fib[2]=2;
	for(int i=3;i<=n;i++)
	{
		Fib[i]=Fib[i-1]+Fib[i-2];
	}
	return Fib[n];
}

int main()
{
	int x;
	cin>>x;
	cout<<climbStairs(x)<<endl;

	return 0;
}

