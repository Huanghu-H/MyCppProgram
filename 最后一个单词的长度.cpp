#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

int LastWordlength(string s)
{
	stack<int> stk;
	int length=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' '&&length!=0) 
		{
			stk.push(length);
			length=0;
		}
		else if(s[i]!=' ')length++;
	}
	if(length!=0) stk.push(length);
	return stk.top();
} 


int main()
{
	string s="       Hello World111";
	cout<<LastWordlength(s)<<endl;

	return 0;
}

