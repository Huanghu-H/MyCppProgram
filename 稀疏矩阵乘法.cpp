#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 1005

struct node
{
	int data;
	int col;
	int row;
	node *next_row;
	node *next_col;
};

long long s[100000][3];
int k=0;
/*
8 8 10
10
2 1 9
3 8 5
4 5 1
4 6 9
6 1 10
6 4 2
6 5 3
7 8 1
8 1 8
8 5 2
10
1 9 9
2 8 9
3 4 2
3 7 4
5 3 8
5 10 6
6 2 2
6 6 10
6 8 6
7 8 9

12
2 9 81
4 2 18
4 3 8
4 6 90
4 8 54
4 10 6
6 3 24
6 9 90
6 10 18
8 3 16
8 9 72
8 10 12

*/
//2 3 2 2 1 2 2 2 1 1
class matrix
{	
	private:
		struct node *columns[MAXN];
		struct node *ctail[MAXN];
		struct node *rows[MAXN];
		struct node *rtail[MAXN];
		int colN,rowN;
	public:
		matrix()
		{
			
		}
		matrix(int p,int q)
		{
			for(int i=0;i<MAXN;i++)
			{
				columns[i]=new node;
				ctail[i]=new node;
				rows[i]=new node;
				rtail[i]=new node;
				 
				columns[i]->col=i;
				columns[i]->row=0;
				ctail[i]=columns[i];
				ctail[i]->next_col=nullptr;
				rows[i]->row=i;
				rows[i]->col=0;
				rtail[i]=rows[i];
				rtail[i]->next_row=nullptr;
			}
			rowN=p;colN=q;
			int m;cin>>m;
			for(int i=0;i<m;i++)
			{
				int r,c,value;
				cin>>r>>c>>value;
				node *p=new node;
				p->col=c;
				p->row=r;
				p->data=value;
				p->next_col=nullptr;
				p->next_row=nullptr;
				rtail[r]->next_col=p;
				ctail[c]->next_row=p;				
				rtail[r]=p;
				ctail[c]=p;
			}
		}
		void multiply(matrix *m1,matrix *m2)
		{
			for(int i=1;i<=m1->rowN;i++)
			{
				for(int j=1;j<=m2->colN;j++)
				{
					s[k][0]=0;
					node *p1=new node;
					p1=m1->rows[i]->next_col;
					node *p2=new node;
					p2=m2->columns[j]->next_row;
					while(1)
					{
						if(p1==nullptr||p2==nullptr)break;
						if(p1->col<p2->row)
						{
							p1=p1->next_col;
						}
						else if(p1->col>p2->row)
						{
							p2=p2->next_row;
						}
						else if(p1->col=p2->row)
						{
							s[k][1]=i;
							s[k][2]=j;
							s[k][0]+=p1->data*p2->data;
							p1=p1->next_col;
							p2=p2->next_row;
						}
						if(p1==nullptr||p2==nullptr)
						{
							if(s[k][0]==0)break;
							else
							{
								//cout<<s[k][1]<<" "<<s[k][2]<<" "<<s[k][0]<<endl;
								k++;break;
							}
						}
					}
				}
			}
	 	}
		void output(int p,int r)
		{
			for(int i=0;i<MAXN;i++)
			{
				columns[i]=new node;
				ctail[i]=new node;
				rows[i]=new node;
				rtail[i]=new node;
				 
				columns[i]->col=i;
				columns[i]->row=0;
				ctail[i]=columns[i];
				ctail[i]->next_col=nullptr;
				rows[i]->row=i;
				rows[i]->col=0;
				rtail[i]=rows[i];
				rtail[i]->next_row=nullptr;
			}
			rowN=p;colN=r;
			for(int i=0;i<k;i++)
			{
				node *p=new node;
				p->col=s[i][2];
				p->row=s[i][1];
				p->data=s[i][0];
				p->next_col=nullptr;
				p->next_row=nullptr;
				rtail[s[i][1]]->next_col=p;
				ctail[s[i][2]]->next_row=p;				
				rtail[s[i][1]]=p;
				ctail[s[i][2]]=p;
			}
			
			for(int i=1;i<=rowN;i++)
			{
				int j=1;
				node *p=new node;
				p=rows[i]->next_col;
				while(p!=nullptr)
				{
					if(j<p->col)
					{
						//cout<<0<<" ";
						j++;
					}
					else if(j=p->col) 
					{
						//cout<<p->data<<" ";
						j++;
						p=p->next_col;
					}
				}
				for(;j<=colN;j++);//cout<<0<<" ";
				//cout<<endl;
			}
		}
}; 

//2 3 2 2 1 2 2 2 1 1 3 1 1 1 1 2 3 2 1 2
int main()
{
	int p,q,r;
	cin>>p>>q>>r;
	matrix a(p,q);
	matrix b(q,r);
	matrix c;
	c.multiply(&a,&b);
	cout<<k<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<s[i][1]<<" "<<s[i][2]<<" "<<s[i][0]<<endl;
	}
	//c.output(p,r); 
	return 0;
}

