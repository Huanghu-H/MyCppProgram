#include<iostream>
#include<cmath>
using namespace std;

	int a[10]={1,2,3,4,5,6,7,8,9,0};
int main()
{	

	int *p=a;//a=&a[0] 
	for(int i=0;i<10;i++)
	{
		//puts("...");
		cout<<*(p+i)<<endl;
	}
	
	return 0;
}

