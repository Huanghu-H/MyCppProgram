#include<iostream>
#include<cmath>
using namespace std;
int fan(int k);
int he2(int k);
int n;

int he(int k)
{
	if(k<=3)
	return 0;
	else 
	{
		int flag=0;
		for(int i=2;i*i<=k;i++)
		{
			if(k%i==0)
			{
				flag=-1;break;
			}
		}
		if(flag==-1)
		return 1;
		else 
		return 0;
	}
	
}
int he2(int k)
{
	//cout<<k<<endl;//4
	int k1=fan(k);
	//cout<<k1<<endl;//0
	if(he(k1)==1)
	return 1;
	else 
	return 0;
}
int fan(int k)
{
	int wei;
	int a[10];
	for(int i=1;i<=9;i++)
	{
		int p=pow(10,i);
		if((int)k/p==0)
		{
			wei=i;break;
		}
	}
	for(int i=1;i<=wei;i++)
	{
		int m=k/pow(10,i-1);
		a[i]=m%10;
	}
	for(int i=1;i+i<=wei;i++)
	{
		int c=a[i];
		a[i]=a[wei+1-i];
		a[wei+1-i]=c;
	}
	int sum=0;
	for(int i=1;i<=wei;i++)
	{
		sum=sum+a[i]*(int)pow(10,i-1);
	}
	return sum;
}


int main()
{
	cin>>n;
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
	//	cout<<he(k)<<" "<<he2(k)<<" "<<fan(k)<<endl;
		if(he(k)==1&&he2(k)==1)
		cout<<"True"<<endl;
		else
		cout<<"False"<<endl;
	}
	
	
	
	return 0;
}

