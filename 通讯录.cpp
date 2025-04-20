#include<iostream>
using namespace std;
struct datatype
{
	int ID;//���
	char name[10];//����
	char ch[5];//�Ա�
	char phone[13];//�绰
	char addr[31];//��ַ
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
	else throw"����λ�ô���";
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
	cout << "������ͨѶ¼�е�������ϵ����Ϣ��" << endl;
	Node<T>* p = front->next;
	int jishu = 1;
	while (p && p->data.ID != 0)
	{
		cout << "��" << jishu << "λ��ϵ�ˣ�" << "ID�ţ�" << p->data.ID << " " << "������" << p->data.name << " " << "�Ա�" << p->data.ch << " " << "�绰���룺" << p->data.phone << " " << "��ַ��" << p->data.addr << endl;
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

		cout << "��������ϵ��" << i + 1 << "����:" << endl;
		cin >> f[i].name;
		cout << "��������ϵ��" << i + 1 << "�Ա�" << endl;
		cin >> f[i].ch;
		cout << "��������ϵ��" << i + 1 << "�绰��" << endl;
		cin >> f[i].phone;
		cout << "��������ϵ��" << i + 1 << "��ַ:" << endl;
		cin >> f[i].addr;

		i++;
	}

}
void jianli2(datatype* z, int id)
{
	z->ID = id;
	cout << "��������ϵ������:";
	cin >> z->name;
	cout << "��������ϵ���Ա�";
	cin >> z->ch;
	cout << "��������ϵ�˵绰��";
	cin >> z->phone;
	cout << "��������ϵ�˵�ַ��";
	cin >> z->addr;
}
void jl(datatype* f)
{
	int renshu;
	cout << "********ͨѶ¼����ϵͳ********" << endl;
	cout << "����ͨѶ¼��" << endl;
	cout << "��������Ҫ��ʼ��ӵ���ϵ����������ʼ���(10������)" << endl;
	cin >> renshu;
	jianli(f, renshu);
}
void zhuomian(lianbiao<datatype>a)
{
	int shuru;
	cout << "********ͨѶ¼����ϵͳ********" << endl;
	cout << "��������Ҫִ�еĲ�����       *" << endl;
	cout << "1.�½���ϵ��                 *" << endl;
	cout << "2.ɾ����ϵ��                 *" << endl;
	cout << "3.�޸���ϵ����Ϣ             *" << endl;
	cout << "4.��ѯ��ϵ��                 *" << endl;
	cout << "5.�˳�ͨѶ¼                 *" << endl;
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
		cout << "���º�ͨѶ¼��" << endl;
		a.bianli();
		zhuomian(a);
	}

	if (shuru == 2)
	{
		a.bianli();
		int shanchuzhe;
		cout << "������Ҫɾ������ϵ��" << endl;
		cin >> shanchuzhe;
		a.Delete(shanchuzhe);
		cout << "ɾ����ͨѶ¼��" << endl;
		a.bianli();
		zhuomian(a);
	}
	if (shuru == 3)
	{
		int xiugaizhe;
		a.bianli();
		cout << "���������޸ĵ���ϵ�ˣ�λ������" << endl;
		cin >> xiugaizhe;
		int p = a.get(xiugaizhe)->data.ID;
		a.Delete(xiugaizhe);
		datatype gaihou = { 0 };
		datatype* z = &gaihou;
		jianli2(z, p);
		a.insert(xiugaizhe, *z);
		cout << "�޸ĺ�ǰͨѶ¼��" << endl;
		a.bianli();
		zhuomian(a);
	}
	if (shuru == 4)
	{
		int chaxunzhe;
		cout << "���������ѯ����ϵ�ˣ�λ������" << endl;
		cin >> chaxunzhe;
		datatype p = a.get(chaxunzhe)->data;
		cout << "����������ѯ����ϵ����Ϣ��" << endl;
		cout << "ID�ţ�" << p.ID << " " << "������" << p.name << " " << "�Ա�" << p.ch << " " << "�绰���룺" << p.phone << " " << "��ַ��" << p.addr << endl;
		zhuomian(a);

	}
	if (shuru == 5)
	{
		cout << "�����˳�ͨѶ¼" << endl;

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

