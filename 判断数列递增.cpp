#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[100]; 

int main()
{
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		if(i>1&&a[i]>a[i-1])
		{
			continue;
		}
		if(i>1&&a[i]<=a[i-1])
		{
			flag=-1;
		}
	}
	if(flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

