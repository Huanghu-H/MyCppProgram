#include<iostream>
#include<cmath>
using namespace std;


struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
        ListNode* ans=new ListNode(-1);
        ListNode* point=ans;
        while(!(list1==nullptr&&list2==nullptr))
        {
            int less=2;
            if(list1==nullptr) less=2;
            else if(list2==nullptr) less=1;
            else if(list1->val<list2->val) less=1;

            if(less==1)
            {
                ListNode* ls= new ListNode(list1->val,list1->next);
                list1=list1->next;
                point->next=ls;
            }
            else 
            {	
                ListNode* ls= new ListNode(list2->val,list2->next);
                list2=list2->next;
                point->next=ls;
            }           
            point=point->next;        
        }
        return ans->next;
}

int main()
{
	ListNode* L1=nullptr;
	ListNode* L2=new ListNode(0,nullptr);
	ListNode* L3=mergeTwoLists(L1,L2) ;
	if(L3==nullptr) cout<<"Nullptr"<<endl;
	else cout<<L3->val<<endl;
	return 0;
}

