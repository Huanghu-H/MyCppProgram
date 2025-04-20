#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef int longlong;

class token
{
	public:
		string type;
		char symbol;
		int value;
		token(char x)
		{
			if(x<='9'&&x>='0')
			{
				type="int";
				value=(int)x-'0';
			}
			else
			{
				type="sym";
				symbol=x;
			}
		}
} ;

vector<token> tk;

void f()
{
	for()
}

int main()
{
	int L;
	cin>>L;
	for(int i=0;i<L;i++)
	{
		char x;
		cin>>x;
		token a(x);
		tk.push_back(a);
	}
	f();	
	return 0;
}

