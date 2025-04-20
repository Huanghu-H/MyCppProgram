#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
I:1 V:5 
X:10 L:50
C:100 D:500
M:1000
*/
int main()
{
	string c;
	cin>>c; 
	
	int ans=0;
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i+1]!='\0') 
		{
			if(c[i]=='C'&&c[i+1]=='M') 
			{
				ans+=900;i++;continue;
			}
			else if(c[i]=='C'&&c[i+1]=='D')
			{
				ans+=400;i++;continue;
			}
			else if(c[i]=='X'&&c[i+1]=='C')
			{
				ans+=90;i++;continue;
			}
			else if(c[i]=='X'&&c[i+1]=='L')
			{
				ans+=40;i++;continue;
			} 
			else if(c[i]=='I'&&c[i+1]=='X')
			{
				ans+=9;i++;continue;
			}
			else if(c[i]=='I'&&c[i+1]=='V')
			{
				ans+=4;i++;continue;
			}
		}
		if(c[i]=='M') ans+=1000;
		else if(c[i]=='D') ans+=500;
		else if(c[i]=='C') ans+=100;
		else if(c[i]=='L') ans+=50;
		else if(c[i]=='X') ans+=10;
		else if(c[i]=='V') ans+=5;
		else if(c[i]=='I') ans+=1;
	}
	cout<<ans<<endl;
	return 0;
}

