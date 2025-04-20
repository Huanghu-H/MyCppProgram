#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//2 -12 2 12
int g(int a1[],int a2[]);
struct BigInt
{
    int len;
    int sign;
    char data[1001];
};
void f(int a1[],int a2[],int s1,int s2)
{
	if(s1==1&&s2==1)
	{
		int p[1005]={0};
		for(int i=0;i<=1005;i++)
		{
			p[i]+=a1[i]+a2[i];
			if(p[i]>=10)
			{
				p[i]-=10;
				p[i+1]++;
			}
		}
		//cout<<p[3]<<endl;
		int wei=1;
		for(int i=1005;i>=0;i--)
		{
			if(p[i]!=0)
			{
				wei=i+1;
				break;	
			}
		}
		for(int i=wei-1;i>=0;i--)
		{
			cout<<p[i];
		}
		cout<<endl;return;
	}
	if(s1==-1&&s2==-1)
	{
		cout<<"-";
		int p[1005]={0};
		for(int i=0;i<=1005;i++)
		{
			p[i]+=a1[i]+a2[i];
			if(p[i]>=10)
			{
				p[i]-=10;
				p[i+1]++;
			}
		}
		int wei=1;
		for(int i=1005;i>=0;i--)
		{
			if(p[i]!=0)
			{
				wei=i+1;
				break;	
			}
		}
		for(int i=wei-1;i>=0;i--)
		{
			cout<<p[i];
		}
		cout<<endl;return;
		
	}
	if(s1!=s2)
	{
		if(g(a1,a2)==1)
		{
			if(s1==-1)cout<<'-';
			int m[1005]={0};
			for(int i=0;i<=1005;i++)
			{
				m[i]+=a1[i]-a2[i];
				if(m[i]<0)
				{
					m[i]+=10;m[i+1]--;
				}
			}
			int wei=0;
			for(int i=1005;i>=0;i--)
			{
				if(m[i]!=0)
				{
					wei=i+1;
					break;	
				}
			}
			for(int i=wei-1;i>=0;i--)
			{
				cout<<m[i];
			}
			cout<<endl;return;
			
		}
		if(g(a1,a2)==2)
		{
			if(s2==-1)cout<<'-';
			int m[1005]={0};
			for(int i=0;i<=1005;i++)
			{
				m[i]+=a2[i]-a1[i];
				if(m[i]<0)
				{
					m[i]+=10;m[i+1]--;
				}
			}
			int wei=0;
			for(int i=1005;i>=0;i--)
			{
				if(m[i]!=0)
				{
					wei=i+1;
					break;	
				}
			}
			for(int i=wei-1;i>=0;i--)
			{
				cout<<m[i];
			}
			cout<<endl;return;
		}
		if(g(a1,a2)==0)
		{
			cout<<0<<endl;
		}
	}
}
int g(int a1[],int a2[])
{
	for(int i=1005;i>=0;i--)
	{
		if(a1[i]==a2[i])continue;
		if(a1[i]<a2[i])return 2;
		if(a1[i]>a2[i])return 1;
	}
	return 0;
}
struct BigInt read_bigint() 
{
    struct BigInt bigint;
    // TODO(p3): Add your code here for reading a BigInt object from terminal
	int n;
	cin>>n;
	bigint.len=n;
	char a;
	cin>>a;
	if(a=='-')
	{
		bigint.sign=-1;
		for(int i=0;i<n;i++)
		{
			cin>>bigint.data[i];
		}	
	}
	else
	{
		bigint.sign=1;
		bigint.data[0]=a;
		for(int i=1;i<n;i++)
		cin>>bigint.data[i];
	} 

    return bigint;
}

void print_bigint(struct BigInt bigint) 
{
   // TODO(p3): Add your code here for printing a BigInt object to terminal

}


// return bigint1 + bigint2
struct BigInt add_bigint(struct BigInt bigint1, struct BigInt bigint2)
{
    struct BigInt ret;
    // TODO(p3): Add your code here, and return sum of bigint1 and bigint2
	int c1[10005];
	int c2[10005];
	
	for(int i=0;i<bigint1.len;i++)
	{
		c1[i]=(int)bigint1.data[bigint1.len-1-i]-(int)'0';
	}
	c1[bigint1.len]='\0';
	for(int i=0;i<bigint2.len;i++)
	{
		c2[i]=(int)bigint2.data[bigint2.len-1-i]-(int)'0';
	}
	c2[bigint2.len]='\0';
	int sign1,sign2;
	sign1=bigint1.sign;
	sign2=bigint2.sign;
	
	f(c1,c2,sign1,sign2);
	f(c1,c2,sign1,-sign2);
    return ret;
}

// return bigint1 - bigint2
struct BigInt sub_bigint(struct BigInt bigint1, struct BigInt bigint2) 
{
    struct BigInt ret;
    // TODO(sub): Add your code here, and return sub of bigint2 and bigint2
   

    return ret;
}

int main() 
{
    struct BigInt bigint1 = read_bigint();
    struct BigInt bigint2 = read_bigint();
    //cout<<bigint1.data<<endl<<bigint2.data<<endl; 
    print_bigint(add_bigint(bigint1, bigint2));
    print_bigint(sub_bigint(bigint1, bigint2));
    return 0;
}
