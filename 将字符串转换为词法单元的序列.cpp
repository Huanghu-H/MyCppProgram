#include<iostream>
#include<cmath>
using namespace std;
/*
x = a + b
a = a + b * c / d
c = 123
ab = cde

abc 123 1 +x - * / 0

identifier x
=
identifier a
+
identifier b
identifier a
=
identifier a
+
identifier b
*
identifier c
/
identifier d
identifier c
=
integer 123
identifier ab
=
identifier cde
endofinput

abc 123 1 +x - * / 0

identifier abc
integer 123
integer 1
+
identifier x
-
*
/
integer 0
endofinput
*/
class lexer
{   private:
		int position;
		int integer;
		char c[105];
		int type;//1 整数，2 标识符 
	public:
		int flag;
		int gettoken(char x)
		{
			for(int i=0;i<100;i++)c[i]='\0';
			integer=0;
			position=0;
			while(x>0)
			{
				if(position==0)
				{
					if(x=='+')cout<<"+"<<endl;
					else if(x=='-')cout<<"-"<<endl;
					else if(x=='*')cout<<"*"<<endl;
					else if(x=='/')cout<<"/"<<endl;
					else if(x=='=')cout<<"="<<endl;
					else if(x=='0')cout<<"integer 0"<<endl;
					else if(x>='1'&&x<='9')
					{
						type=1;integer=10*integer+((int)x-(int)'0');position++;
					}
					else if(x==' '||x=='\n');
					else
					{
						if(x<0)break;
						type=2;c[position]=x;position++;
					}
				}
				else 
				{
					if(x>='0'&&x<='9')
					{
						type=1;integer=10*integer+((int)x-(int)'0');position++;
					}
					else if(x==' '||x=='\n')
					{
						if(type==1)cout<<"integer "<<integer<<endl;
						if(type==2)cout<<"identifier "<<c<<endl;
						position=0;
						return 1;
					}
					else 
					{
						if(x<0)break;
						type=2;c[position]=x;position++;
					}
					
				}
				x=getchar();
			}
			return 0;
		}
};

int main()
{
	char x;
	lexer str;
	str.flag=1;
	while(str.flag)
	{
		x=getchar();
		str.flag=str.gettoken(x);
	}
	cout<<"endofinput"<<endl;
	return 0;
}

