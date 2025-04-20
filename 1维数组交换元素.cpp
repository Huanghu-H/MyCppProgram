#include<iostream>
#include<cmath>
using namespace std;

int a[10]={0};

int main()
{
	int m;int n;
	for(int i=0;i<10;i++)
	cin>>a[i];
	cin>>m>>n;
	int *pm=&a[0];
	int *pp=&a[m];
	int *pn=&a[10-n];
	
	
	return 0;
}

