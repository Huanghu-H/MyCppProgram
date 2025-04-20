#include<iostream>
#include<cmath>
using namespace std;

int a[100][100];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(2*i<=n||2*j<=n)a[i][j]=min(i,j);
			else a[i][j]=min(n-i,n-j);
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
