#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/*
5 12345 1234 12567 12543 12 
*/
string prefix(vector<string>& strs)
{
	string ans="\0";
	int index=0;
	bool same=1;
	while(same)
	{
		bool begin=1;
		char c='\0';
		for(auto it:strs)
		{
//			if(it[index]=='\0') 
//			{
//				same=0;break;
//			}
			if(begin==1)
			{
				c=it[index];
				begin=0;
			}
			else if(it[index]!=c)
			{
				same=0;break;
			}
		}
		if(same==1)
		{
			ans+=c;
		}
		index++;
	}
	return ans;
} 


int main()
{
	int n;
	cin>>n;
	vector<string> strs;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		strs.push_back(s);
	}
	cout<<prefix(strs)<<endl;
	return 0;
}

