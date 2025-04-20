#include<iostream>
#include<cmath>
using namespace std;

typedef enum Colortype{Red,Black} Colortype;
class RBTree
{
	public:
		int value;
		RBTree* left;
		RBTree* right;
		Colortype color;
	 
};

RBTree* NullNode=nullptr;
RBTree* Initialize(int x)
{
	RBTree* T;
	
	if(NullNode==nullptr)
	{
		NullNode=new RBTree;
		NullNode->left=NullNode->right=NullNode;
		NullNode->color=Black;
		NullNode->value=0;
	}
	//创建头节点 
	T=new RBTree;
	T->value=x; 
	T->left=T->right=NullNode;
	T->color=Black;
	
	return T; 
}
RBTree* SingleRWL(RBTree* K2)
{
	RBTree* K1=K2->left;
	K2->left=K1->right;
	K1->right=K2;
	
	return K1;
}
RBTree* SingleRWR(RBTree* K2)
{
	RBTree* K1=K2->right;
	K2->right=K1->left;
	K1->left=K2;
	
	return K1;
}
RBTree* Rotate(int x,RBTree* Parent)
{
	if(x<Parent->value)
	{
		return Parent->left=x<Parent->left->value?
			SingleRWL(Parent->left):
			SingleRWR(Parent->left);
	}
	else if(x>Parent->value)
	{
		return Parent->right=x<Parent->right->value?
			SingleRWL(Parent->right):
			SingleRWR(Parent->right);
	}
}

static RBTree* X,*P,*GP,*GGP;
RBTree* Reorient(int x,RBTree* T)
{
	X->color=Red;
	X->left->color=Black;
	X->right->color=Black; 
	
	if(P->color==Red)
	{
		GP->color=Red;
		if((x<GP->value)!=(x<P->value))
		{
			P=Rotate(x,GGP);
			X->color=Black;
		}
	} 
}
RBTree* Insert(int x,RBTree* T)
{
	X=P=GP=T;
	NullNode->value=x;
	while(X->value!=x)
	{
		GGP=GP;GP=P;P=X;
		if(x<X->value)X=X->left;
		else X=X->right;
		if(X->left->color==Red&&X->right->color==Red) Reorient(x,T);
	} 
	
	if(X!=NullNode)return NullNode;//复制 
	
	X=new RBTree;
	X->value=x;
	X->left=X->right=NullNode;
	
	if(x<P->value)P->left=X;
	else P->right=X;
	Reorient(x,T);
	return T;
}
void Output(RBTree* T)
{
	if(T!=NullNode)
	{
		Output(T->left);
		cout<<T->value<<" ";
		Output(T->right); 
	}
}
int main()
{
	RBTree* TR;
	TR=Initialize(5);
	TR=Insert(3,TR);
	TR=Insert(2,TR);
	TR=Insert(7,TR);
	TR=Insert(6,TR);
	TR=Insert(9,TR);
	TR=Insert(8,TR);
	TR=Insert(4,TR);
	TR=Insert(1,TR);
	
	Output(TR);
	return 0;
}

