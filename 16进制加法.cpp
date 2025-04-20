#include<iostream>
#include<cmath>
using namespace std;

int in1,in2,wei;
char a[105];
char b[105]; 
int c[105];

int shu(char a)
{
	if(a=='1')return 1;
	if(a=='2')return 2;
	if(a=='3')return 3;
	if(a=='4')return 4;
	if(a=='5')return 5;
	if(a=='6')return 6;
	if(a=='7')return 7;
	if(a=='8')return 8;
	if(a=='9')return 9;
	if(a=='0')return 0;
	if(a=='A')return 10;
	if(a=='B')return 11;
	if(a=='C')return 12;
	if(a=='D')return 13;
	if(a=='E')return 14;
	if(a=='F')return 15;
}

int main()
{
	cin>>in1>>in2;
	for(int i=in1;i>=1;i--)
	{
		cin>>a[i];
	}
	for(int i=in2;i>=1;i--)
	{
		cin>>b[i];
	}
	for(int i=1;i<=101;i++)
	c[i]=shu(a[i])+shu(b[i]);
	for(int i=1;i<=101;i++)
	{
		//cout<<c[i]<<endl;
		if(c[i]>=16)
		{
			c[i]-=16;
			c[i+1]++;
		}
		if(c[i]!=0)wei=i;
	}
	//cout<<wei<<endl;
	if(wei==0)cout<<0;
	for(int i=wei;i>=1;i--)
	{	
		if(c[i]<=9)
		cout<<c[i]<<" ";
		if(c[i]==10)
		cout<<"A"<<" ";
		if(c[i]==11)
		cout<<"B"<<" ";
		if(c[i]==12)
		cout<<"C"<<" ";
		if(c[i]==13)
		cout<<"D"<<" ";
		if(c[i]==14)
		cout<<"E"<<" ";
		if(c[i]==15)
		cout<<"F"<<" ";
		
	}
	
	return 0;
}

