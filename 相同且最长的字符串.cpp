#include<iostream>
#include<cmath>
using namespace std;

//声明：1.本程序只对长度为1000以内的字符串生效，可以改大； 
//2.如果没有满足条件的字符串输出FALSE，如输入：abc，则输出FALSE；

/*
思路:
cnm不写了；累死了。到时候你问吧；那里不懂问我 打电话也行反正回家了 
*/

//举个例子：这里假设输入abcabca;
//跟着我走： 
char str_in[1005];//输入的字符串 
char str_out[1005][1005];//满足条件的一堆字符串 
int str_out_head[1005];//分别对应那一堆字符串的首字母的位置序号 
int len_in=1;//输入字符串的长度 
int len_out=1;//输出字符串的长度 
int index=0;//第n个满足输出条件的字符串。index：序号； 
int flag=0;//如果长度为n的满足条件；就不必进行下去了； 
int main()
{
	cin>>str_in;
	for(;str_in[len_in]!='\0';len_in++);//现在len_in=6; 
	//计算字符串的长度；len是字符串的长度-1； 
	for(len_out=len_in-1;len_out>=1;len_out--)
	// 之所以采取减法，是因为要最长的字符串 
	{
		//len_out=5,4不符合条件；跳过；
		//这里展示len_out=3; 
		for(int head=0;head<len_in-len_out;head++)
		//a(head)bcabca 
		{
			for(int d=1;d<=len_in-head-len_out;d++)
			//这里展示d=3；a(head)bca(head+d)bca; 
			{
				int same=0;
				for(int i=0;i<=len_out;i++)
				{	
					// 位置1：abca 和 位置4：abca 一样； 
					if(str_in[head+i]==str_in[head+d+i])same++;
				}
				if(same==len_out+1)//判断是否满足条件； 
				{
					flag=1;
					for(int i=0;i<=len_out;i++)
					str_out[index][i]=str_in[head+i];//储存满足条件的字符串 
					str_out_head[index]=head;//储存首字母位置-1！！！ 
					index++;
				}
			}	
		}
		if(flag==1)break;
		//如果已经有满足条件的字符串，就不必进行下去了，因为都比它短； 
	} 
	for(int i=0;i<index;i++)
	{
		for(int d=1;d<=index-i;d++)
		//查重，看看有没有重复的 
		//比如 abcaabcaaaaabc 就可能输出考几次abc； 
		{
			if(str_out[i]==str_out[i+d])break;
		}
		cout<<str_out[i]<<","<<str_out_head[i]+1<<endl;//完事 
	}
	
	return 0;
}

