#include<iostream>
#include<cmath>
#include<unordered_set>
using namespace std;

//abcabcbb 3

int lengthOfLongestSubstring(string s) 
{
    int max=0;
    unordered_set<char> hash;
    int left=0,right=0;
    while(s[left]!='\0'&&s[right]!='\0')
    {
        // cout<<left<<" "<<right<<endl;
        if(hash.find(s[right])==hash.end()) // 不重复
        {
            hash.insert(s[right]);
            right++;
            if(hash.size()>max) max=hash.size();
        }
        else // 重复元素
        {        
            hash.erase(s[left]);
            left++;
        }
    }
    return max;
}

int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}