#include<iostream>
#include<cmath>
using namespace std;

void swap(int *pa,int *pb)
{
	int x=*pa;
	*pa=*pb;
	*pb=x; 
} 

int main()
{
	int a=1;
	int b=2;
	swap(a,b);
	cout<<a<<" "<<b<<endl;

	return 0;
}

