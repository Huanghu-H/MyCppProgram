#include<iostream>
#include<string>
using namespace std;

string findOdd(string s)
{
    string longest;
    int mid=0,wide=0;

    while(mid!=s.size())
    {   
        while((mid-wide>=0)&&(mid+wide<s.size()))
        {
            if(s[mid-wide]==s[mid+wide]) wide++;
            else break;
        }
        if(longest.size()<2*wide-1) longest=s.substr(mid-wide+1,2*wide-1);
        mid++;wide=0;
    }
    return longest;
}
string findEven(string s)
{
    string longest;
    int lmid=0,wide=0;

    while(lmid!=s.size()-1)
    {
        while((lmid-wide>=0)&&(lmid+1+wide<s.size()))
        {
            if(s[lmid-wide]==s[lmid+1+wide]) wide++;
            else break;
        }
        if(longest.size()<2*wide) longest=s.substr(lmid-wide+1,2*wide);
        lmid++;wide=0;
    }
    return longest;
}

string longestPalindrome(string s) 
{   
    string s0=findOdd(s);
    string s1=findEven(s);
    if(s0.size()>s1.size()) return s0;
    else return s1;
}

int main() 
{
    string s;
    cin>>s;
    //cout<<s.substr(0,5)<<endl;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}