#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
/*
} 
){
*/
bool isValid(string s)
{
	stack<char> stk;
	for(int i=0;i<s.size();i++)
	{cout<<"A"<<endl;
		if(s[i]==')')
		{
			if(stk.empty()==1) stk.push(')');
			else if(stk.top()=='(')stk.pop();
			else stk.push(')');
		}
		else if(s[i]==']')
		{
			if(stk.empty()==1) stk.push(']');
			else if(stk.top()=='[')stk.pop();
			else stk.push(']');
		}
		else if(s[i]=='}')
		{
			if(stk.empty()==1) stk.push('}');
			else if(stk.top()=='{')stk.pop();
			else stk.push('}');
		}
		else stk.push(s[i]); 
	}
	if(stk.empty()==1) return 1;
	else return 0; 
} 


int main()
{
	string s;
	cin>>s;
	cout<<isValid(s)<<endl;
	
	return 0;
}

