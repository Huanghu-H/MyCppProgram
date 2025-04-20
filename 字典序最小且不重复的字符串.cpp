#include<iostream>
using namespace std;

int position[27];
char c[5000001];
//cbacdcbc
void run(char s[])
{
	int length=0;
	for(;s[length]!='\0';length++);
	for(int i=0;i<length;i++)
	{
		if(position[s[i]-'a']==-1)
		{
			position[s[i]-'a']=i;
		}
	}
	for(int index=25;index>0;index--)
	{
		int have_small=0;
		int position_of_small=length+1;
		for(int i=0;i<length;i++)
		{	
			if(s[i]<'a'+index&&i>position[index])
			{
				have_small=1;position_of_small=i;
			}
			if(s[i]=='a'+index&&i>position_of_small&&have_small==1)
			{
				have_small=0;s[position[index]]=123;position[index]=i;
			}
			if(s[i]=='a'+index&&i>position[index])
			{
				s[i]=123;
			}
		}
	}
	for(int i=0;i<length;i++)
	{
		if(s[i]<123)cout<<s[i];
	}	
}	
int main()
{
	for(int i=0;i<26;i++)position[i]=-1;
	cin>>c;
	run(c);
	return 0;
}

