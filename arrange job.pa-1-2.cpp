#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#define MAX 105

bool compare(pair<int, int>& a,pair<int, int>& b) 
{
    return a.first>b.first;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&compare)> Q1(compare);
priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&compare)> Q2(compare);
int n,ans,time;
int r[MAX],p[MAX];

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i]>>p[i];
		Q1.push(make_pair(r[i],i));
	}
	ans=0;	
	time=Q1.top().first;
}

int arrange()
{
	pair<int,int> former=Q1.top();
	Q1.pop();
	Q2.push(make_pair(p[former.second],former.second));
	pair<int,int> later,t;
		
	while(!Q1.empty())
	{
		later=Q1.top();
		Q1.pop();
		
		while(time<r[later.second])
		{
			if(Q2.empty())
			{
				time=later.first;
				break;
			}
			
			t=Q2.top();
			Q2.pop();
			r[t.second]=time;
			
			if(t.first<r[later.second]-time)
			{
				time=time+t.first;
				ans+=time;
				//cout<<t.second<<" "<<time<<endl;
			}
			else
			{
				t.first-=r[later.second]-time;
				time=later.first;
				Q2.push(t);
				break;
			}			
		}
		//cout<<"top: "<<Q2.top().first<<" "<<Q2.top().second<<endl;
		//cout<<"time: "<<time<<endl;
		former=later;
		Q2.push(make_pair(p[former.second],former.second));
	}
	while(!Q2.empty())
	{
		t=Q2.top();
		Q2.pop();
		
		time=time+t.first;//cout<<time<<endl;
		ans+=time;
	}
	return ans;
}
int main()
{
	init();
	
	cout<<endl<<arrange()<<endl;
	
	return 0;
}

