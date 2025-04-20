#include<iostream>
#include<cmath>
using namespace std;

int zdgys (int m,int n){
    int a;
    while(a=m%n){
          m=n;
          n=a;
     }
     return n;
}

int main()
{
int a;int b;
cin>>a>>b;
cout<<zdgys(a,b)<<endl;

	return 0;
}

