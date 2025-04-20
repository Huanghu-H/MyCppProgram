#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100000
class FibNode
{
public:
	int val;
	FibNode* parent;
	FibNode* son;
	FibNode* left;
	FibNode* right;
	int degree;
	int marked;
	int traversal;
	double x;
	double y;
	FibNode()
	{
		val=0;
		parent=nullptr;
		son=nullptr;
		left=nullptr;
		right=nullptr;
		degree=0;
		marked=0;
		traversal=0;
		x=0;
		y=0;
	}
	FibNode(int m)
	{
		val=m;
		parent=nullptr;
		son=nullptr;
		left=nullptr;
		right=nullptr;
		degree=0;
		marked=0;
		traversal=0;
		x=0;
		y=0;
	}
};
class FibHeap
{
public:
	FibNode* min;
	int n;
	FibHeap()
	{
		min=nullptr;
		n=0;
	}
};


void Insert(FibHeap* h,int x)
{
	FibNode* fn=new FibNode(x);
	if(h->min==nullptr)
	{
		h->min=fn;
		fn->left=fn;
		fn->right=fn;
	}
	else
	{
		FibNode* m=h->min;
		FibNode* l=m->left;
		l->right=fn;
		fn->left=l;
		fn->right=m;
		m->left=fn; 
		if(fn->val<m->val)
		{
			h->min=fn;
		}
	}
	h->n++;
}
FibHeap* heapUnion(FibHeap *h1, FibHeap *h2) 
{
    FibHeap *h=new FibHeap; 
 
    if (h!=NULL) 
	{ 
        if (h1->min==nullptr) 
		{
            h->min=h2->min;
        } 
		else if (h2->min==nullptr) 
		{
            h->min=h1->min;
        } 
		else 
		{
            FibNode *min_h1=h1->min;
            FibNode *min_right_h1=min_h1->right;
            FibNode *min_h2=h2->min;
            FibNode *min_right_h2=min_h2->right;
 
            min_h1->right=min_right_h2;
            min_right_h2->left=min_h1;
 
            min_h2->right=min_right_h1;
            min_right_h1->left=min_h2;
 
            if (h1->min->val>h2->min->val) 
			{
                h->min=h2->min;
            } 
			else 
			{
                h->min=h1->min;
            }
        }
 
        free(h1);
        h1 = NULL;
        free(h2);
        h2 = NULL;
 
        h->n=h1->n+h2->n;
    }
    return h;
}
void heapLink(FibHeap* h, FibNode *y, FibNode *x) 
{
	FibNode* yl=y->left;
	FibNode* yr=y->right;
    yl->right=y->right;
    yr->left=y->left;
 
    FibNode *child=x->son;
    if (child==nullptr) 
	{
        x->son=y;
        y->left=y;
        y->right=y;
    } 
	else 
	{
        y->right=child->right;
        child->right->left=y;
        y->left=child;
        child->right=y;
    }
    y->parent=x;
    x->degree+=1;
    y->marked=0;
}
void consolidate(FibHeap* h) 
{
    int dn=(int)(log(h->n)/log(2))+1;
    FibNode* A[dn];
    int i;
    for (i=0;i<dn;i++) 
	{
        A[i]=nullptr;
    }
 
    FibNode *w=h->min;
    FibNode *f=w->left;
 
    FibNode *x=nullptr;
    FibNode *y=nullptr;
 
    int d;
    FibNode *t=nullptr;
    while(w!=f) 
	{
        d=w->degree;
        x=w;
        w=w->right;
        while (A[d]!=nullptr)
		{
            y=A[d];
            if(x->val>y->val) 
			{
                t=x;
                x=y;
                y=t;
            }
            heapLink(h,y,x);
            A[d]=nullptr;
            d+=1;
        }
        A[d]=x;
    }

    d=w->degree;
    x=w;
    while (A[d]!=nullptr) 
	{
        y=A[d];
        if(x->val>y->val) 
		{
            t=x;
            x=y;
            y=t;
        }
        heapLink(h,y,x);
        A[d]=nullptr;
        d+=1;
    }
    A[d]=x;
 
    int min_key=MAX;
    h->min=nullptr;

    for (i=0;i<dn;++i) 
	{
        if(A[i]!=nullptr&&A[i]->val<min_key) 
		{
            h->min=A[i];
            min_key=A[i]->val;
        }
    }
}
FibNode* ExtractMin(FibHeap* h) 
{
    FibNode* z=h->min;
    if (z!=nullptr) 
	{
        FibNode* firstChid=z->son;
        if (firstChid!=nullptr) 
		{
            FibNode* sibling=firstChid->right;
            FibNode* min_right=z->right;
 			sibling->parent=nullptr;
            z->right=firstChid;
            firstChid->left=z;
            min_right->left=firstChid;
            firstChid->right=min_right;
 
            firstChid->parent=nullptr;
            min_right=firstChid;
            while (firstChid!=sibling) 
			{
				sibling->parent=nullptr;
                FibNode *sibling_right=sibling->right;
 
                z->right=sibling;
                sibling->left=z;
                sibling->right=min_right;
                min_right->left=sibling;
 
                min_right=sibling;
                sibling=sibling_right;

                sibling->parent=nullptr;
            }
        }
        FibNode* zl=z->left;
        FibNode* zr=z->right;
        zl->right=z->right;
       	zr->left=z->left;

        if (z==z->right) 
		{
            h->min=nullptr;

            if(z->son!=nullptr) 
			{
               FibNode *child=z->son;
               h->min=child;
               FibNode *sibling=child->right;
               while (child != sibling) 
			   {
                   if (h->min->val>sibling->val) 
				   {
                       h->min=sibling;
                   }
                   sibling=sibling->right;
               }
           }
        } 
		else 
		{
            h->min=z->right;
            consolidate(h);
        }
        h->n-=1;
    }
    return z;
}
void cut(FibHeap* h,FibNode *x,FibNode *y) 
{
    if(y->degree==1) 
	{
        y->son=nullptr;
    } 
	else 
	{
        x->left->right=x->right;
        x->right->left=x->left;
 
        y->son=x->right;
    }

    x->left=h->min;
    x->right=h->min->right;
    h->min->right=x;
    x->right->left=x;

    x->parent=nullptr;
    x->marked=0;
    y->degree-=1;
}
void cascadingCut(FibHeap *h,FibNode *y) 
{
    FibNode *z=y->parent;
    if (z!=nullptr) 
	{
        if(y->marked==0) 
		{
            y->marked=1;
        } 
		else 
		{
            cut(h,y,z);
            cascadingCut(h,z);
        }
    }
}
void DecreaseKey(FibHeap* h,FibNode *x,int key) 
{
    if (key>=x->val) 
	{
        printf("new key is's smaller than originl value");
        return;
    }
    x->val=key;
    FibNode *y=x->parent;
    if (y!=NULL&&x->val<y->val) 
	{
        cut(h,x,y);
        cascadingCut(h,y);
    }
 
    if (x->val<h->min->val) 
	{
        h->min=x;
    }
}
void Delete(FibHeap* h,FibNode *x) 
{
    DecreaseKey(h,x,-MAX);
    ExtractMin(h);
}

