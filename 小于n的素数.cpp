#include<iostream>
#include<cmath>
using namespace std;

int n;
int f(int a)
{
	int flag=1;
	if(a==2)return 1;
	else
	{
		for(int i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				flag=-1;break;
			}
		}
		if(flag==1)return 1;
		else return 0;
	}
}

int main()
{
	cin>>n;
	int counter=0;
	if(n==2)cout<<2<<"\t";
	else 
	{
		for(int i=2;i<=n;i++)
		{
			if(f(i)==1)
			{
				cout<<i;
				counter++;
				if(counter<6)cout<<"\t";
				else 
				{
					counter=0;cout<<endl;
				}
			}
			
		}
	}
	return 0;
}



