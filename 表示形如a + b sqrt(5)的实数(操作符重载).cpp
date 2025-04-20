#include<iostream>
#include<cmath>
using namespace std;


class aplusbsqrt5
{
	private:
		long long a,b,c,d;
	public:
		void out()
		{
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		}
		aplusbsqrt5()
		{
			a=1;b=1;c=0;d=1;
		}
		aplusbsqrt5(long long a1,long long b1,long long c1,long long d1)
		{
			a=a1;b=b1;c=c1;d=d1;
		}
		aplusbsqrt5 operator + (aplusbsqrt5& x)
		{
			aplusbsqrt5 t;
			t.a=a*x.b+b*x.a;
			t.b=b*x.b;
			t.c=c*x.d+d*x.c;
			t.d=d*x.d;
			long long p,m=t.a,n=t.b;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.a=t.a/n;t.b=t.b/n;
		    m=t.c,n=t.d;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.c=t.c/n;t.d=t.d/n;
			return t;
		}
		aplusbsqrt5 operator - (aplusbsqrt5& x)
		{
			aplusbsqrt5 t;
			t.a=a*x.b-b*x.a;
			t.b=b*x.b;
			t.c=c*x.d-d*x.c;
			t.d=d*x.d;
			long long p,m=t.a,n=t.b;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.a=t.a/n;t.b=t.b/n;
		    m=t.c,n=t.d;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.c=t.c/n;t.d=t.d/n;
			return t;
		}
		aplusbsqrt5 operator * (aplusbsqrt5& x)
		{
			aplusbsqrt5 t;
			t.a=a*x.a*d*x.d+5*c*x.c*b*x.b;
			t.b=b*x.b*d*x.d;
			t.c=c*x.a*b*x.d+a*x.c*d*x.b;
			t.d=b*x.b*d*x.d;
			long long p,m=t.a,n=t.b;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.a=t.a/n;t.b=t.b/n;
		    m=t.c,n=t.d;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.c=t.c/n;t.d=t.d/n;
			return t;
		}
		aplusbsqrt5 operator / (aplusbsqrt5& x)
		{
			aplusbsqrt5 t;
			t.a=x.b*x.d*(a*x.a*d*x.d-5*c*x.c*b*x.b);
			t.b=b*d*(x.a*x.a*x.d*x.d-5*x.b*x.b*x.c*x.c);
			t.c=x.b*x.d*(b*c*x.a*x.d-a*d*x.c*x.b);
			t.d=b*d*(x.a*x.a*x.d*x.d-5*x.b*x.b*x.c*x.c);
			long long p,m=t.a,n=t.b;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.a=t.a/n;t.b=t.b/n;
		    m=t.c,n=t.d;
		    while(p=m%n)
			{
		        m=n;
		        n=p;
		    }
		    if(n<0)n=-n;
		    t.c=t.c/n;t.d=t.d/n;
		    if(t.b<0)
		    {
		    	t.a=-t.a;t.b=-t.b;
			}
			if(t.d<0)
			{
				t.c=-t.c;t.d=-t.d;
			}
			return t;
		}
};

int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a,b,c,d,e,f,g,h,judge;
		cin>>judge;
		if(judge!=4)
		{
			cin>>a>>b>>c>>d>>e>>f>>g>>h;
			aplusbsqrt5 x(a,b,c,d);
			aplusbsqrt5 y(e,f,g,h);
			aplusbsqrt5 z;
			if(judge==0)z=x+y;
			else if(judge==1)z=x-y;
			else if(judge==2)z=x*y;
			else if(judge==3)z=x/y;
			z.out();
		}
		else 
		{
			cin>>a>>b>>c>>d>>e;
			aplusbsqrt5 x(a,b,c,d);
			aplusbsqrt5 z;
			for(int j=0;j<e;j++)
			z=z*x;
			z.out();
		}
	}
	
	return 0;
}

