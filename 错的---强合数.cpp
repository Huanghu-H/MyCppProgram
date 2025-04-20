#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int k[5020];
int fan[5020];
int fu[5020];
int n;
int a[10];
int huan;
int wei;


int f(int an,int b)
{
	for(int i=1;i<10;i++)
	{
		if(an/pow(10,i-1)>0.99)wei=i;
		//cout<<wei;
	}
	for(int i=1;i<=wei;i++)
	{
		//cout<<wei;
		a[i]=(int(an/pow(10,i-1))%10);
		//cout<<a[i]<<" we";
	}
	
	
	for(int i=1;2*i<=(wei+1);i++)
	{
		huan=a[i];
		a[i]=a[wei+1-i];
		a[wei+1-i]=huan;
		//cout<<a[i]<<" er";
	}
	fan[b]=0;
	for(int i=1;i<=wei;i++)
	{
		fan[b]=fan[b]+a[i]*pow(10,i-1);
	}
	return fan[b];
}




int he(int a)
{
	int flag=1;
	for(int i=2;i*i<=a+1;i++)
	{
		if(a%i==0)flag=0;
	}
	return flag;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]<0)
		{
			fu[i]=-1;
			k[i]=-k[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		
		
		
		
	//	cout<<k[i]<<"  "<<f(k[i],i)<<"  "<<he(k[i])<<"  "<<he(f(k[i],i))<<endl;
		if(fu[i]==-1)cout<<"False"<<endl;
		else if((he(k[i])==0)&&(he(f(k[i],i))==0))cout<<"True"<<endl;
		else cout<<"False"<<endl;
	}
	
	return 0;
}

 
