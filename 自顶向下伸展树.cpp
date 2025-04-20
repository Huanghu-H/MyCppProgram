#include<iostream>
#include<cmath>
using namespace std;
//Splay Tree ÉìÕ¹Ê÷ 
//typedef class SpalyNode *SpalyTree;

class SplayNode 
{
	public:
		int value;
		SplayNode* left;
		SplayNode* right;
		SplayNode()
		{
			value=0;
			left=nullptr;
			right=nullptr;
		}
	 
};

static SplayNode* NullNode=nullptr;

SplayNode* Initialize()
{
	if(NullNode==nullptr)	
	{
		NullNode=new SplayNode;
		NullNode->left=NullNode->right=NullNode;
	}
	return NullNode;
}
SplayNode* SingleRWL(SplayNode* K2)
{
	SplayNode* K1=K2->left;
	K2->left=K1->right;
	K1->right=K2;
	
	return K1;
}
SplayNode* SingleRWR(SplayNode* K2)
{
	SplayNode* K1=K2->right;
	K2->right=K1->left;
	K1->left=K2;
	
	return K1;
}
SplayNode* Splay(int x,SplayNode* T)
{
	static SplayNode Header;
	SplayNode* LeftTreeMax;
	SplayNode* RightTreeMin;
	
	Header.left=NullNode;
	Header.right=NullNode;
	LeftTreeMax=&Header;
	RightTreeMin=&Header;
	NullNode->value=x;
	
	while(x!=T->value)
	{
		if(x<T->value)
		{
			if(x<T->left->value)	T=SingleRWL(T);
			if(T->left==NullNode)	break;
			
			RightTreeMin->left=T;
			RightTreeMin=T;
			T=T->left;
		}
		else if(x>T->value)
		{
			if(x>T->right->value)	T=SingleRWR(T);
			if(T->left==NullNode) break;
			
			LeftTreeMax->right=T;
			LeftTreeMax=T;
			T=T->right; 
		}
	}
	//Reassemble ÖØ×é
	LeftTreeMax->right=T->left;
	RightTreeMin->left=T->right;
	T->left=Header.right;
	T->right=Header.left;
	
	return T; 
}
SplayNode* Insert(int x,SplayNode* T)
{
	static SplayNode* NewNode=nullptr;
	
	if(NewNode==nullptr)	NewNode=new SplayNode;
	NewNode->value=x;
	
	if(T==NullNode)
	{
		NewNode->left=NullNode;
		NewNode->right=NullNode;
		T=NewNode;
	}
	else
	{
		T=Splay(x,T);
		if(x<T->value)
		{
			NewNode->left=T->left;
			NewNode->right=T;
			T->left=NullNode;
			T=NewNode;
		}
		else if(x>T->value)
		{
			NewNode->right=T->right;
			NewNode->left=T;
			T->right=NullNode;
			T=NewNode;
		}
		else return T;
	}
	
	NewNode=nullptr;
	return T;
}
SplayNode* Delete(int x,SplayNode* T)
{
	SplayNode* NewTree;
	
	if(T!=NullNode)
	{
		T=Splay(x,T);
		if(x==T->value)
		{
			if(T->left==NullNode)NewTree=T->right;
			else
			{
				NewTree=T->left;
				NewTree=Splay(x,NewTree);
				NewTree->right=T->right;
			}
			delete T;
			T=NewTree;
		}
	}
	return T;
}
void Output(SplayNode* T)
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
	SplayNode* STNode=Initialize();
	
	STNode=Insert(5,STNode);
	STNode=Insert(3,STNode);
	STNode=Insert(2,STNode);
	STNode=Insert(7,STNode);
	STNode=Insert(6,STNode);
//	STNode=Insert(9,STNode);
//	STNode=Insert(8,STNode);
//	STNode=Insert(4,STNode);
	
	Output(STNode);
	return 0;
}

