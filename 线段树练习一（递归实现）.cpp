#include<iostream>
#include<cmath>
using namespace std;

int nofa;
int a[10005];
int n;

void replace(int x,int y)
{
	a[x]=y;
}

long long sum(int x,int y)
{
	if(x==y)return 0;
	else 
	{
		return a[x]+sum(x+1,y);
	}
}


int main()
{
	cin>>nofa;
	for(int i=0;i<nofa;i++)cin>>a[i];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int judge,lbnd,rbnd;
		cin>>judge>>lbnd>>rbnd;
		if(judge==1)cout<<sum(lbnd,rbnd)<<endl;
		else replace(lbnd,rbnd);
	}
	return 0;
}

