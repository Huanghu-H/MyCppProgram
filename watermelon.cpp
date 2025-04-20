#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char a[100];
		cin>>a;
		int length=0;
		for(;a[length]!='\0';length++);
		if(length<=10)cout<<a<<endl;
		else cout<<a[0]<<length-2<<a[length-1]<<endl;
	}
}

