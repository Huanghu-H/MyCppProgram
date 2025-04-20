#include<iostream>
#include<cmath>
using namespace std;
//指针型函数 
//输出最大的数 
int *max(int a[],int n)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(a[m]<a[i])
		m=i;
	}
	return &a[m];
}

int main()
{
	int a[5]={3,4,5,27,4};
	int n=5;
	cout<<*max(a,n)<<endl;
	
	return 0;
}

