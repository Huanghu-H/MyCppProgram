#include<bits/stdc++.h>
using namespace std;

class List
{
	private:
	int r[105];
	int n;
	public:
		void Display()
		{
			for(int i=1;i<=n;i++)
      		cout<<r[i]<<" ";
			cout<<"\n";
		}
	    List(){n=0;} 
	void InsertR(int k)  
		{r[++n]=k;}     
	void QuickSort();   
};


void List::QuickSort()
{
    stack<int> S;
 	int first = 1,end = n;
	S.push(1);
 	S.push(n);


 	while(!S.empty())
    {
        int j = S.top();
        S.pop();
        int i = S.top();
        S.pop();
        end = j;
        first = i;
        while(i<j)
        {
	        while(i<j&&r[i]<=r[j])j--;
	        if(i<j)
			{
		    	int temp=r[i];
		        r[i]=r[j];
		        r[j]=temp;
		        i++;
	        }
	        while(i<j&&r[i]<r[j])i++;
	        if(i<j)
	        {
	            int temp=r[i];
	            r[i]=r[j];
	            r[j]=temp;
	            j--;
	        }
        }
        if(first<i-1)
        {
           S.push(first);
           S.push(i-1);
        }
        if(i+1<end)
        {
           S.push(i+1);
           S.push(end);
        }
    }
}
int a[10005];
int main()
{
	List L;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];L.InsertR(a[i]);
	}
	L.QuickSort();
	L.Display();
	return 0;
}

