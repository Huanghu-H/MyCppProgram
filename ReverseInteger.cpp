#include<iostream>
#include<cmath>
using namespace std;

/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。
*/

int reverse(int x) 
{
    int ans=0;
    bool sign=x>0;
    if(!sign&&x!=-2147483648) x=-x;
    else if(x==-2147483648) return 0; 
    while(x>9)
    {
        int rem=x%10;
        x/=10;
        ans*=10;
        ans+=rem;
    }
    if((ans>214748364&&x>8)||(ans>214748364&&x>0)) return 0;
    else if(sign==1&&ans==214748364&&x==8) return 0;
    else 
    {
        if(x>0) ans=ans*10+x;
        if(sign==0) return -ans;
        else return ans;
    }
}

int main() 
{
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
    return 0;
}