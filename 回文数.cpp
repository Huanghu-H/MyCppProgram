#include<iostream>
#include<cmath>
using namespace std;

bool isPalindrome(int x) 
{
	if(x<0) return 0;
	int forward = x;
    long long reverse = 0; 
    while(forward!=0)
    {
       	reverse += forward%10;
       	reverse *= 10;
    	forward /= 10;
    }
    return (reverse/10)==x;
}

int main()
{
	int x;
	cin>>x;
	cout<<isPalindrome(x);  

	return 0;
}

