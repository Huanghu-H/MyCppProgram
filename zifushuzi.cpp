#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
extern int f(char a);
using namespace std;
//Return the cards
char* GetCards()
{
    char* cards=NULL;
    //ToDo
    char* a=new char[105];
    cin>>a;
    cards=a;
    return cards;
}
//ToDo
//Attention!! cards[i] is forbidden!!
void SortCards(char* cards)
{
	char *p1=cards;
	char *p2=cards;
	for(;*(p1+1)!='\0';p1++)
	{
		for(p2=p1+1;*p2!='\0';p2++)
		{
			if(f(*p1)<f(*p2))
			{
				int t=*p1;
				*p1=*p2;
				*p2=t;
			}
		}
	}
	
}
int f(char a)
{
	if(a=='3')return 3;
	if(a=='4')return 4;
	if(a=='5')return 5;
	if(a=='6')return 6;
	if(a=='7')return 7;
	if(a=='8')return 8;
	if(a=='9')return 9;
	if(a=='T')return 10;
	if(a=='J')return 11;
	if(a=='Q')return 12;
	if(a=='K')return 13;
	if(a=='A')return 14;
	if(a=='2')return 15;
}
//Output the sorted cards
//ToDo
void Output(char* cards)
{
	cout<<cards<<endl;
}
int main()
{
	char* cards = GetCards();
    SortCards(cards);
    Output(cards);
}
	
