#include<iostream>
#include<cmath>
#include<vector> 
using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
	int carry=1;
	vector<int> ans=digits;
	for(int i=digits.size()-1;i>=0;i--)
	{	
		if(digits[i]==9&&carry==1)
		{
			ans[i]=0; 
		}
		else
		{
			ans[i]=digits[i]+carry;
			carry=0;			
		}
	} 
	if(carry==1)
	{
		ans.insert(ans.begin(),1);
	}
	return ans;
}

int main()
{
	vector<int> v={1,9,9,9,9,9,9,9,9,9,9,9,9};
	v=plusOne(v);
	for(auto it:v)
	{
		cout<<it<<" ";
	}

	return 0;
}

