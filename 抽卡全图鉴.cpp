#include<iostream>
#include<cmath>
using namespace std;

int n,m,x1,x2;
double p1,p2,ans;

int main()
{
	cin>>n>>m>>x1>>p1>>x2>>p2;
	ans=(p1-1-p1*p1)/(p1*p1-p1);
	cout<<ans<<endl;
	
	
	return 0;
}

