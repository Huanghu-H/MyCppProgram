#include<iostream>
#include<cmath>
using namespace std;

int digit[10][10][100];
int nooftail[10];
int nostr[100];
//6 53 3 542 748 14 214
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nostr[i];
	}
	
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int no=nostr[j]/(int)pow(10,i-1)%10;
			digit[i][no][nooftail[no]]=nostr[j];
			nooftail[no]++;
		}
		//for(int j=0;j<=9;j++)cout<<digit[1][4][j]<<endl;
		//1->2 
		for(int j=1;j<=n;j++)nostr[j]=0;
		//1->0
		int a=1;
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<nooftail[j];k++)
			{
				nostr[a]=digit[i][j][k];a++;
			}
		}
		//2->1
		for(int j=0;j<=9;j++)nooftail[j]=0;
		//nooftail->0
	}
	for(int t=1;t<=n;t++)
	{
		cout<<nostr[t]<<" ";
	}
	return 0;
}

