#include<iostream>
#include<cmath>
using namespace std;
class stack
{
	public:
		stack(){top=-1;}
		bool push(int i)
		{
			if(top==99)
			{
				cout<<"overflow"<<endl;
				return false; 
			}
			else
			{
				top++;
				buffer[top]=i;
				return true;
			}
		}
		bool pop(int &i)
		{
			if(top==-1)
			{
				cout<<"empty"<<endl;
				return false;
			}
			else 
			{
				i=buffer[top];
				top--;
				return true;
			}
		}
	private:
		int top;
		int buffer[100];
};
int main()
{
	stack st;
	st.push(12);
	int x;
	st.pop(x);
	cout<<x<<endl;

	return 0;
}

