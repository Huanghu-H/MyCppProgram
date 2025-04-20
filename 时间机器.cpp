#include<iostream>
#include<iomanip>
using namespace std;

int a,b,c;
int n;
int k,h,m; 
	int ana[1000];
	int anb[1000];
	int anc[1000];
int main()
{
	cin>>a>>b>>c>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k>>h>>m;
//		while (m>=60)
//		{
//			m=m-60;
//			h=h+1;
//		}
//		while(h>=24)
//		{
//			h=h-24;
//		}
		if(k==1)
		{	
			if(i>1)c+=5;
			if(c>=60)
			{
				c=c-60;b=b+1;
			}

			b+=m;
			if(b>=60)
			{
				a=a+b/60;
				b=b%60;
			}

			
			a+=h;
			if(a>=24)a=a%24;	
		}
		if(k==0)
		{
			if(i>1)c+=5;
			if(c>=60)
			{
				c=c-60;b=b+1;
			}
			
			b-=m;
			if(b<0)//HERE IS WRONG 
			{
				a=a-(-b)/60-1;
				b=60-(-b)%60;
			}
			
			a-=h;
			if(a<0)a=24-(-a)%24;
			if(a==24)a=0;
			
						
		}
		ana[i]=a;anb[i]=b;anc[i]=c; 
		//cout<<"So far the time is "<< setw(2) << setfill('0') << a<<":"<< setw(2) << setfill('0') << b<<":"<< setw(2) << setfill('0') << c<<endl;
	}

	for(int i=1;i<=n;i++)
	{
		cout<<"So far the time is "<< setw(2) << setfill('0') << ana[i]<<":"<< setw(2) << setfill('0') << anb[i]<<":"<< setw(2) << setfill('0') << anc[i]<<endl;
	}
	return 0;
}

