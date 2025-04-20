#include<iostream>
#include<cmath>
using namespace std;
#define NumSets 100


void Initialize(int S[])
{	
	for(int i=NumSets;i>0;i--)S[i]=0;
}
void Union(int S[],int Root1,int Root2)
{
	S[Root2]=Root1;
}
int Find(int X,int S[])
{
	if(S[X]<=0)return X;
	else return Find(S[X],S);
} 

int main()
{


	return 0;
}

