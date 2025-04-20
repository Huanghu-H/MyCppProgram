#include<iostream>
#include<cmath>
#include<set> 
using namespace std;
set<int> s;
int n;
int in,an;
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
		if(in==1)
		{
			cin>>an;s.insert(an);
		}
		else if(in==2)
		{
			cin>>an;s.erase(an);
		}
		else if(in==3)
		{
			cout<<s.size(); puts("");
		}
		else if(in==4)
		{
			if(s.size()!=0)
			{
				cout<<*s.rbegin(); puts("");
			}
			else cout<<"Stop playing games, fei.\n"; 
		}
		else if(in==5)
		{
			cin>>an;
			set<int>::iterator it;
			it=s.lower_bound(an);
			if(it==s.end())
				cout<<"Stop playing games, fei.\n";
			else
				{cout<<*it; puts("");}
		}
	}	
	return 0;
}

