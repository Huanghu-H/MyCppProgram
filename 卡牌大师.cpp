#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//Return the cards
char* GetCards()
{
    char* cards = NULL;
    //ToDo
    string a;
    cin>>a;
    *cards=&a;
    return cards;
}
//ToDo
//Attention!! cards[i] is forbidden!!
void SortCards(char* cards)
{
	
}
//Output the sorted cards
//ToDo
void Output(char* cards)
{
	cout<<*cards;
}
int main()
{
	string a;
	char* cards = GetCards();
    SortCards(cards);
    Output(cards);
}
	
