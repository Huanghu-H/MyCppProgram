#include<iostream>
#include<cmath>
using namespace std;

int in;
int out;

long long path(int a)
{
	if(a==-1)out=0;
	if(a==0)out=0
	if(a==1)out=0;
	if(a==2)out=1;
	if(a%2==0)
		out=path(a-2)+path(a-3);
	else
		out=path(a-2)+path(a-1);
	return out;
} 

int main()
{
	cin>>in;
	cout<<path(in)<<endl;
	return 0;
}
