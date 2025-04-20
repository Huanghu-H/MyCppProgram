#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,vector<vector<int>>> calc_two_sum(vector<int>& nums)
{
	unordered_map<int,vector<vector<int>>> two_sum;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=i+1;j<nums.size();j++)
		{
			int sum=nums[i]+nums[j];
			auto it=two_sum.find(sum);
			
			vector<int> t;
			t.push_back(nums[i]),t.push_back(nums[j]);
			t.push_back(i),t.push_back(j);
			two_sum[sum].push_back(t);
		}
	}
	return two_sum;
}

vector<vector<int>> calc_three_sum(unordered_map<int,vector<vector<int>>> two_sum,vector<int>& nums)
{
	vector<vector<int>> ans;
	int index=0;
	for(auto nums_it:nums)
	{
		auto two_sum_it=two_sum.find(-nums_it);
		if(two_sum_it!=two_sum.end())
		{
			for(auto addend_it:two_sum[-nums_it])
			{
				vector<int> t=addend_it;
				if(index!=t[3]&&index!=t[4])t.insert(t.begin(),nums_it);
				ans.push_back(t);
			}
		}
		index++;
	}
	return ans;
}

int main()
{
	vector<int>	nums;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		nums.push_back(m);
	}
	unordered_map<int,vector<vector<int>>> two_sum;
	two_sum=calc_two_sum(nums);
//	for(auto& pair:two_sum)
//	{
//		cout<<pair.first<<endl;
//		for(auto it:pair.second)
//		{
//			cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
//		}
//		cout<<endl;
//	}
	vector<vector<int>> ans;
	ans=calc_three_sum(two_sum,nums);
	for(auto it:ans)
	{
		cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
	}
	return 0;
}

