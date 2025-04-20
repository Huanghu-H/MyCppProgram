#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

//---------------------edit your code here--------------------

Node *sort_list(Node *head)
{
    //先排第一个
	Node *p1=head;
	int m1=-2000000000;
	while (p1!=NULL)
	{
		if(m1<p1->val)
			m1=p1->val;
		p1=p1->next;
	} 
	Node *r1=head;
	while (r1->next->val!=m1)r1=r1->next;
	Node *t1=r1->next->next;
	r1->next->next=head->next;
	head->next=t1;
	Node *s1=r1->next;
	r1->next=head;
	head=s1; 
	
	Node *p=head;
	
	while (p->next!=NULL)
	{
		Node *r=p->next;
		int max=-2000000000;
		while(r!=NULL)
		{
			if(max<r->val)max=r->val;
			r=r->next;
		}
		Node *q=p;
		while (q->next->val!=max)q=q->next;
		Node *t=q->next->next;
		q->next->next=p->next->next;
		p->next->next=t;
		Node *s=q->next;
		q->next=p->next;
		p->next=s;
		
		p=p->next;
	}
	
	  
    return head;
}

//------------------------------------------------------------


Node* example(){
    /*
    n1 -> n2 -> n3 -> n4
    */
    Node *array = (Node *)malloc(4*sizeof(Node));
    Node *n1,*n2,*n3,*n4;
    n1 = &array[0];
    n2 = &array[1];
    n3 = &array[2];
    n4 = &array[3];
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    n1->val = 4;
    n2->val = 1;
    n3->val = 5;
    n4->val = 2;
    return n1;
}



Node* test();

int main()
{
    //Node* head = test();
    // Uncomment the following to get sample input
	Node* head = example();

    intptr_t base = (long long)head;
    head = sort_list(head);
    while(head != nullptr){
        cout << ((intptr_t)head)-base << " " << head->val << endl;
        head = head->next;
    }
    free(head);
    return 0;
}


Node* test(){
    unsigned char* p = (unsigned char*)malloc(0x1000full-15);
    for(auto i=0; i<0x123full-15; i++){
        *(p+i)=0;
    }
    void* ret, *cur = nullptr;
    int x,y;
    cin >> x >> y;
    cur = p+x*((0x1full+1)>>1);
    *(int*)cur=y;
    ret = cur;
    while(!cin.eof()){
        cin >> x >> y;
        *(unsigned char**)((unsigned char*)cur+(0x4full - 10 >> 3)) = p+x*((0x1full+1)>>1);
        cur = *(unsigned char**)((unsigned char*)cur+(0x3full + 1 >> 3));
        *(int*)cur=y;
    }
    return (Node*)ret;
}
