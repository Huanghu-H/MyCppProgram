#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	int left=0,right=nums.size()-1;
	if(target>nums[right]) return right+1;
	if(target<nums[left]) return left;

	while(1)
	{
		cout<<left<<" "<<right<<endl;
		int middle=(right+left)/2;
		if(right-left<=1) 
		{
			if(right==left)return left;
			else if(nums[left]>=target) return left;
			else return right; 
		}
		else if(target<=nums[middle]) 
		{
			right=middle;
			continue;
		}
		else 
		{
			left=middle+1;
			continue;
		}
	}	        
}

int main()
{
	vector<int> v={3,4,5,6,7,8};
	cout<<searchInsert(v,6)<<endl;

	return 0;
}

