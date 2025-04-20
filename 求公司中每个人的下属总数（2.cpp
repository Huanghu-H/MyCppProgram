#include<iostream>
#include<cmath>
using namespace std;

int n;
int next1[1005];
int rank1[1005];
int subordinate[1005];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int y;
		cin>>y;
		next1[i]=y;
	}
	for(int i=0;i<n;i++)
	{
		int k=i;
		while(next1[k]!=-1)
		{
			if(rank1[next1[k]]<rank1[k]+1)rank1[next1[k]]=rank1[k]+1;
			k=next1[k];
		}
		//cout<<rank1[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(rank1[j]==i)
			{
				subordinate[next1[j]]=subordinate[next1[j]]+1+subordinate[j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(rank1[i]==0) cout<<0<<" ";
		else cout<<subordinate[i]<<" ";
	}
	return 0;
}

