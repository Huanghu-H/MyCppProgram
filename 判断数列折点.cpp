#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[100];
 
int main()
{
	cin>>n;
	int count=0;
	int up=2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2)
		{

			if(a[i-1]>a[i-2])up=1;
			if(a[i-1]<a[i-2])up=0;
			
			if(up==1&&a[i-1]>a[i])count++;
			else if(up==0&&a[i-1]<a[i])count++;
		}
	}
	cout<<count<<endl;

	return 0;
}

