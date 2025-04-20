#include<iostream>
#include<cmath>
using namespace std;

class stack
{
	private:
		int top;
		int x[2];
	public:
		int m;
		stack(){top=-1;m=2;};
		void push(int i)
		{
			top++;
			x[top]=i;
		}
		void pop(int &i)
		{
			i=x[top];
			top--;
		}
};


int a[1005];

int main()
{
	stack st;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	st.push(0);
	st.push(1);
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)cout<<0<<endl;
		else if(a[i]==1)cout<<1<<endl;
		else if(a[i]<st.m)
		{
			int temp1,temp2;
			while(a[i]<=st.m)
			{	 
				st.pop(temp1);
				st.pop(temp2);
				st.push(temp1-temp2);
				st.push(temp2);
				st.m--;
			} 
			cout<<temp1+temp2<<endl;
			//¼õÉÙ 
		}
		else if(a[i]>st.m)
		{
			int temp1,temp2;
			while(a[i]>=st.m)
			{
				st.pop(temp1);
				st.pop(temp2);
				//cout<<temp1<<" "<<temp2<<endl;
				st.push(temp1);
				st.push(temp1+temp2);
				//cout<<st.m<<" "<<a[i]<<" "<<a[i]<<" "<<temp1<<" "<<temp2<<endl;
				st.m++;
			}
			cout<<temp1+temp2<<endl;
			//Ôö¼Ó 
		} 
		else 
		{
			int temp1,temp2;
			st.pop(temp1);st.pop(temp2);
			st.push(temp2);st.push(temp1);
			cout<<temp1+temp2<<endl;
		} 
	}
	
	return 0;
}

