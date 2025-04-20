#include<iostream>
#include<cmath>
using namespace std;

int x;
int nian[5];
int main()
{
	cin>>x;
	nian[0]=1;
	for(int i=1;i<=x;i++)
	{
		int a=nian[1];
		int b=nian[2];
		int c=nian[3];
		nian[1]=c+nian[0];
		nian[0]=0;
		nian[2]=a;
		nian[3]=b+c;
	}
	
	cout<<nian[1]+nian[2]+nian[3]+nian[4];
	return 0;
}

