#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int s2i(char c)
{
	return (int)c-(int)'0';
}
string AddNum(int x,int y,int& in,string ans)
{
	int product=x*y+in;
	if(product>10)
	{
		in=product/10;
		product%=10;
	}
	else in=0;
	char c=(char)((int)'0'+product);
	return c+ans;
}
string multiply(string num1,string num2)
{
	int l1=num1.length()-1;
	int l2=num2.length()-1;
	const char* c1=num1.c_str();
	const char* c2=num2.c_str();
	int in=0;
	string ans;
	int n1=0,n2=0;
	while(!(l1==0&&l2==0&&in==0))
	{	
		if(l1==0&&l2==0)
		{
			n1=0;n2=0;
		}
		else if(l1==0)
		{
			n1=0;n2=s2i(num2[l2]);
			l2--;
		}
		else if(l2==0)
		{
			n1=s2i(num1[l1]);n2=0;
			l1--;
		}
		else 
		{
			n1=s2i(num1[l1]);n2=s2i(num2[l2]);
			l1--;l2--;
		}
		ans=AddNum(n1,n2,in,ans);
	}
	return ans;
} 



int main()
{
	string num1="15";
	string num2="15";
	cout<<multiply(num1,num2)<<endl;
	return 0;
}

