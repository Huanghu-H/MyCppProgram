#include<iostream>
#include<cmath>
using namespace std;

int n,q;
int p2[50];
int in,zhishu;
int qian,yingbi,sum;


int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
		zhishu=log(in)/log(2);
		p2[zhishu]++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qian;
		for(int mi=32;mi>=0;mi--)
		{
			if(p2[mi])
			{
				yingbi=qian/pow(2,mi);
				if(yingbi>=p2[mi])//bugou
				{
					sum+=p2[mi];
				//	cout<<sum<<"   hjj"<<endl;
					qian-=p2[mi]*pow(2,mi);
					if(qian<=0)break;
				}
				else
				{
				//	cout<<" hjh"<<endl;
					sum+=yingbi;
					qian-=yingbi*pow(2,mi);
					if(qian<=0)break;
				}
			//	p2[mi]=0;
				
			}
		}
		if(qian==0)
		cout<<sum<<endl;
		else
		cout<<-1<<endl;
		sum=0;
	}
	
	
	
//	for(int i=0;i<=n;i++)
//	cout<<p2[i]<<endl;
	
	return 0;
}

