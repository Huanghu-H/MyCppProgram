#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int solve_problem=0;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>=2)solve_problem++;
	}
	cout<<solve_problem<<endl;
	return 0;
}

