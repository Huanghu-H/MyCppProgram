#include<iostream>
#include<cmath>
#include<string> 
#include <algorithm>
using namespace std;

string addBinary(string a, string b) 
{
	int pa=a.size()-1;
	int pb=b.size()-1;
	int carry=0;
	string ans;
	while(!(pa==-1&&pb==-1))
	{
		int sum=0;
		if(pa==-1)
		{
			sum=carry+b[pb]-'0';
			pb--;
		}
		else if(pb==-1)
		{
			sum=carry+a[pa]-'0';
			pa--;
		}
		else 
		{
			sum=carry+a[pa]+b[pb]-2*'0';
			pa--;
			pb--;
		}

		if(sum==3) 
		{
			ans+='1';carry=1;
		}
		else if(sum==2)
		{
			ans+='0';carry=1;
		}
		else if(sum==1) 
		{
			ans+='1';carry=0;
		}
		else if(sum==0)
		{
			ans+='0';carry=0;
		}
	}
	if(carry==1) ans+='1';
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	string a="1111",b="1";
	cout<<addBinary(a,b)<<endl;
	return 0;
}

