#include<iostream>
#include<cmath>
using namespace std;

class TreeNode
{
	public:
		int value;
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;
		int Height; 
		TreeNode()
		{
			value=0;
			left=nullptr;
			right=nullptr;
			parent=nullptr;
			Height=-1;
		}
		TreeNode(int x)
		{
			value=x;
			left=nullptr;
			right=nullptr;
			parent=nullptr;
			Height=0;
		}
}; 

TreeNode* P=nullptr;

TreeNode* MakeEmpty(TreeNode* T)
{
	if(T!=nullptr)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return nullptr;
}
TreeNode* Find(int x,TreeNode* T)
{
	if(T==nullptr)return nullptr;
	else if(x<T->value)return Find(x,T->left);
	else if(x>T->value)return Find(x,T->right);
	else return T; 
}
TreeNode* FindMin(TreeNode* T)
{
	if(T==nullptr)return nullptr;
	else if(T->left==nullptr)return T;
	else return FindMin(T->left);
}
TreeNode* FindMax(TreeNode* T)
{
	if(T==nullptr)return nullptr;
	else if(T->right==nullptr)return T;
	else return FindMax(T->right);
}
int Height(TreeNode* T)
{
	if(T==nullptr)return -1;
	else return T->Height;
}
TreeNode* SingleRWL(TreeNode* K2)
{
	TreeNode* K1=K2->left; K1->parent=K2->parent;
	if(K2->parent!=nullptr&&K2->parent->left==K2)K2->parent->left=K1;
	else if(K2->parent!=nullptr)K2->parent->right=K1;
	TreeNode* Y=K1->right;
	
	K2->left=Y;	if(Y!=nullptr)Y->parent=K2; 	
	K1->right=K2; K2->parent=K1;

	K2->Height=max(Height(K2->left),Height(K2->right))+1;
	K1->Height=max(Height(K1->left),K2->Height)+1;
	return K1;
}
TreeNode* SingleRWR(TreeNode* K2)
{
	TreeNode* K1=K2->right; 	K1->parent=K2->parent;
	if(K2->parent!=nullptr&&K2->parent->left==K2)K2->parent->left=K1;
	else if(K2->parent!=nullptr)K2->parent->right=K1;
	TreeNode* Y=K1->left;
	
	K2->right=Y; if(Y!=nullptr)Y->parent=K2;
	K1->left=K2; K2->parent=K1;	
	
	K2->Height=max(Height(K2->left),Height(K2->right))+1;
	K1->Height=max(K2->Height,Height(K1->right))+1;
	return K1;
}
TreeNode* DoubleRWL(TreeNode* K3)
{
	K3->left=SingleRWR(K3->left);
	return SingleRWL(K3);
}
TreeNode* DoubleRWR(TreeNode* K3)
{
	K3->right=SingleRWL(K3->right);
	return SingleRWR(K3);
}
TreeNode* Insert(int x,TreeNode* T)
{
	if(T==nullptr)
	{
		T=new TreeNode(x);
		T->parent=P;
	}
	else if(x<T->value) 
	{
		P=T;
		T->left=Insert(x,T->left);
		if(Height(T->left)-Height(T->right)==2)
		{
			if(x<T->left->value)T=SingleRWL(T);
			else T=DoubleRWL(T);
		}
	}
	else if(x>T->value) 
	{
		P=T;
		T->right=Insert(x,T->right);
		if(Height(T->right)-Height(T->left)==2)
		{
			if(x>T->right->value) T=SingleRWR(T);
			else T=DoubleRWR(T);
		}
	}
	T->Height=max(Height(T->left),Height(T->right))+1;
	return T;
}
TreeNode* Delete(int x,TreeNode* T)
{
	TreeNode* Current=Find(x,T);
	TreeNode* Parent_of_Current=Current->parent;
//	if(Current->value==20802)
//	{
//		//cout<<(bool)(Find(20802,T)->parent==Find(21789,T))<<endl;
//		//TreeNode* TN2=Find(31325,T);//cout<<TN2->parent->right->value<<endl;
//		//TreeNode* TN=Find(21789,T);//cout<<TN->right->value<<endl;
//		//TreeNode* TN3=Find(20802,T);//cout<<TN3->parent->value<<endl;
//		//cout<<Current->parent->right->value<<endl;
//	}
	if(Current->left==nullptr&&Current->right==nullptr)
	{		
		if(Parent_of_Current==nullptr)return nullptr;
		if(Parent_of_Current->left==Current)
		{
			Parent_of_Current->left=nullptr;
			Parent_of_Current->Height=max(Height(Parent_of_Current->left),Height(Parent_of_Current->right))+1;
		}
		else
		{
			Parent_of_Current->right=nullptr;
			Parent_of_Current->Height=max(Height(Parent_of_Current->left),Height(Parent_of_Current->right))+1;
		}
		Current=Parent_of_Current;
	}
	else if(Current->left==nullptr&&Current->right!=nullptr)
	{ 
		TreeNode* rightson=Current->right;
		Current->value=rightson->value;
		Current->Height=0;	
		Current->right=nullptr;
		//Parent_of_Current->Height=max(Height(Parent_of_Current->left),Height(Parent_of_Current->right))+1;
	}
//	else if(Current->left!=nullptr&&Current->right==nullptr)
//	{
//		TreeNode* leftson=Current->left;
//		Current->value=leftson->value;
//		Current->Height=0;
//		Current->left=nullptr;
//		//Parent_of_Current->Height=max(Height(Parent_of_Current->left),Height(Parent_of_Current->right))+1;
//		delete leftson;leftson=nullptr;
//	}
	else 
	{	
		TreeNode* Previous=FindMax(Current->left);
		TreeNode* Parent_of_Previous=Previous->parent;
		Current->value=Previous->value;
		if(Parent_of_Previous->left==Previous)
		{
			Parent_of_Previous->left=Previous->left;
			if(Previous->left!=nullptr)Previous->left->parent=Parent_of_Previous;
			Parent_of_Previous->Height=max(Height(Parent_of_Previous->left),Height(Parent_of_Previous->right))+1;
		}
		else
		{
			Parent_of_Previous->right=Previous->left;
			Parent_of_Previous->Height=max(Height(Parent_of_Previous->left),Height(Parent_of_Previous->right))+1;
		}
		Previous=nullptr;
		Current=Parent_of_Previous;
	}
	Parent_of_Current=Current->parent;
	if(Height(Current->left)-Height(Current->right)==2)
	{
		if(Height(Current->left->left)-Height(Current->left->right)>=0)Current=SingleRWL(Current);
		else Current=DoubleRWL(Current);
	}
	if(Height(Current->right)-Height(Current->left)==2)
	{
		if(Height(Current->right->right)-Height(Current->right->left)>=0)Current=SingleRWR(Current);
		else Current=DoubleRWR(Current);
	}
	while(Parent_of_Current!=nullptr)
	{ 
		Parent_of_Current->Height=max(Height(Parent_of_Current->left),Height(Parent_of_Current->right))+1;
		if(Height(Parent_of_Current->left)-Height(Parent_of_Current->right)==2)
		{
			if(Height(Parent_of_Current->left->left)-Height(Parent_of_Current->left->right)>=0)Parent_of_Current=SingleRWL(Parent_of_Current);
			else Parent_of_Current=DoubleRWL(Parent_of_Current);
		}
		else if((Height(Parent_of_Current->left)-Height(Parent_of_Current->right)==-2))
		{
			if(Height(Parent_of_Current->right->right)-Height(Parent_of_Current->right->left)>=0) Parent_of_Current=SingleRWR(Parent_of_Current);
			else Parent_of_Current=DoubleRWR(Parent_of_Current);
		}
		Current=Parent_of_Current;
		Parent_of_Current=Current->parent;
	}
	
	return Current;
}
void Output(TreeNode* T)
{
	if(T==nullptr)return;
	if(T->parent!=nullptr)
	{
		if(T->parent->left==T&&T->value>T->parent->value)return;
		else if(T->parent->right==T&&T->value<T->parent->value)return;
	} 
	cout<<"(";
	if(T->left!=nullptr)Output(T->left);
	if(T!=nullptr)cout<<T->value<<","<<Height(T->right)-Height(T->left);
	if(T->right!=nullptr)Output(T->right);
	cout<<")";	
}
int TreeHeight(TreeNode* T)
{
	if(T==nullptr)return -1;
	else if(T->left==nullptr&&T->right==nullptr)return 0;
	else return max(TreeHeight(T->left),TreeHeight(T->right))+1; 
}
void IsAvlTree(TreeNode* T)
{
	if(T->left!=nullptr)IsAvlTree(T->left);
	if(T!=nullptr&&abs(-TreeHeight(T->left)+TreeHeight(T->right))==2)return;
	if(T->right!=nullptr)IsAvlTree(T->right);
}
int main()
{
	TreeNode* TreeRoot=nullptr;
	int N;cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int x,y;cin>>x>>y;
//		if(i>13){
//			cout<<(bool)(Find(20802,TreeRoot)->parent==Find(21789,TreeRoot))<<endl;
//		}
		P=nullptr;
		if(x==1&&!Find(y,TreeRoot))TreeRoot=Insert(y,TreeRoot);
		else if(x==2&&Find(y,TreeRoot))TreeRoot=Delete(y,TreeRoot);
		Output(TreeRoot);
		//IsAvlTree(TreeRoot);
		cout<<endl;
		
	}	
//	if(TN->right!=nullptr)cout<<"B"<<endl;
//	if(TN->right==nullptr)cout<<"A"<<endl;
	return 0;
}

/*
9 1 6 1 3 1 8 1 1 1 4 1 7 1 2 1 5 2 8
*/
