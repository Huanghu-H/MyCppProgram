#include<iostream>
#include<cmath>
using namespace std;

//������1.������ֻ�Գ���Ϊ1000���ڵ��ַ�����Ч�����ԸĴ� 
//2.���û�������������ַ������FALSE�������룺abc�������FALSE��

/*
˼·:
cnm��д�ˣ������ˡ���ʱ�����ʰɣ����ﲻ������ ��绰Ҳ�з����ؼ��� 
*/

//�ٸ����ӣ������������abcabca;
//�������ߣ� 
char str_in[1005];//������ַ��� 
char str_out[1005][1005];//����������һ���ַ��� 
int str_out_head[1005];//�ֱ��Ӧ��һ���ַ���������ĸ��λ����� 
int len_in=1;//�����ַ����ĳ��� 
int len_out=1;//����ַ����ĳ��� 
int index=0;//��n����������������ַ�����index����ţ� 
int flag=0;//�������Ϊn�������������Ͳ��ؽ�����ȥ�ˣ� 
int main()
{
	cin>>str_in;
	for(;str_in[len_in]!='\0';len_in++);//����len_in=6; 
	//�����ַ����ĳ��ȣ�len���ַ����ĳ���-1�� 
	for(len_out=len_in-1;len_out>=1;len_out--)
	// ֮���Բ�ȡ����������ΪҪ����ַ��� 
	{
		//len_out=5,4������������������
		//����չʾlen_out=3; 
		for(int head=0;head<len_in-len_out;head++)
		//a(head)bcabca 
		{
			for(int d=1;d<=len_in-head-len_out;d++)
			//����չʾd=3��a(head)bca(head+d)bca; 
			{
				int same=0;
				for(int i=0;i<=len_out;i++)
				{	
					// λ��1��abca �� λ��4��abca һ���� 
					if(str_in[head+i]==str_in[head+d+i])same++;
				}
				if(same==len_out+1)//�ж��Ƿ����������� 
				{
					flag=1;
					for(int i=0;i<=len_out;i++)
					str_out[index][i]=str_in[head+i];//���������������ַ��� 
					str_out_head[index]=head;//��������ĸλ��-1������ 
					index++;
				}
			}	
		}
		if(flag==1)break;
		//����Ѿ��������������ַ������Ͳ��ؽ�����ȥ�ˣ���Ϊ�������̣� 
	} 
	for(int i=0;i<index;i++)
	{
		for(int d=1;d<=index-i;d++)
		//���أ�������û���ظ��� 
		//���� abcaabcaaaaabc �Ϳ������������abc�� 
		{
			if(str_out[i]==str_out[i+d])break;
		}
		cout<<str_out[i]<<","<<str_out_head[i]+1<<endl;//���� 
	}
	
	return 0;
}

