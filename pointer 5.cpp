#include<iostream>
#include<cmath>
using namespace std;
//ָ���ͺ��� 
//��������� 
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

