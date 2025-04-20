#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> v;

int main()
{
	for(int i=1;i<=10;i++)v.push_back(i);
	for(auto it:v)
	{
		cout<<it<<endl;
	}
	return 0;
}

