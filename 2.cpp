#include<iostream> 
#include<cmath>
using namespace std;
int b;

long long path(int a)
{
	if(a==2)return 1;
	if(a==1)return 1;
	else if(a%2==0)
		return path(a-3)+path(a-2)+path(a-1);
	else
		return path(a-2)+path(a-1);
}

int main ()
{
	cin>>b;
	cout<<path(b)<<endl;
	
	return 0;
}

