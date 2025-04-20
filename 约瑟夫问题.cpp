#include<iostream>
#include<cmath>
using namespace std;

int n,m;

int main()
{
	int a[100];
	for(int i=0;i<100;i++)a[i]=1;
	cin>>n>>m;
	int no_remain=n;
	int index=-1;
	while(no_remain>1)
	{
		int count=0;
		while(count<m)
		{
			index=(index+1)%n;
			if(a[index])count++;
		}

		a[index]=0;
		no_remain--;
	}
		
	for(index=0;index<n;index++)
	{

		if(a[index])break;
	}
	cout<<index<<endl;
	return 0;
}

