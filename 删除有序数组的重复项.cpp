#include<iostream>
#include<cmath>
#include<vector> 
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	int pre=-10000;
	for(auto it=nums.begin();it!=nums.end();it++)
	{
		if(*it==pre) 
		{
			nums.erase(it);it--;
		}
		else pre=*it;
	}
	return nums.size();
}
int main()
{
	vector<int> nums={0,2,2,2,4,4,4,4,4,5,5,5,5,6};
	removeDuplicates(nums);
	for(auto it:nums)
	{
		cout<<it<<endl;
	}
	
	return 0;
}

