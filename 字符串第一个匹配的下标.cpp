#include<iostream>
#include<cmath>
using namespace std;

int strstr(string haystack, string needle)
{
	if(haystack.size()<needle.size()) return -1;
	for(int p=0;p<=haystack.size()-needle.size();p++) //ע�ⷶΧ and <=
	{	
		bool same=1;
		for(int q=0;q<needle.size();q++)
		{
			if(haystack[p+q]!=needle[q]) same=0;
		}
		
		if(same==1) return p;
	}
	return -1;
} 

int main()
{
	string s1="a";
	string s2="a";
	cout<<strstr(s1,s2)<<endl;

	return 0;
}

