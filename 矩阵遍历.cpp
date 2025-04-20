#include<iostream>
#include<cmath>
using namespace std;

int a[131][131];
int x,y;
int n=1,m=1;
int fangxiang=1;//you 1;xia 2;zuo 3;shang 4

int main()
{
	cin>>y>>x;
	for(int j=1;j<=y;j++)
	{
		for(int i=1;i<=x;i++)
		{
			cin>>a[i][j];
		}
	}
	for(int k=1;k<=x*y;k++)
	{
	
	    cout<<a[n][m]<<" ";
		a[n][m]=-18310629;
		if((n==x||a[n+1][m]==-18310629)&&fangxiang%4==1)fangxiang++;
		if((m==y||a[n][m+1]==-18310629)&&fangxiang%4==2)fangxiang++;
		if((n==1||a[n-1][m]==-18310629)&&fangxiang%4==3)fangxiang++;
		if((m==1||a[n][m-1]==-18310629)&&fangxiang%4==0)fangxiang++;
		if(fangxiang%4==1)n++;
		if(fangxiang%4==2)m++;
		if(fangxiang%4==3)n--;
		if(fangxiang%4==0)m--;				
	}	
	

	return 0;
}

