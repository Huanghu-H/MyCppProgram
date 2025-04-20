#include<iostream>

using namespace std;
/*
42 42
 -042 -42
1337co0d 1337
0-1 0
word987 0
先读空格
后看正负
跳前置0
舍到int
截止字符
*/
#define MAXI 2147483647
#define MINI -2147483678

int myAtoi(string s)
{
    int index=0;
    long long ans=0;
    bool sign=1;
    while(s[index]==' ') index++;
    
    if(s[index]=='-')
    {
        sign=0;index++;
    }
    else if(s[index]=='+') index++;
    
    while(s[index]=='0') index++;
    while(s[index]<='9'&&s[index]>='0')
    {
        cout<<ans<<endl;
        ans*=10;
        ans+=s[index]-'0';
        index++;
        if(ans>MAXI&&sign==1) return MAXI;
        else if(ans>-MINI&&sign==0) return MINI;
    }
    if(sign==0) return -ans;
    else return ans;
}
int main() 
{
    string s;
    cin>>s;
    cout<<myAtoi(s)<<endl;
    return 0;
}