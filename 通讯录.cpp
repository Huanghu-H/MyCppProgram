#include<iostream>
using namespace std;
struct datatype
{
	int ID;//编号
	char name[10];//姓名
	char ch[5];//性别
	char phone[13];//电话
	char addr[31];//地址
};
template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};
template<class T>
class lianbiao
{
public:
	lianbiao() { front = new Node<T>; front->next = NULL; }
	lianbiao(T a[], int n);
	~lianbiao();
	Node<T>* get(int i);
	int getlength();
	void bianli();
	/*int locate(T x);*/
	void insert(int i, T x);
	T Delete(int i);
private:
	Node<T>* front;
};
template<class T>
lianbiao<T>::lianbiao(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>* s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
}
template<class T>
lianbiao<T>::~lianbiao()
{
	Node<T>* p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}
template<class T>
int lianbiao<T>::getlength()
{
	Node<T>* p = front->next;
	int length = 0;
	while (p && p->data.ID != 0)
	{
		p = p->next;
		length = length + 1;
	}
	return length;
}
template<class T>
Node<T>* lianbiao<T>::get(int i)
{
	Node<T>* p = front->next;
	int j = 1;
	while (p && j != i)
	{
		p = p->next;
		j++;
	}
	return p;
}
template<class T>
void lianbiao<T>::insert(int i, T x)
{
	Node<T>* p = front;
	if (i != 1) 
		p = get(i - 1);
	if (p) {
		Node<T>* s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else throw"插入位置错误";
}
template<class T>
T lianbiao<T>::Delete(int i)
{
	Node<T>* p = front;
	if (i != 1)p = get(i - 1);
	Node<T>* q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}
template<class T>
void lianbiao<T>::bianli()
{
	cout << "如下是通讯录中的所有联系人信息：" << endl;
	Node<T>* p = front->next;
	int jishu = 1;
	while (p && p->data.ID != 0)
	{
		cout << "第" << jishu << "位联系人：" << "ID号：" << p->data.ID << " " << "姓名：" << p->data.name << " " << "性别：" << p->data.ch << " " << "电话号码：" << p->data.phone << " " << "地址：" << p->data.addr << endl;
		p = p->next;
		jishu++;
	}
}
void jianli(datatype* f, int shumu)
{
	int i = 0;
	while (i < shumu)
	{

		f[i].ID = i + 1;

		cout << "请输入联系人" << i + 1 << "姓名:" << endl;
		cin >> f[i].name;
		cout << "请输入联系人" << i + 1 << "性别：" << endl;
		cin >> f[i].ch;
		cout << "请输入联系人" << i + 1 << "电话：" << endl;
		cin >> f[i].phone;
		cout << "请输入联系人" << i + 1 << "地址:" << endl;
		cin >> f[i].addr;

		i++;
	}

}
void jianli2(datatype* z, int id)
{
	z->ID = id;
	cout << "请输入联系人姓名:";
	cin >> z->name;
	cout << "请输入联系人性别：";
	cin >> z->ch;
	cout << "请输入联系人电话：";
	cin >> z->phone;
	cout << "请输入联系人地址：";
	cin >> z->addr;
}
void jl(datatype* f)
{
	int renshu;
	cout << "********通讯录管理系统********" << endl;
	cout << "建立通讯录：" << endl;
	cout << "请输入您要初始添加的联系人人数并开始添加(10人以内)" << endl;
	cin >> renshu;
	jianli(f, renshu);
}
void zhuomian(lianbiao<datatype>a)
{
	int shuru;
	cout << "********通讯录管理系统********" << endl;
	cout << "请输入您要执行的操作：       *" << endl;
	cout << "1.新建联系人                 *" << endl;
	cout << "2.删除联系人                 *" << endl;
	cout << "3.修改联系人信息             *" << endl;
	cout << "4.查询联系人                 *" << endl;
	cout << "5.退出通讯录                 *" << endl;
	cout << "******************************" << endl;
	cin >> shuru;
	if (shuru == 1)
	{
		int id = a.get(a.getlength())->data.ID;
		int changdu = a.getlength() + 1;
		datatype x = { 0 };
		datatype* z = &x;
		jianli2(z, id + 1);
		a.insert(changdu, x);
		cout << "更新后通讯录：" << endl;
		a.bianli();
		zhuomian(a);
	}

	if (shuru == 2)
	{
		a.bianli();
		int shanchuzhe;
		cout << "请输入要删除的联系人" << endl;
		cin >> shanchuzhe;
		a.Delete(shanchuzhe);
		cout << "删除后通讯录：" << endl;
		a.bianli();
		zhuomian(a);
	}
	if (shuru == 3)
	{
		int xiugaizhe;
		a.bianli();
		cout << "输入您想修改的联系人（位数）：" << endl;
		cin >> xiugaizhe;
		int p = a.get(xiugaizhe)->data.ID;
		a.Delete(xiugaizhe);
		datatype gaihou = { 0 };
		datatype* z = &gaihou;
		jianli2(z, p);
		a.insert(xiugaizhe, *z);
		cout << "修改后当前通讯录：" << endl;
		a.bianli();
		zhuomian(a);
	}
	if (shuru == 4)
	{
		int chaxunzhe;
		cout << "输入您想查询的联系人（位数）：" << endl;
		cin >> chaxunzhe;
		datatype p = a.get(chaxunzhe)->data;
		cout << "如下是您查询的联系人信息：" << endl;
		cout << "ID号：" << p.ID << " " << "姓名：" << p.name << " " << "性别：" << p.ch << " " << "电话号码：" << p.phone << " " << "地址：" << p.addr << endl;
		zhuomian(a);

	}
	if (shuru == 5)
	{
		cout << "您已退出通讯录" << endl;

	}
}

int main()
{
	datatype tongxunlu[10] = { 0 };
	datatype* f = tongxunlu;
	jl(f);
	lianbiao<datatype>txllianbiao(f, 10);
	zhuomian(txllianbiao);
}

