#include<iostream>

using namespace std;

string convert(string s, int numRows) 
{
    string ans;
    int cycle=2*(numRows-1); 
    if(numRows==1) cycle=1;   
    for(int row=0;row<numRows;row++)
    {
        int index=0;
        if(row==0||row==numRows-1)
        {
            index=row;
            while(index<s.size())
            {
                ans+=s[index];
                index+=cycle;
            }
        }
        else
        {
            index=row;
            while(index<s.size())
            {
                ans+=s[index];
                if(index+cycle-2*row<s.size()) ans+=s[index+cycle-2*row];
                index+=cycle;
            }
        }
    }
    return ans;
}

int main() 
{
    int numRows;
    string s;
    cin>>s>>numRows;
    cout<<convert(s,numRows)<<endl;
    return 0;
}