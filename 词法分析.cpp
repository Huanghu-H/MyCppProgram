#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> variable;

class token
{
	private:
		int integer;
		char c[105];
		int position;
		int value; 
		string type;
		char symbol;
		bool next_is_semicolon;
	public:
		token()	
		{
			for(int i=0;i<100;i++)c[i]='\0';
			integer=0;
			position=0;
			type="\0";
			symbol='\0';
			value=0;
			next_is_semicolon=0;
		}
		string gettype(){return type;}
		char getsymbol(){return symbol;}
		int getinteger(){return integer;}
		string getidentifier(){return c;}
		bool getnext_is_semicolon(){return next_is_semicolon;}
		string gettoken()
		{
			char x;
			x=getchar();
			if(x=='+'){symbol='+';type="symbol";return type;}
			else if(x=='-'){symbol='-';type="symbol";return type;}
			else if(x=='*'){symbol='*';type="symbol";return type;}
			else if(x=='/'){symbol='/';type="symbol";return type;}
			else if(x=='='){symbol='=';type="symbol";return type;}
			else if(x==';'){next_is_semicolon=1;type="semicolon";return type;} 
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
			else if(x==';')
			{
				next_is_semicolon=1;return;
			}
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
		void clear()
		{
			for(int i=0;i<100;i++)c[i]='\0';
			integer=0;
			position=0;
			type="\0";
			symbol='\0';
			value=0;
			next_is_semicolon=0;
		}
};

class expression
{
	private:
		vector<token> tk;
	public:
		token a;
		expression()
		{
			tk.clear();
		}
		void getexpression()
		{	
			while(a.gettype()!="EOF")
			{
				a.clear();
				a.gettoken();
				tk.push_back(a);
				while(a.getnext_is_semicolon()!=1&&a.gettype()!="EOF")
				{
					a.clear();
					a.gettoken();
					tk.push_back(a);
				}
				exp_judge();
				exp_calc();
				exp_clear();
			}
		}
		void coutexpression()
		{
			for(auto it:tk)
			{
				if(it.gettype()=="identifier")cout<<it.getidentifier()<<" ";
				else if(it.gettype()=="integer")cout<<it.getinteger()<<" ";
				if(it.getnext_is_semicolon()==1)cout<<";"<<endl;
			}
		}
		void exp_judge()
		{
			//for()
		}
		void exp_calc()
		{
			
		}
		void exp_clear()
		{
			
		}	
};


int main()
{
	expression a;
	a.getexpression();
	a.coutexpression();

	return 0;
}


//	int flag=1;	
//	while(flag==1)
//	{
//		token a;
//		a.gettoken();
//		if(a.gettype()=="integer")cout<<a.gettype()<<" "<<a.getinteger()<<endl;
//		else if(a.gettype()=="symbol")cout<<a.getsymbol()<<endl;
//		else if(a.gettype()=="identifier")cout<<a.gettype()<<" "<<a.getidentifier()<<endl;
//		else if(a.gettype()=="EOF")flag=0;
//	}
//	cout<<"endofinput"<<endl;

