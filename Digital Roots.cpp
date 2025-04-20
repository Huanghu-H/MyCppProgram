#include<iostream>
#include<cmath>
using namespace std;

char a[10005];


int main()
{
	a[0]='1';
	a[1]='\0';
	while(a!="0")
	{
		scanf("%s",a);
		if(a[0]=='0')break;
		int sum=0;
		for(int i=0;a[i]!='\0';i++)
		{
			sum+=(int)a[i]-(int)'0';
		}
		while(sum>=10)
		{
			int sump=0;
			for(int i=1;i<=9;i++)
			{
				sump+=sum/(int)pow(10,i-1)%10;
			}
			sum=sump;
		}
		printf("%d",sum);cout<<endl;
	}
	
	
	return 0;
}

