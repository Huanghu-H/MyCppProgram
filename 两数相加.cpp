/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int num1=0, num2=0;
        ListNode* ans=nullptr; 
        ListNode* tail=nullptr;
        int in=0;
        while(!(l1==nullptr&&l2==nullptr&&in==0))
        {
            if(l1==nullptr&&l2==nullptr)
            {
                num1=num2=0;
            }
            else if(l1==nullptr) 
            {
                num2=l2->val;num1=0;
            }
            else if(l2==nullptr)
            {
                num1=l1->val;num2=0;
            }
            else
            {
                num1=l1->val;num2=l2->val;
            } 
            ans=addNewNode(num1,num2,in,tail,ans);
            
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        return ans;
    }

    ListNode* addNewNode(int x, int y, int& in, ListNode*& tail, ListNode* ans)
    {
        int sum=x+y+in;
        if(sum>=10)
        {
            sum-=10; in=1;
        }
        else in=0;
        if(tail==nullptr) 
        {
            tail=new ListNode(sum);
            return tail;
        }
        else
        {
            ListNode* l=new ListNode(sum);
            tail->next=l;
            tail=l;
        }
        return ans;
    }  

};
