#include<iostream>
#include<cmath>
#include<iomanip>
#define y1 yy

using namespace std;

int n;
int x1;
int y1;
int x2;
int y2;
double ans[101];
int flag[101];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		if(y1*y2>0)flag[i]=-1;
		if(y1*y2==0)
		{
			if(y1==y2)
			{
				if(x1==x2)ans[i]=x1;
				else flag[i]=-1;
			}
		}
		if(flag[i]==0&&(y1!=y2))
		{
			ans[i]=-(double)y1*(x2-x1)/(y2-y1);
			cout<<ans[i]<<endl;
			ans[i]+=x1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)cout<<fixed<<setprecision(6)<<ans[i]<<endl;
		else cout<<"null"<<endl;
	}

	return 0;
}

