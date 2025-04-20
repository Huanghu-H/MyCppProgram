#include<iostream>
#include<cmath>
#include<set> 
#include <algorithm>
#include <iterator>
using namespace std;
int n,m;
#define MAX 999999
int w[MAX];
set<int> pre[MAX];
int dp1[MAX],dp2[MAX];
int taken[MAX];

void solve()
{
	for(int i=1;i<=n;i++)
	{
		dp1[i]=w[i];
		dp2[i]=0;
		for(auto x:pre[i])
		{
			
		}
		dp2[i]=max(dp1[i-1],dp2[i-1]);
		cout<<dp1[i]<<" "<<dp2[i]<<endl;
	}
	cout<<max(dp1[n],dp2[n])<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		pre[y].insert(x);
		for(auto z:pre[x])
		{
			pre[y].insert(x);
		}
	}
	solve();
	return 0;
}

