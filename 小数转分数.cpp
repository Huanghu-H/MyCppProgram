#include<iostream>
#include<cmath> 
using namespace std;

typedef struct
{
    long long zheng;
    long long xiao;
    long long zi;
    long long mu;
}Fraction;


Fraction DecimalToFraction(char num[])
{
	Fraction ans;
	ans.zheng=0;
	ans.mu=0;
	int i=0;
    for(;num[i]!='\0'&&num[i]!='.';i++)
    {
    	ans.zheng=ans.zheng*10+((int)num[i]-(int)'0');
	}
	ans.zi=ans.zheng;
	int a=i;
	if(num[i]=='\0') return ans;
	i++;
	ans.zi=ans.zheng;
	//cout<<ans.zi<<" "<<ans.mu<<endl;
	for(;num[i]!='\0';i++)
	{
		ans.zi=ans.zi*10+((int)num[i]-(int)'0');
	}
	ans.mu=(int)pow(10,i-1-a);
	//cout<<ans.zi<<" "<<ans.mu<<endl;
	//yuefen
	int flag=1;
	while(flag==1)
	{ 	flag=0;
		for(int j=2;j<=ans.zi;j++)
		{
			if(ans.zi%j==0&&ans.mu%j==0)
			{
				ans.zi=ans.zi/j;
				ans.mu=ans.mu/j;
				flag=1;
			}
		}
	}
	return ans;
}

void FractionPrint(Fraction x)
{
	if(x.mu==0||x.mu==1)
	{
		cout<<x.zi<<endl;return;
	}
    cout<<x.zi<<"/"<<x.mu<<endl;
}

/*YOU CAN ADD ANY FUNCTIONS IF YOU WANT*/

int main()
{
    char num[20];
    cin >> num;
    Fraction result = DecimalToFraction(num);
    FractionPrint(result);
    return 0;
}

