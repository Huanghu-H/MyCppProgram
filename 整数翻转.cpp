#include<iostream>
#include<cmath>
using namespace std;
//��10��n-1�η�
long long p(int a) 
{
	return pow(10,a-1);
}
//������longlong��Χ�ڵ���������Ҳ�У� 
long long fanzhuan(long long a)
{
	int in[20]={0};
	int fan[20]={0};
	int wei=0;
	int out=0;
	int fu=0;
	if(a<0)
	{
		fu=-1;a=-a;
	}
	for(int i=1;i<=19;i++)
	{
		in[i]=(a/p(i))%10;
		if(in[i]) wei=i;
	}
	
	for(int i=1;i<=wei;i++)
	{
		fan[i]=in[wei+1-i];
		out+=fan[i]*p(i);
	}
	if(fu==-1) out=-out;
	return out;
}


int main()
{
	int a;
	cin>>a;
	cout<<fanzhuan(a)<<endl;
} 
