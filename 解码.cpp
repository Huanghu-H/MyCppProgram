#include<iostream>
#include<cmath>
using namespace std;

int n;
char a[1050];
/*
14
2[a]3[b]define
13
11[ab]include
*/
int main()
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='['||a[i]==']'||(a[i]<='9'&&a[i]>='0'))continue;
		else
		{
			if(a[i-1]=='[')
			{
				char b[10000]={'\0'};
				int k=0;
				for(;a[i+k]!=']';k++)
				{
					b[k]=a[i+k];
				}
				int x=(int)a[i-2]-(int)'0';
				if(a[i-3]<='9'&&a[i-3]>='0')
				{
					x=x+((int)a[i-3]-(int)'0')*10;
					if(a[i-4]<='9'&&a[i-5]>='0')
					{
						x=x+((int)a[i-4]-(int)'0')*100;
						if(a[i-5]<='9'&&a[i-5]>='0')
						{
							x=x+((int)a[i-5]-(int)'0')*1000;
							if(a[i-6]<='9'&&a[i-6]>='0')
							{
								x=x+((int)a[i-6]-(int)'0')*10000;
							}
						}
					}
				}
				i=i+k-1;
				for(int j=1;j<=x;j++)cout<<b;
			}
			else
			cout<<a[i];
		}
	}
	return 0;
}

