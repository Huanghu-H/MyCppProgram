#include<iostream>
#include<cmath>
using namespace std;

void output(int x)
{
	if(x==-1)return;
	else cout<<x<<" ";
}
//7 1 2 5 3 4 -1 6
void Snake_ergodic()
{
	int x;cin>>x;
	int data[10001];
	
	int Maxrow=0;
	for(;;Maxrow++)
	{
		if((int)pow(2,Maxrow)==x+1)break;
	}
	for(int i=0;i<10001;i++)data[i]=0;
	for(int i=0;i<x;i++)cin>>data[i];
	cout<<Maxrow<<endl;
	int p=0;int row=1;
	cout<<data[p]<<" ";
	
	while(row<Maxrow)
	{
		int row_length=(int)pow(2,row);
		int length=0;
		int sign=(int)pow(-1,row%2);
		if(sign==1) p=p+(int)pow(2,row-1);
		else p=p+(int)pow(2,row);
		output(data[p]);
		while(length<row_length-1)
		{
			p=p+sign;
			output(data[p]);
			length++;
		}
		row++;
	}
}

int main()
{
	Snake_ergodic();
	return 0;
}

