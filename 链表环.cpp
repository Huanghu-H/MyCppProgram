#include <iostream>
using namespace std;

struct Node 
{
    int val; // It will not be used in this question.
    Node *next;
};

//---------------------edit your code here--------------------

int get_ring_length(Node* head)
{
    // your code here
    Node *p=head;
	while(p->val!=1&&p->next!=NULL)
	{
		p->val=1;
		p=p->next;
	}
	if(p->next==NULL)return 0;
	p->val=2;
	int x=1;
	p=p->next;
	while(p->val==1)
	{
		x++;
		p=p->next;
	} 
    return x;
}

//------------------------------------------------------------


Node* example1(){
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
    return n1;
}


Node* example2(){
    /*
    n1 -> n2 -> n3 -> n4 -> n2 -> ...
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
    n4->next = n2;
    return n1;
}



Node* test();

int main()
{
    Node* head = test();
    // Uncomment the following to get sample input
    //Node* head = example1();
    //Node* head = example2();
    
    cout << get_ring_length(head) << endl;
    free(head);
    return 0;
}


Node* test(){
    unsigned char* p = (unsigned char*)malloc(0x1000full-15);
    for(auto i=0; i<0x123full-15; i++){
        *(p+i)=0;
    }
    void* ret, *cur = nullptr;
    int x;
    cin >> x;
    cur = p+x*((0x1full+1)>>1);
    ret = cur;
    while(!cin.eof()){
        cin >> x;
        *(unsigned char**)((unsigned char*)cur+(0x4full - 10 >> 3)) = p+x*((0x1full+1)>>1);
        cur = *(unsigned char**)((unsigned char*)cur+(0x3full + 1 >> 3));
    }
    return (Node*)ret;
}
