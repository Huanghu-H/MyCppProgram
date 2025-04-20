#include<iostream>
#include<cmath>
#include<set>
using namespace std;

set<int> s;
int n;
long long a[105];
int k[104];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i]>>a[i];
		int flag=0;
		s.insert(a[i]);
		
		while(flag!=1)
		{
			long long p=0;
			p=a[i]*a[i];
			while(p>=(int)pow(10,k[i]))
				p=p/10;
			a[i]=p;
			for(auto t:s)
			{
				if(t==p)flag=1;
			}
			s.insert(p);
		}
		//for(auto t:s)cout<<t<<endl;
		cout<<*(--s.end())<<endl;
		s.clear();
	}
	
	return 0;
}
//			cin>>an;s.insert(an);
//			cin>>an;s.erase(an);
//			cout<<s.size(); puts("");
//			cout<<*s.rbegin(); puts("");
//			set<int>::iterator it;
//			it=s.lower_bound(an);
	
