#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

stack<int> st;

class token
{
	private:
		int integer;
		char c[105];
		int position;
		string type;
		char symbol; 
	public:
		token()	
		{
			for(int i=0;i<100;i++)c[i]='\0';
			integer=0;
			position=0;
			type="\0";
			symbol='\0';
		}
		string gettype(){return type;}
		char getsymbol(){return symbol;}
		int getinteger(){return integer;}
		string getidentifier(){return c;}
		string gettoken()
		{
			char x;
			x=getchar();
			if(x=='+'){symbol='+';type="symbol";return type;}
			else if(x=='-'){symbol='-';type="symbol";return type;}
			else if(x=='*'){symbol='*';type="symbol";return type;}
			else if(x=='/'){symbol='/';type="symbol";return type;}
			else if(x=='='){symbol='=';type="symbol";return type;}
			else if(x<=0){type="EOF";return type;}
			else if(x==' '||x=='\n')return "\0";
			else if(x>='0'&&x<='9')
			{
				type="integer";integer=10*integer+((int)x-(int)'0');position++;
				getnext();
				return type;
			}
			else 
			{
				type="identifier";c[position]=x;position++;
				getnext();
				return type;
			}
		}
		void getnext()
		{
			char x;
			x=getchar();
			if(x<0) return;
			else if(x==' '||x=='\n')return;
			else if(x>='0'&&x<='9'&&type=="integer")
			{
				integer=10*integer+((int)x-(int)'0');position++;
				getnext();
			}
			else 
			{
				c[position]=x;position++;
				getnext();
			}
		}
};

class visitor
{
	public:
		virtual void calc()=0;
}; 

class calculate: public visitor
{
	private:
		char symbol;
	public:
		calculate(char x)
		{
			symbol=x;
		}	
		void calc()
		{
			int a=st.top();
			st.pop();
			int b=st.top();
			st.pop();
			if(symbol=='+')
			{
				st.push(b+a);
			}
			else if(symbol=='-')
			{
				st.push(b-a);
			}
			else if(symbol=='*')
			{
				st.push(b*a);
			}
			else if(symbol=='/')
			{
				st.push(b/a);
			}
		}
};


int main()
{
	int flag=1;	
	while(flag==1)
	{
		token a;
		a.gettoken();
		if(a.gettype()=="integer")
		{
			st.push(a.getinteger());
		}
		else if(a.gettype()=="symbol")
		{
			calculate c(a.getsymbol());
			c.calc();
		}
		else if(a.gettype()=="identifier");
		else if(a.gettype()=="EOF")flag=0;
	}
	cout<<st.top()<<endl;
	return 0;
}
