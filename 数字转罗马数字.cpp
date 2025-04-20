#include<iostream>
#include<cmath>
#include<string>
using namespace std;
/*
1:I 5:V
10:X 50:L
100:C 500:D
1000:M
*/
char roman(int x1,int x2)
{
	if(x1==1&&x2==0) return 'I';
	else if(x1==5&&x2==0) return 'V';
	else if(x1==1&&x2==1) return 'X';
	else if(x1==5&&x2==1) return 'L';
	else if(x1==1&&x2==2) return 'C';
	else if(x1==5&&x2==2) return 'D';
	else if(x1==1&&x2==3) return 'M';
}
int main()
{
	int n;
	cin>>n;
	string s="";
	int num[4]={n%10,n%100/10,n%1000/100,n/1000};
	
	for(int i=3;i>=0;i--)
	{
		if(num[i]==9)
		{
			s+=roman(1,i);s+=roman(1,i+1);num[i]=0;
		}
		else if(num[i]==4)
		{
			s+=roman(1,i);s+=roman(5,i);num[i]=0;
		}
		else if(num[i]>=5)
		{
			s+=roman(5,i);num[i]-=5; 
		}
		for(int j=0;j<num[i];j++)
		{
			s+=roman(1,i);
		}
	}
	cout<<s<<endl;	
	return 0;
}

