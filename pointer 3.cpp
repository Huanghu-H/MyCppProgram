#include<iostream>
#include<cmath>
using namespace std;

//´«Ö·µ÷ÓÃ 
void f(int *p,int b)
{
	for(int i=0;i<b;i++)
	{
		cout<<*(p+i)<<endl;
	}
}

int main()
{
	int b=10;
	int a[10]={1,2,3,4,5,6,7,8,9,0};
	f(a,b);
	
	return 0;
}