int count=0;
void GetPosition(FibHeap* h)
{
	int d=1;
	int last=0;
	FibNode* t=h->min;
	while(t!=nullptr)
	{	//cout<<"BBB"<<endl;		
		if(t->parent==nullptr)
		{
			t->y=0;
		}
		if(t->traversal==1)
		{
			if(t->parent!=nullptr) 
			{//cout<<t->x<<" "<<t->y<<" "<<t->parent->x<<" "<<t->parent->y<<" "<<t->parent->right->x<<" "<<t->parent->right->y<<endl;
				t=t->parent;
			}
			else break;
			//cout<<t->parent->x<<" "<<t->parent->y<<endl;
			FibNode* l=t;
			FibNode* r=l;
			double left_x=0;
			double right_x=0;
			
			while(l->son!=nullptr)
			{
				l=l->son;
			}
			while(r->son!=nullptr)
			{
				r=r->son;
				r=r->left;			
			}
			//cout<<l->x<<" "<<l->y<<" "<<r->x<<" "<<r->y<<endl;
			left_x=l->x;
			right_x=r->x;
			t->x=(left_x+right_x)/2;

			t->traversal=1;
			t=t->right;
			t->y=t->left->y;//if(t->parent==t)cout<<"BBB"<<endl;
		}
		if(t->son!=nullptr&&t->son->traversal==0)
		{
			t=t->son;//cout<<"BBB"<<endl;
			t->y=t->parent->y+d;
		}
		else if(t->son==nullptr&&t->traversal==0)
		{//cout<<"BBB"<<endl;	
			last+=d;
			t->x=last;
			t->traversal=1;
			t=t->right;
			t->y=t->left->y;
		}
	}
}
void Output(FibHeap* h)
{
	FibNode* t=h->min;
	while(t!=nullptr)
	{
		if(t->traversal==0)
		{
			if(t->parent!=nullptr)t=t->parent;
			else break;
			
			cout<<t->val<<"   "<<t->x<<" "<<t->y<<endl;
			t->traversal=0;
			t=t->right;
		}
		if(t->son!=nullptr&&t->son->traversal==1)
		{
			t=t->son;
		}
		else if(t->son==nullptr&&t->traversal==1)
		{
			cout<<t->val<<"   "<<t->x<<" "<<t->y<<endl;
			t->traversal=0;
			t=t->right;
		}
	}
}
int main()
{
	int m;
	FibHeap* FH=new FibHeap;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x;cin>>x;
		Insert(FH,x);
	}
	while(FH->min!=nullptr)
	{
		cout<<"AAA"<<endl;
		FibNode* fn=ExtractMin(FH);
 		cout<<fn->val<<endl;
		GetPosition(FH);
		Output(FH);
	} 
	return 0;
}

