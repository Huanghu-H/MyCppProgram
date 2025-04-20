#include<iostream>
#include<cmath>
using namespace std;

int mySqrt(int x) 
{
	long long y=x;
	long long i=0;
	for(;i*i<=y;i++);
	return i-1;        
}

int main()
{
	int x;
	cin>>x;
	cout<<mySqrt(x)<<endl;
	return 0;
}

