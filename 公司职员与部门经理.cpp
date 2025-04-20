#include<iostream>
#include<cmath>
using namespace std;

class employee
{
	private:
		string name;
		int salary;
	public:
		employee()
		{
			name="\0";salary=0;
		}
		employee(string s,int n)
		{
			name=s;
			salary=n;
		}
		int getsalary()
		{
			return salary;
		}
		string getname()
		{
			return name;
		}
		void remove()
		{
			name="\0";
			salary=0;
		}
};
class manager:public employee
{
	private:
		employee group[10];
		int numofemp;
	public:
		manager(string s,int n):employee(s,n)
		{
			numofemp=0;
		}
		void addemp(employee e)
		{
			group[numofemp]=e;
			numofemp++;
		}
		void removeemp(employee e)
		{
			e.remove();
			numofemp--;
		}
		void display()
		{
			cout<<getname()<<endl;
			cout<<getsalary()<<endl;
			cout<<numofemp<<endl;
			for(int i=0;i<=numofemp;i++)
			{
				cout<<group[i].getname()<<" "<<group[i].getsalary()<<endl;
			}
		}
};


int main()
{
//	employee a("a",100);
//	employee b("b",200);
//	employee c("c",300);
//	cout<<a.getname()<<" "<<a.getsalary() <<endl;
	return 0;
}

