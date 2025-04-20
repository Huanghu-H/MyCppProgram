#include<iostream>
#include<cmath>
#include<vector> 
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int i=0,j=0;
	vector<int> v;
	while(!(i==m&&j==n))
	{
		//cout<<i<<" "<<j<<endl;
		int less=2;
		if(i==m) less=2;
		else if(j==n) less=1;
		else if(nums1[i]<nums2[j]) less=1;
		
		if(less==1)
		{
			v.push_back(nums1[i]); i++;
		}
		else 
		{
			v.push_back(nums2[j]); j++;
		}  	
	} 
	nums1=v;    
}


int main()
{
	vector<int> v1={1,3,7,0,0,0};
	vector<int> v2={4,6,8};
	
	merge(v1,3,v2,3);
	for(auto it:v1)
		cout<<it<<endl;
	return 0;
}

