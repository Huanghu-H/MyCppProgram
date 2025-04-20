#include<iostream>
#include<cmath>
using namespace std;

int LEN[6][205];

int p(int k,int s)
{
	if(LEN[k][s]!=-1)return LEN[k][s];
	else
	{
		if(k==0||s==0)return 0;
		else
		{
			int c=p(k-1,s-1)+p(k,s-1)+1;
			return c;
		}
	}
}


int main()
{
	for(int k=1;k<=5;k++)
	{
		for(int s=0;s<=200;s++)
		{
			LEN[k][s]=-1;
		}
	}
	
	for(int k=1;k<=5;k++)
	{
		for(int s=0;s<=200;s++)
		{
			LEN[k][s]=p(k,s);
		}
	}

//	for(int s=0;s<=200;s++)
//	{
//		for(int k=1;k<=5;k++)
//		{
//			cout<<LEN[k][s]<<" ";
//		}cout<<endl;
//	}
		
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		int k;int n;
		cin>>k>>n;
		for(int s=0;s<=200;s++)
		{
			if(LEN[k][s]>=n)
			{
				cout<<s<<endl;break;
	    	}	
		}
	}
	return 0;
}

