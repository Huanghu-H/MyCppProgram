#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

class brct
{
	public:
		int num;
		int value;
		brct(char c,int n)
		{
			num=n;
			if(c=='(')value=-1;
			else value=1;
		}
};
stack<brct> st;
int tag[1000005];

int main()
{
	for(int i=0;i<1000005;i++)
	{
		tag[i]=1;
	}
	
	int L;cin>>L;
	for(int i=0;i<L;i++)
	{
		char c;cin>>c;
		brct b(c,i);
		if(st.empty()!=1&&st.top().value==-1&&c==')')
		{	
			tag[i]=0;
			tag[st.top().num]=0;
			st.pop();
		}
		else st.push(b);		
	}
	
	int maxlength=0;
	int currentlength=0;
	for(int i=0;i<L;i++)
	{
		if(tag[i]==0)
		{
			currentlength++;
		}
		else currentlength=0;
		if(currentlength>maxlength)
		{
			maxlength=currentlength;
		}
	}
	cout<<maxlength;
	return 0;
}

