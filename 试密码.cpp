#include<iostream>
#include<cmath>
using namespace std;

int n,m;
char a[10001][10001];
char b[10001][10001];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		int g=0;
		for(int j=1;j<=n;j++)
		{
			int f=0;
			for(int k=0;b[i][k]!='\0'||a[j][k]!='\0';k++)
			{
				if(a[j][k]!=b[i][k])
				{
					f++;
				}
			}
			//if(f>1)break;
			if(f==1)
			{
				cout<<"YES"<<endl;
				g=1;break;
			}
		}
		if(g==0)cout<<"NO"<<endl;
	} 
	return 0;
}

