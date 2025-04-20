#include<iostream>
#include<cmath>
using namespace std;

int n;
char a[20];
long long b=0;

int main()
{
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a[0]=='-')
		{
			int len=1;
			for(;a[len+1]!='\0';len++);
			for(int j=1;a[j]!='\0';j++)
			{
				b=b+(int)(a[j]-'0')*(int)pow(10,len-j); 
			}
			cout<<-b<<endl;
			b=0;
		}
		else
		{
			int len=1;
			for(;a[len]!='\0';len++);
			for(int j=0;a[j]!='\0';j++)
			{
				b=b+(int)(a[j]-'0')*(int)pow(10,len-j-1); 
			}
			cout<<b<<endl;
			b=0;
			
		}
		for(int k=0;k<=19;k++)
		{
			a[k]='\0'; 
		}
	}
	return 0;
}

