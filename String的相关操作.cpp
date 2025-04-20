#include<iostream>
#include<cmath>
using namespace std;

class String
{
	private:
		char str[100];
	public:
		String(char x[])
		{
			for(int i=0;x[i]!='\0';i++)str[i]=x[i];
		} 
		String substring(int start,int length)
		{
			char a[100];
			for(int i=0;i<length;i++)
			{
				a[i]=str[i+start];
			}
			for(int i=0;str[i]!='\0';i++)str[i]='\0';
			for(int i=0;a[i]!='\0';i++)str[i]=a[i];
		}
		void display()
		{
			cout<<str<<endl;
		}
		void removespace()
		{	
			char a[100]={'\0'};
			int k=0;
			for(int i=0;str[i]!='\0';i++)
			{
				if(str[i]!=' ')
				{
					a[k]=str[i];k++;
				}
			}
			for(int i=0;str[i]!='\0';i++)str[i]='\0';
			for(int i=0;a[i]!='\0';i++)
			{
				str[i]=a[i];
			}
		}
}; 


int main()
{
	String s0("abcdefg");
	String s1("abcdefg");
	String s2("a     bc    d  ef");
//	cout<<s0.is_substring(s1);
//	s0.substring(3,3);
//	s0.display();
	s2.removespace();
	s2.display();
	return 0;
}

