#include<iostream>
#include<cmath>
using namespace std;

//输出数组中的数 
int a[10]={1,2,3,4,5,6,7,8,9,0};
int main()
{	
	int *p=a;//a=&a[0] 
	for(;p<a+10;p++)
	{
		cout<<*p<<endl;
	}
	
	return 0;
}

